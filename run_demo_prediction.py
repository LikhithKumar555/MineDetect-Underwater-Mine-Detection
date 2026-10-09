"""
Offline demo: run the actual shipped SVM (ml/model_svm.pkl) against the
synthetic sample data (sample_data/demo_sensor_readings_SYNTHETIC.csv)
instead of a live serial connection.

This exists so the project can be demonstrated (e.g. in an interview)
without the Arduino / submarine hardware attached. It is NOT part of the
original deployed pipeline — the real one is gui_and_logging/realtime_prediction_gui.py,
which reads live data from a serial port.

Usage:
    python run_demo_prediction.py
"""
import csv
import joblib

MODEL_PATH = "ml/model_svm.pkl"
SAMPLE_PATH = "sample_data/demo_sensor_readings_SYNTHETIC.csv"

def main():
    model = joblib.load(MODEL_PATH)
    correct = 0
    total = 0
    with open(SAMPLE_PATH, newline="") as f:
        reader = csv.reader(f)
        header = next(reader)
        print(f"Loaded model. Classes: {list(model.classes_)}\n")
        print(f"{'True label':<10} {'Prediction':<10} {'Match'}")
        print("-" * 32)
        for row in reader:
            *features, true_label = row
            features = [float(v) for v in features]
            pred = model.predict([features])[0]
            match = "yes" if pred == true_label else "no"
            if pred == true_label:
                correct += 1
            total += 1
            print(f"{true_label:<10} {pred:<10} {match}")
    print(f"\n{correct}/{total} correct on this synthetic sample "
          f"({100*correct/total:.1f}%).")
    print("Note: this is a quick sanity check on synthetic data, not a")
    print("real accuracy figure. See the root README for the honest,")
    print("held-out accuracy measured on real recorded data.")

if __name__ == "__main__":
    main()

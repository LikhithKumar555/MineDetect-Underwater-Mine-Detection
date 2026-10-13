# MineDetect-Underwater-Mine-Detection

# Underwater Mine Detection from Sensor Data (ML + IoT)

B.E. final-year project, Dept. of CSE (AI & ML), Vidyavardhaka College of
Engineering (VVCE), Mysuru — VTU Belagavi, 2023-24.

**Team:** Nagaprapthi P S, Likhith Kumar S, Suraj S M, Nikhil Raj G
**Guide:** Prof. Sheeban E Tamanna · **HOD:** Dr. Vinutha D C

Published in IJSREM, Vol 8 Issue 5, May 2024 (ISSN 2582-3930), and the
subject of an Indian patent application, No. 202441035054 A.

## Overview

A prototype submarine carries a multi-sensor rig — PIR, dual ultrasonic,
five microphones, and a turbidity sensor — read by an Arduino Uno. Readings
stream over serial, either over USB or wirelessly via an HC-05 Bluetooth
module, to a laptop running a trained SVM classifier that labels each
reading as **Mine / Rock / Negative** in real time. A Tkinter dashboard
displays the live prediction alongside 9 real-time sensor plots and logs
every reading to CSV.

The motors — brushless ESCs, servos, and a small pump — can also be
controlled remotely from a phone over WiFi, using an ESP8266 module and the
RemoteXY app, independent of the sensing pipeline.

## How it works

1. **Sensing:** the combined Arduino firmware reads all 9 channels and
   streams them as a single comma-separated line over serial.
2. **Data collection:** a Python logger records labeled readings from bench
   tests, building the training dataset.
3. **Model:** a scikit-learn SVM is trained on the collected dataset to
   classify each reading.
4. **Live prediction:** a Tkinter GUI reads the live serial stream,
   classifies each reading with the trained model, and displays the result
   alongside real-time sensor plots.
5. **Remote control:** a separate ESP8266 + RemoteXY setup lets the
   motors, servos, and pump be driven from a phone over WiFi.

## Repository layout

```
docs/                    Project papers, full report, and patent documentation
firmware/                Arduino sketches for sensing, motor control, and WiFi remote control
ml/                       Model training script and the trained SVM model
gui_and_logging/          The live prediction GUI and the serial data loggers
data/                     Datasets used to train and demonstrate the model
sample_data/              A small synthetic dataset for trying the pipeline without hardware
archive/                  Earlier experiments and prototype iterations
run_demo_prediction.py    Runs the trained model against sample data
```

## Documentation

The `docs/` folder contains the project's primary write-ups:

- **`Final_Project_Report_VVCE_2023-24.pdf`** — the full final-year project
  report, including the system design, sensor and firmware details, and
  submarine photos.
- **`IJSREM_Published_Paper_May2024.pdf`** — the published journal paper
  (IJSREM, Vol 8 Issue 5, May 2024).
- **`Conference_Manuscript_Draft.pdf`** — the conference-format manuscript.
- **`Patent_Application_202441035054A.jpg`** — the published Indian patent
  application (No. 202441035054 A).

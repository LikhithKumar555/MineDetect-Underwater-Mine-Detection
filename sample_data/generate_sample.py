import csv, random
random.seed(42)

# SYNTHETIC demo data — NOT real sensor recordings.
# Ranges are loosely modeled on what full.ino's scaling logic can produce
# (baseline ~511 when nothing triggers an offset, large jumps when a
# threshold is crossed), purely so this repo is runnable end-to-end
# without real hardware attached. See sample_data/README.md.

header = ["pir","ultrasonic1","ultrasonic2","mic1","mic2","mic3","mic4","mic5","turbidity_or_rand9","label"]
rows = []

def jitter(base, spread):
    return round(base + random.uniform(-spread, spread), 2)

for _ in range(12):  # Mine-like: metal box -> several channels saturate high
    row = [jitter(10700, 150) if random.random() < 0.6 else jitter(511, 20) for _ in range(8)]
    row.append(random.randint(1, 19))
    row.append("Mine")
    rows.append(row)

for _ in range(12):  # Rock-like: stone -> mid-range, less saturation
    row = [jitter(420, 40) if random.random() < 0.7 else jitter(10600, 100) for _ in range(8)]
    row.append(round(random.uniform(1, 38), 1))
    row.append("Rock")
    rows.append(row)

for _ in range(12):  # Negative: nothing in front -> near baseline
    row = [jitter(511, 15) for _ in range(8)]
    row.append(round(random.uniform(1, 20), 1))
    row.append("Negative")
    rows.append(row)

random.shuffle(rows)

with open("./demo_sensor_readings_SYNTHETIC.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(header)
    w.writerows(rows)

print("wrote", len(rows), "synthetic rows")

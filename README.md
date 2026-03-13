# ☀️ Single-Axis Solar Tracker

An Arduino-based single-axis solar tracker that uses two LDR sensor modules to detect light direction and rotates a servo motor to keep a solar panel oriented toward the brightest light source.

## 📌 How It Works

Two LDR modules are placed on the left and right sides of the panel. The Arduino reads their digital outputs and adjusts the servo angle to track the light source horizontally.

- **Left LDR detects more light** → Servo rotates left
- **Right LDR detects more light** → Servo rotates right
- **Both LDRs equal** → Servo stays still (aligned)

## 🔧 Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| LDR Sensor Module      | 2        |
| Servo Motor (SG90)     | 1        |
| Solar Panel (optional) | 1        |
| Jumper Wires           | As required |

## 📐 Wiring

| Component            | Arduino Pin |
|----------------------|-------------|
| Left LDR DO          | Pin 2       |
| Right LDR DO         | Pin 3       |
| Servo Signal         | Pin 9       |

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/danibae006/single-axis-solar-tracker.git
   ```
2. Open `Single_Axis_Solar_Tracker.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
3. Connect components according to the wiring table above.
4. Upload the sketch to your Arduino board.

## ⚙️ Configuration

Tune these values in the code to adjust tracking behavior:

```cpp
const int stepAngle = 2;   // Increase for faster tracking, decrease for smoother
const int minAngle  = 0;   // Minimum servo angle
const int maxAngle  = 180; // Maximum servo angle
int angle = 90;            // Starting position (center)
```

> **Note:** If your LDR modules give opposite logic (HIGH = dark, LOW = light), swap the conditions in the `if` statement inside `loop()`.

## 📄 License

MIT License — feel free to use and modify for your own projects.

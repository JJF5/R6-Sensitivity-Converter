# ADS Calculator

This program calculates adjusted aiming down sight (ADS) sensitivity values for various magnification levels in first-person shooter (FPS) games. It takes input parameters such as mouse sensitivity, field of view (FOV), aspect ratio, and magnification modifiers to provide accurate sensitivity settings for different zoom levels.

## Prerequisites

Before running the program, ensure you have a C++ compiler installed on your system.

## Usage

1. Clone this repository to your local machine.

Follow the on-screen prompts to input the required parameters such as mouse sensitivity, FOV, aspect ratio, and magnification modifiers.

After providing the inputs, the program will display the calculated ADS sensitivity values for different magnification levels.

Input Parameters
Mouse Sensitivity Multiplier: Multiplier applied to mouse sensitivity.
Sensitivity: Base sensitivity setting.
ADS: Aim down sight sensitivity setting.
XFactor: Horizontal sensitivity multiplier.
FOV: Field of view setting.
DPI: Dots per inch of your mouse.
Inch: 1 for true, 0 for false (whether your DPI is measured in inches).
Aspect Ratio: Aspect ratio of your display.
Use Legacy: 1 for true, 0 for false (whether to use legacy calculations).
Magnification Modifiers: Adjustments for different zoom levels (x1, x1.5, x2, x2.5, x3, x4, x5, x12).
Output
The program outputs the following:

Adjusted sensitivity values for various magnification levels (x1, x1.5, x2, x2.5, x3, x4, x5, x12).
FOV setting.
Revolutions per 360-degree turn (rev/360).
Converter value for transitioning from legacy ADS to shadow legacy ADS.
Contributing
Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or create a pull request.

License
This project is licensed under the MIT License.

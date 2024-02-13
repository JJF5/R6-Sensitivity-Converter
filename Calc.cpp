#define _USE_MATH_DEFINES  // Ensure that M_PI is defined
#include <iostream>
#include <cmath>

// Function declarations
double NewADS(double verticalFOV, double FOVMultiplier, double ADSMultiplier, double aspectRatio, double oldADS);
double CalculateADS(double modifier, double FOVMultiplier, double ADSMultiplier, double FOV, double aspectRatio,
    double Sens, double XFactor);
double revCalculator(double Sens);

struct InputData {
    double MouseSensMult;
    double Sensitivity;
    double ADS;
    double XFactor;
    double FOV;
    double DPI;
    int Inch;
    double aspectRatio;
    int useLegacy;
    double x1modifier;
    double x15modifier;
    double x2modifier;
    double x25modifier;
    double x3modifier;
    double x4modifier;
    double x5modifier;
    double x12modifier;
};

struct OutputData {
    double x1output;
    double x15output;
    double x2output;
    double x25output;
    double x3output;
    double x4output;
    double x5output;
    double x12output;
    double FOV;  // New field for FOV
    double rev360;  // New field for rev/360
    double converter;  // New field for converter
};

struct ResultData {
    double x1ADS;
    double x15ADS;
    double x2ADS;
    double x25ADS;
    double x3ADS;
    double x4ADS;
    double x5ADS;
    double x12ADS;
};

// Function definition for calculateAndDisplay
OutputData calculateAndDisplay(const InputData& inputs) {
    // Define .1 mrad
    const double dotmrad = 0.00572958;

    double Sens = (inputs.Sensitivity * inputs.MouseSensMult) / 0.02;
    double ADS = inputs.ADS;
    double XFactor = inputs.XFactor;
    double FOV = inputs.FOV;
    double DPI = inputs.DPI;
    int Inch = inputs.Inch;
    double aspectRatio = inputs.aspectRatio;

    double x1Modifier = inputs.x1modifier;
    double x15Modifier = inputs.x15modifier;
    double x2Modifier = inputs.x2modifier;
    double x25Modifier = inputs.x25modifier;
    double x3Modifier = inputs.x3modifier;
    double x4Modifier = inputs.x4modifier;
    double x5Modifier = inputs.x5modifier;
    double x12Modifier = inputs.x12modifier;

    double FOVMultiplier, ADSMultiplier;

    if (inputs.useLegacy) {
        FOVMultiplier = 0.9;
        ADSMultiplier = 0.6;

        x1Modifier = NewADS(FOV, FOVMultiplier, ADSMultiplier, aspectRatio, ADS);
        x15Modifier = NewADS(FOV, 0.59, 0.59, aspectRatio, ADS);
        x2Modifier = NewADS(FOV, 0.49, 0.49, aspectRatio, ADS);
        x25Modifier = NewADS(FOV, 0.42, 0.42, aspectRatio, ADS);
        x3Modifier = NewADS(FOV, 0.35, 0.35, aspectRatio, ADS);
        x4Modifier = NewADS(FOV, 0.3, 0.3, aspectRatio, ADS);
        x5Modifier = NewADS(FOV, 0.22, 0.22, aspectRatio, ADS);
        x12Modifier = NewADS(FOV, 0.092, 0.14, aspectRatio, ADS);
    }

    ResultData results;

    results.x1ADS = CalculateADS(x1Modifier, 0.9, 0.6, FOV, aspectRatio, Sens, XFactor);
    results.x15ADS = CalculateADS(x15Modifier, 0.59, 0.59, FOV, aspectRatio, Sens, XFactor);
    results.x2ADS = CalculateADS(x2Modifier, 0.49, 0.49, FOV, aspectRatio, Sens, XFactor);
    results.x25ADS = CalculateADS(x25Modifier, 0.42, 0.42, FOV, aspectRatio, Sens, XFactor);
    results.x3ADS = CalculateADS(x3Modifier, 0.35, 0.35, FOV, aspectRatio, Sens, XFactor);
    results.x4ADS = CalculateADS(x4Modifier, 0.3, 0.3, FOV, aspectRatio, Sens, XFactor);
    results.x5ADS = CalculateADS(x5Modifier, 0.22, 0.22, FOV, aspectRatio, Sens, XFactor);
    results.x12ADS = CalculateADS(x12Modifier, 0.092, 0.14, FOV, aspectRatio, Sens, XFactor);

    OutputData outputs;
    outputs.x1output = results.x1ADS;
    outputs.x15output = results.x15ADS;
    outputs.x2output = results.x2ADS;
    outputs.x25output = results.x25ADS;
    outputs.x3output = results.x3ADS;
    outputs.x4output = results.x4ADS;
    outputs.x5output = results.x5ADS;
    outputs.x12output = results.x12ADS;

    outputs.FOV = FOV;  // Assign FOV
    outputs.rev360 = revCalculator(Sens);  // Assign rev/360
    outputs.converter = NewADS(FOV, 0.92, 0.6, aspectRatio, ADS);  // Assign converter

    return outputs;
}

// Main function
int main() {
    InputData inputs;
    std::cout << "Enter Mouse Sensitivity Multiplier: ";
    std::cin >> inputs.MouseSensMult;

    std::cout << "Enter Sensitivity: ";
    std::cin >> inputs.Sensitivity;

    std::cout << "Enter ADS: ";
    std::cin >> inputs.ADS;

    std::cout << "Enter XFactor: ";
    std::cin >> inputs.XFactor;

    std::cout << "Enter FOV: ";
    std::cin >> inputs.FOV;

    std::cout << "Enter DPI: ";
    std::cin >> inputs.DPI;

    std::cout << "Enter Inch (1 for true, 0 for false): ";
    std::cin >> inputs.Inch;

    std::cout << "Enter Aspect Ratio: ";
    std::cin >> inputs.aspectRatio;

    std::cout << "Use Legacy (1 for true, 0 for false): ";
    std::cin >> inputs.useLegacy;

    std::cout << "Enter x1 Modifier: ";
    std::cin >> inputs.x1modifier;

    std::cout << "Enter x1.5 Modifier: ";
    std::cin >> inputs.x15modifier;

    std::cout << "Enter x2 Modifier: ";
    std::cin >> inputs.x2modifier;

    std::cout << "Enter x2.5 Modifier: ";
    std::cin >> inputs.x25modifier;

    std::cout << "Enter x3 Modifier: ";
    std::cin >> inputs.x3modifier;

    std::cout << "Enter x4 Modifier: ";
    std::cin >> inputs.x4modifier;

    std::cout << "Enter x5 Modifier: ";
    std::cin >> inputs.x5modifier;

    std::cout << "Enter x12 Modifier: ";
    std::cin >> inputs.x12modifier;

    OutputData outputs = calculateAndDisplay(inputs);

    std::cout << "Results (without modifiers):" << std::endl;
    std::cout << "x1output: " << outputs.x1output << std::endl;
    std::cout << "x15output: " << outputs.x15output << std::endl;
    std::cout << "x2output: " << outputs.x2output << std::endl;
    std::cout << "x25output: " << outputs.x25output << std::endl;
    std::cout << "x3output: " << outputs.x3output << std::endl;
    std::cout << "x4output: " << outputs.x4output << std::endl;
    std::cout << "x5output: " << outputs.x5output << std::endl;
    std::cout << "x12output: " << outputs.x12output << std::endl;

    // Output additional values
    std::cout << "FOV: " << outputs.FOV << std::endl;
    std::cout << "rev/360: " << outputs.rev360 << std::endl;
    std::cout << "Re-Shadow Legacy ADS to Shadow Legacy ADS converter: " << outputs.converter << std::endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

unsigned int getHighestDigitInRange(const std::string& batteryBank, unsigned int startPos, unsigned int endPos) {
    int highestValPos = -1;
    int highestVal = -1;
    for (unsigned int i = startPos; i < endPos; i++) {
        int inspectedBatteryVoltage = batteryBank[i] - '0'; // Convert char to int
        if (highestVal< inspectedBatteryVoltage) {
            highestValPos = i;
            highestVal = inspectedBatteryVoltage;
        }
    }
    return highestValPos;
}

unsigned int concatVoltages(const std::string& batteryBank, unsigned int leftDigitPos, unsigned int rightDigitPos) {
    return std::stoi(std::string(1,batteryBank[leftDigitPos]) + batteryBank[rightDigitPos]);
}

unsigned int getBankVoltage(const std::string& batteryBank) {

    unsigned int highestBatVoltPos =
        getHighestDigitInRange(batteryBank, 0, batteryBank.length());

    int leftHighestBatVoltPos = -1;
    if (highestBatVoltPos > 0) {
        leftHighestBatVoltPos = getHighestDigitInRange(batteryBank, 0, highestBatVoltPos);
    }

    int rightHighestBatVoltPos = -1;
    if (highestBatVoltPos < (batteryBank.length() - 1) ) {
        rightHighestBatVoltPos = getHighestDigitInRange(batteryBank, highestBatVoltPos + 1, batteryBank.length());
    }

    //See if either number is automatically disqualified
    if (leftHighestBatVoltPos == -1) {
        return concatVoltages(batteryBank, highestBatVoltPos, rightHighestBatVoltPos);
    } else if (rightHighestBatVoltPos == -1) {
        return concatVoltages(batteryBank, leftHighestBatVoltPos, highestBatVoltPos);
    } else {
        // Both numbers are possible candidates
        // Get the two numbers to compare
        unsigned int rightNumber =
            concatVoltages(batteryBank, leftHighestBatVoltPos, highestBatVoltPos);
        unsigned int leftNumber =
            concatVoltages(batteryBank, highestBatVoltPos, rightHighestBatVoltPos);
        // Provide the largest number that has been found
        if (leftNumber > rightNumber) {
            return leftNumber;
        } else {
            return rightNumber;
        }
    }
}

int main() {
    //Storage variables
    std::ifstream inputFile("input.txt");
    std::vector<std::string> batteryBanks;

    // Read the data out of the file
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            batteryBanks.push_back(line);
        }
        inputFile.close();
    } else {
        std::cout << "Error: Unable to open the file." << std::endl;
    }

    std::vector<unsigned int> bankVoltages;
    for (const std::string& batteryBank : batteryBanks) {
        bankVoltages.push_back(getBankVoltage(batteryBank));
    }

    //Gather the sum
    unsigned int totalVoltage = 0;
    for (unsigned int bankVoltage : bankVoltages) {
        totalVoltage += bankVoltage;
    }
    std::cout << "Total voltage of banks is:  " << totalVoltage << std::endl;
}

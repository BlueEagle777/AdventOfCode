#include <iostream>
#include <fstream>
#include <vector>

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

    for (std::string batteryBank :batteryBanks) {
        std::cout << batteryBank << "\n";
    }
    std::cout << std::endl;
}

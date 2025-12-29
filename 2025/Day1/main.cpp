#include <iostream>
#include <fstream>
#include <string>

int main() {

    int safeDial = 50;
    unsigned int password = 0;

    std::cout << "Reading the text file" << std::endl;
    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            char rotateDirection = line[0];
            int rotationNum = std::stoi(line.substr(1));

            // Rotate the dial
            if (rotateDirection == 'R') {
                safeDial += rotationNum;
                while (safeDial > 99) {
                    safeDial -= 100;
                }
            } else if (rotateDirection == 'L') {
                safeDial -= rotationNum;
                while (safeDial < 0) {
                    safeDial += 100;
                }
            }

            std::cout << safeDial << std::endl;

            // Get the password
            if (safeDial == 0) {
                password++;
            }
        }
        inputFile.close();
    } else {
        std::cout << "Error: Unable to open the file." << std::endl;
    }

    std::cout << "The password is: " << password;
    std::cout << std::endl;
}

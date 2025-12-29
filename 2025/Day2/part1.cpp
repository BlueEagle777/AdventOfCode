#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct range {
    unsigned int start;
    unsigned int end;
};

int main() {
    std::ifstream inputFile("input.txt");
    std::string fileContents;
    std::vector<range> rangeArray;

    // Read the data out of the file
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            fileContents.append(line);
        }
        inputFile.close();
    } else {
        std::cout << "Error: Unable to open the file." << std::endl;
    }

    std::cout << fileContents << std::endl;

    //Read the data into an vector
    bool stopRangeArrayGen = false;
    do {
        int hyphenLoc = fileContents.find('-');
        int commaLoc = fileContents.find(',');
        range rangeToAdd;

        rangeToAdd.start = std::stoi(fileContents.substr(0,hyphenLoc));
        rangeToAdd.end = std::stoi(fileContents.substr(hyphenLoc + 1, commaLoc));
        rangeArray.push_back(rangeToAdd);

        //Check if the end has been reached
        if (commaLoc == -1 ) {
            stopRangeArrayGen = true;
        } else {
            fileContents.erase(0,commaLoc+1);
        }
    } while (stopRangeArrayGen == false);


    for (range inspected :  rangeArray) {
        std::cout << inspected.start << " " << inspected.end << std::endl;
    }

}

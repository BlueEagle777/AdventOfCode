#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct range {
    unsigned long start;
    unsigned long end;
};

int main() {
    //Storage variables
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

    //Read the data into an vector
    bool stopRangeArrayGen = false;
    do {
        unsigned long hyphenLoc = fileContents.find('-');
        unsigned long commaLoc = fileContents.find(',');
        range rangeToAdd;

        rangeToAdd.start = std::stoul(fileContents.substr(0,hyphenLoc));
        rangeToAdd.end = std::stoul(fileContents.substr(hyphenLoc + 1, commaLoc));
        rangeArray.push_back(rangeToAdd);

        //Check if the end has been reached
        if (commaLoc == -1 ) {
            stopRangeArrayGen = true;
        } else {
            fileContents.erase(0,commaLoc+1);
        }
    } while (stopRangeArrayGen == false);

    //Go through the ranges and check for invalid IDs
    unsigned long totalOfInvalid = 0;
    for (int i = 0; i < rangeArray.size(); i++) {
        //Step through the range
        for (unsigned long inspectProdId = rangeArray[i].start; inspectProdId < (rangeArray[i].end + 1); inspectProdId++) {
            //Investigate the product ID that is present in the range
            std::string stringProdId = std::to_string(inspectProdId);
            if (stringProdId.length() % 2 == 0) {
                std::string firstHalf = stringProdId.substr(0,stringProdId.length()/2);
                std::string secondHalf = stringProdId.substr((stringProdId.length()/2));
                if (firstHalf == secondHalf) {
                    totalOfInvalid += inspectProdId;
                }
            }
        }
    }

    std::cout << "Invalid number total is: " << totalOfInvalid << std::endl;
}

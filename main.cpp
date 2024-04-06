//Modules 
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 
#include <vector> 
#include "students.h"
#include "company.h"
#include "interview.h"

//Global Variables
#define STR_BOOL_TRUE "1"
#define STR_BOOL_FALSE "0"


//Functions

//DataFormatters
std::string stripWhitespace(const std::string& inputString) {
    std::string result = inputString; 

    size_t firstNonSpace = result.find_first_not_of(" \t\n\r");
    if (firstNonSpace != std::string::npos)
        result.erase(0, firstNonSpace);

    size_t lastNonSpace = result.find_last_not_of(" \t\n\r");
    if (lastNonSpace != std::string::npos)
        result.erase(lastNonSpace + 1);

    return result;
}

std::string toLowercase(const std::string& inputString) {
    std::string result = inputString; 

    std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c) { return std::tolower(c); });

    return result;
}

std::string fD(const std::string& inputString) {    
    return toLowercase(stripWhitespace(inputString));
}

//Gets index of the word in the file
int getIndexFromData(const std::string& filePath, const std::string& searchWord) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
                count++;
            if (line == searchWord) {
                return count;
            }
        }
    }
    return count;
}

//Gets the word from the file at a particular index
std::string getDataFromIndex(const std::string& filePath, int index) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (count == index) {
                return line;
            }
        }
    }
    return "";
}

//Returns an array of index of all the strings that match the searchWord
std::vector<int> getIndicesVectorFromSearchWord(const std::string& filePath, const std::string& searchWord) {
    std::vector<int> result;
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            if (line == searchWord) {
                result.push_back(count);
            }
        }
    }
    return result;
}

//Changes the Data at a particular index in the file
void changeDataAtIndex(const std::string& filename, int index, const std::string& newLine) {
    std::ifstream inputFile(filename); // Open the input file for reading
    std::ofstream tempFile("temp.txt"); // Create a temporary output file

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (lineNumber == index) {
            // Replace the line at the specified index
            tempFile << fD(newLine) << std::endl;
        } else {
            // Copy other lines unchanged
            tempFile << line << std::endl;
        }
        
    }

    inputFile.close();
    tempFile.close();

    std::ofstream outputFile(filename, std::ios::out); // Open the output file for writing
    std::ifstream tempInputFile("temp.txt"); // Open the temporary input file for reading
    std::string tempLine;
    while (std::getline(tempInputFile, tempLine)) {
        outputFile << tempLine << std::endl;
    }

    tempInputFile.close();
    outputFile.close();
    std::remove("temp.txt"); // Remove the temporary file



}









//Main Function
int main(){
     // Open the file "my_file.txt" (replace with your file name)

    std::string filePath1 = "Database/PlacementManager/Company/CompanyName.txt";
    // std::string filePath2 = "Name.txt";

    changeDataAtIndex(filePath1, getIndexFromData(filePath1, "orange"), "  amazon  ");
    changeDataAtIndex(filePath1, 2, "  Apple ");
    // std::string filePath2 = "Database/PlacementManager/Company/CompanyEmail.txt";
    // std::string searchWord1 = "tesla";
    // std::string searchWord2 = "google";
    // int index = getIndexFromData(filePath1, searchWord1);
    // std::cout << index << std::endl;
    // std::string word = getDataFromIndex(filePath2, index);
    // std::cout << word << std::endl;
    // std::vector<int> indices = getIndicesVectorFromSearchWord(filePath1, searchWord2);
    // for (int i = 0; i < indices.size(); i++) {
    //     std::cout << indices[i] << " " << std::endl;
    // }
    // std::ifstream file("Database/PlacementManager/Company/CompanyName.txt");
    // std::string line;

    // if (file.is_open()) {
    //     int i = 0;
    //     // Read each line from the file
    //     while (getline(file, line)) {
    //         i++;
    //         if (line == "adobe"){
    //         std::cout << i << " " << line << std::endl;
    //         }
    //     }

    //     // Close the file
    //     file.close();
    // } else {
    //     // Display an error message if the file cannot be opened
    //     std::cerr << "Unable to open file!" << std::endl;
    // }
 
   

    return 0;
}
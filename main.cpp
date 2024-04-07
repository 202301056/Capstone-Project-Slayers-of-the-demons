//Modules 
#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include "functions.hpp"
#include "students.h"
#include "company.h"
#include "interview.h"

//Global Variables
#define STR_BOOL_TRUE "1"
#define STR_BOOL_FALSE "0"


//Functions

//Gets index of the word in the file
int getIndexFromData(const std::string& filePath, const std::string& searchWord) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
                count++;
            if (line == fD(searchWord)) {
                return count;
            }
        }
    }
    return -1;
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
            if (line == fD(searchWord)) {
                result.push_back(count);
            }
        }
    }
    return result;
}

//Changes the Data at a particular index in the file
void changeDataAtIndex(const std::string& filename, int index, const std::string& newLine) {
    std::ifstream inputFile(filename); 
    std::ofstream tempFile("temp.txt"); 

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (lineNumber == index) {
            if(newLine != "") {
            tempFile << fD(newLine) << std::endl;
            }
            else{
                 tempFile << fD(newLine);
            }
        } else {
            tempFile << line << std::endl;
        }
        
    }

    inputFile.close();
    tempFile.close();

    std::ofstream outputFile(filename, std::ios::out); 
    std::ifstream tempInputFile("temp.txt"); 
    std::string tempLine;
    while (std::getline(tempInputFile, tempLine)) {
        outputFile << tempLine << std::endl;
    }

    tempInputFile.close();
    outputFile.close();
    std::remove("temp.txt");

}


//Company functions
void addNewCompany() {
    std::string companyName, companyEmail, companyContact;
    std::cout << "Enter company name: ";
    std::getline(std::cin, companyName);
    std::cout << "Enter company email: ";
    std::getline(std::cin, companyEmail);
    std::cout << "Enter company Contact Number: ";
    std::getline(std::cin, companyContact);
    Company (companyName, companyEmail, companyContact);
    std::cout << "Company Added Successfully!" << std::endl;
}

void deleteCompany(const std::string& companyName){
    int index = getIndexFromData("Database/PlacementManager/Company/CompanyName.txt", companyName);
    if(index == -1){
        std::cout << "No such company found!" << std::endl;
    }
    changeDataAtIndex("Database/PlacementManager/Company/CompanyName.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Company/CompanyEmail.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Company/CompanyContactNumber.txt", index, "");
    std::cout << "Company deleted successfully!" << std::endl;

}


//Student functions
void addNewStudent() {
    std::string studentID, fullName, email, program, contactNumber, alternateNumber, skypeID;
    std::cout << "Enter student ID: ";
    std::getline(std::cin, studentID);
    std::cout << "Enter Fullname (Format: firstname lastname): ";
    std::getline(std::cin, fullName);
    std::cout << "Enter Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter Program (Format: B-Tech ICT): ";
    std::getline(std::cin, program);
    std::cout << "Enter Contact Number: ";
    std::getline(std::cin, contactNumber);
    std::cout << "Enter Alternate Number: ";
    std::getline(std::cin, alternateNumber);
    std::cout << "Enter Skype ID: ";
    std::getline(std::cin, skypeID);
    Student(studentID, fullName, email, program, contactNumber, alternateNumber, skypeID);
    std::cout << "Student Added Successfully!" << std::endl;
}

void deleteStudent(const std::string& studentID){
    int index = getIndexFromData("Database/PlacementManager/Student/Student_ID.txt", studentID);
    if(index == -1){
        std::cout << "No such student found!" << std::endl;
    }
    changeDataAtIndex("Database/PlacementManager/Student/Student_ID.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/FullName.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/Email.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/Program.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/ContactNumber.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/AlternateNumber.txt", index, "");
    changeDataAtIndex("Database/PlacementManager/Student/SkypeID.txt", index, "");

    std::cout << "Student deleted successfully!" << std::endl;


}


//Interview Functions
void scheduleAnInterview() {

    std::string companyName, intervieweeID, interviewDate, interviewTime, venue, status, packageoffered, offeraccepted;
    std::cout << "Enter Interviewing Company Name: ";
    std::getline(std::cin, companyName);
    std::cout << "Enter Interviewee Student ID: ";
    std::getline(std::cin, intervieweeID);
    std::cout << "Enter Interview Date (Format: dd/mm/yyyy): ";
    std::getline(std::cin, interviewDate);
    std::cout << "Enter Interview Time (Format: hh:mm): ";
    std::getline(std::cin, interviewTime);
    std::cout << "Enter Interview Venue: ";
    std::getline(std::cin, venue);
    Interview(companyName, intervieweeID, interviewDate, interviewTime, venue);
    std::cout << "Interview Scheduled Successfully!" << std::endl;

}

int getTheIndexOfInterview(std::string companyName, std::string intervieweeID){
    std::vector<int> indicesOfCompanyName = getIndicesVectorFromSearchWord("Database/PlacementManager/Interview/InterviewingCompany.txt", companyName);
    std::vector<int> indicesOfIntervieweeID = getIndicesVectorFromSearchWord("Database/PlacementManager/Interview/Interviewee.txt", intervieweeID);
    for(int i=0; i<indicesOfCompanyName.size(); i++){
        for(int j=0; j<indicesOfIntervieweeID.size(); j++){
            if(indicesOfCompanyName[i] == indicesOfIntervieweeID[j]){
                return indicesOfCompanyName[i];
            }
        }
    }
    return -1;
}

void cancelAnInterview(std::string companyName, std::string intervieweeID) {
    int index = getTheIndexOfInterview(companyName, intervieweeID);

    if(index == -1){
        std::cout << "No such interview found!" << std::endl;
    }
    else{
        changeDataAtIndex("Database/PlacementManager/Interview/InterviewingCompany.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Interviewee.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/DateOfInterview.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/TimeOfInterview.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Venue.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/Status.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/PackageOffered.txt", index, "");
        changeDataAtIndex("Database/PlacementManager/Interview/OfferAccepted.txt", index, "");
    }

}

void changeInterviewstatus(std::string companyName, std::string intervieweeID){
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    std::string status;
    std::cout << "Enter new status (C for completed/I for incomplete): ";
    std::getline(std::cin, status);
    changeDataAtIndex("Database/PlacementManager/Interview/Status.txt", index, fD(status));
    std::cout << "Status changed successfully!" << std::endl;
}

void resultAnInterview(std::string companyName, std::string intervieweeID) {
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    std::string hired, package;
    std::cout << "Is the candidate hired? (Y/N): ";
    std::getline(std::cin, hired);
    if(fD(hired) == "y"){
        std::cout << "Offer Package Amount (Format:XXXXXXXX): ";
        std::getline(std::cin, package);
        changeDataAtIndex("DataBase/PlacementManager/Interview/PackageOffered.txt", index, fD(package));
    }
    else{
        changeDataAtIndex("DataBase/PlacementManager/Interview/PackageOffered.txt", index, "notHired");
        changeDataAtIndex("DataBase/PlacementManager/Interview/OfferAccepted.txt", index, "notHired");
    }
    std::cout << "Interview Resulted Successfully!" << std::endl;    
}

void studentAcceptedOffer(std::string companyName, std::string intervieweeID){
    int index = getTheIndexOfInterview(companyName, intervieweeID);
    changeDataAtIndex("Database/PlacementManager/Interview/OfferAccepted.txt", index, "y");
    std::cout << "Offer Marked Accepted Successfully!" << std::endl;
}

//Main Function
int main(){
    

    




    // Open the file "my_file.txt" (replace with your file name)

    // std::string filePath1 = "Database/PlacementManager/Company/CompanyName.txt";
    // std::string filePath2 = "Name.txt";

    // changeDataAtIndex(filePath1, getIndexFromData(filePath1, "orange"), "  amazon  ");
    // changeDataAtIndex(filePath1, 2, "  Apple ");
    // std::string filePath2 = "Database/PlacementManager/Company/CompanyEmail.txt";
    // std::string searchWord1 = "miCrosoft ";
    // std::string searchWord2 = "google";
    // int index = getIndexFromData(filePath1, (searchWord1));
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
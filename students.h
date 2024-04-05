//Modules
#include <string>
#include <fstream>

#ifndef STUDENT_H
#define STUDENT_H

class Student {

private:

    //Private Student Variables
    int Student_ID;
    std::string FullName;
    std::string Email;
    std::string Program;
    int ContactNumber;
    int WhatsappNumber;
    int AlternateNumber;
    std::string SkypeID;

    //Resoures for database
    std::string ColumnPath="Database/PlacementManager/Student/";
    

public:

    //Constructor
        Student(int studentID, const std::string& fullName, const std::string& email,
            const std::string& program, int contactNumber, int whatsappNumber,
            int alternateNumber, const std::string& skypeID)
        : Student_ID(studentID), FullName(fullName), Email(email), Program(program),
          ContactNumber(contactNumber), WhatsappNumber(whatsappNumber),
          AlternateNumber(alternateNumber), SkypeID(skypeID) {

            std::ofstream studentid;
            studentid.open(ColumnPath+"Student_ID.txt", std::ios::app);
            if (studentid.is_open()){
                studentid << Student_ID << std::endl;
                studentid.close();
            }
            std::ofstream fullname;
            fullname.open(ColumnPath+"FullName.txt", std::ios::app);
            if (fullname.is_open()){
                fullname << FullName << std::endl;
                fullname.close();
            }
            std::ofstream studentemail;
            studentemail.open(ColumnPath+"Email.txt", std::ios::app);
            if (studentemail.is_open()){
                studentemail << Email << std::endl;
                studentemail.close();
            }
            std::ofstream studentprogram;
            studentprogram.open(ColumnPath+"Program.txt", std::ios::app);
            if (studentprogram.is_open()){
                studentprogram << Program << std::endl;
                studentprogram.close();
            }
            std::ofstream contactnumber;
            contactnumber.open(ColumnPath+"ContactNumber.txt", std::ios::app);
            if (contactnumber.is_open()){
                contactnumber << ContactNumber << std::endl;
                contactnumber.close();
            }
            std::ofstream whatsappnumber;
            whatsappnumber.open(ColumnPath+"WhatsappNumber.txt", std::ios::app);
            if (whatsappnumber.is_open()){
                whatsappnumber << WhatsappNumber << std::endl;
                whatsappnumber.close();
            }
            std::ofstream alternatenumber;
            alternatenumber.open(ColumnPath+"AlternateNumber.txt", std::ios::app);
            if (alternatenumber.is_open()){
                alternatenumber << AlternateNumber << std::endl;
                alternatenumber.close();
            }
            std::ofstream skypeid;
            skypeid.open(ColumnPath+"SkypeID.txt", std::ios::app);
            if (skypeid.is_open()){
                skypeid << SkypeID << std::endl;
                skypeid.close();
            }
    }

    //Public Student Methods
    void displayStudent() {
        std::cout << "Student ID: " << Student_ID << std::endl;
        std::cout << "Full Name: " << FullName << std::endl;
        std::cout << "Email: " << Email << std::endl;
        std::cout << "Program: " << Program << std::endl;
        std::cout << "Contact Number: " << ContactNumber << std::endl;
        std::cout << "WhatsApp Number: " << WhatsappNumber << std::endl;
        std::cout << "Alternate Number: " << AlternateNumber << std::endl;
        std::cout << "Skype ID: " << SkypeID << std::endl;
    }

    int getStudentID(){
        return Student_ID;
    }

    

};

#endif 

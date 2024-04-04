//Modules
// #include <string>


//Making sure class is only compiled once
#ifndef STUDENT_H
#define STUDENT_H


//Class defines a student and all his details
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

public:

    //Constructor
        Student(int studentID, const std::string& fullName, const std::string& email,
            const std::string& program, int contactNumber, int whatsappNumber,
            int alternateNumber, const std::string& skypeID)
        : Student_ID(studentID), FullName(fullName), Email(email), Program(program),
          ContactNumber(contactNumber), WhatsappNumber(whatsappNumber),
          AlternateNumber(alternateNumber), SkypeID(skypeID) {
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

};

#endif 

#include "students.h"

#ifndef INTERVIEW_H
#define INTERVIEW_H

class Interview{
    
    private:
    Company InterviewingCompany;
    Student Interviewee;
    std::string DateOfInterview;   //(dd/mm/yyyy)
    std::string TimeOfInterview;   //(hh:mm)
    std::string Venue;
    bool Status = 0;  //Complete-Incomplete
    bool Hired;   //Yes-No
    int Package;  //Package obtain if Hired

};









#endif
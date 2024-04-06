#include "students.h"
#include "company.h"

#ifndef INTERVIEW_H
#define INTERVIEW_H

class Interview{
    
    private:
    Company InterviewingCompany;
    Student Interviewee;
    std::string DateOfInterview;   //(dd/mm/yyyy)
    std::string TimeOfInterview;   //(hh:mm)
    std::string Venue;
    std::string Status;  //Complete-Incomplete
    std::string Hired;   //Yes-No
    std::string Package;  //Package obtain if Hired

    std::string ColumnPath = "Database/PlacementManager/Interview/";

    public:
    Interview(const Company& interviewingcompany, const Student& interviewee, const std::string& date, const std::string& time, const std::string& venue, const std::string& status = "0", const std::string& hired = "0", const std::string& package="0")
        :InterviewingCompany(interviewingcompany), Interviewee(interviewee), DateOfInterview(date), TimeOfInterview(time), Venue(venue), Status(status), Hired(hired), Package(package) 
        {

            std::ofstream nameofinterviewingcompany;
            nameofinterviewingcompany.open(ColumnPath+"InterviewingCompany.txt", std::ios::app);
            if (nameofinterviewingcompany.is_open()){
                nameofinterviewingcompany << InterviewingCompany.getCompanyName() << std::endl;
                nameofinterviewingcompany.close();
            }

            std::ofstream nameofinterviewee;
            nameofinterviewee.open(ColumnPath+"Interviewee.txt", std::ios::app);
            if (nameofinterviewee.is_open()){
                nameofinterviewee << Interviewee.getStudentID() << std::endl;
                nameofinterviewee.close();
            }

            std::ofstream dateoftheinterview;
            dateoftheinterview.open(ColumnPath+"DateOfInterview.txt", std::ios::app);
            if (dateoftheinterview.is_open()){
                dateoftheinterview << DateOfInterview << std::endl;
                dateoftheinterview.close();
            }

            std::ofstream timeoftheinterview;
            timeoftheinterview.open(ColumnPath+"TimeOfInterview.txt", std::ios::app);
            if (timeoftheinterview.is_open()){
                timeoftheinterview << TimeOfInterview << std::endl;
                timeoftheinterview.close();
            }

            std::ofstream venueoftheinterview;
            venueoftheinterview.open(ColumnPath+"Venue.txt", std::ios::app);
            if (venueoftheinterview.is_open()){
                venueoftheinterview << Venue << std::endl;
                venueoftheinterview.close();
            }

            std::ofstream statusoftheinterview;
            statusoftheinterview.open(ColumnPath+"Status.txt", std::ios::app);
            if (statusoftheinterview.is_open()){
                statusoftheinterview << Status << std::endl;
                statusoftheinterview.close();
            }
            
            std::ofstream candidatehiredOrnot;
            candidatehiredOrnot.open(ColumnPath+"Hired.txt", std::ios::app);
            if (candidatehiredOrnot.is_open()){
                candidatehiredOrnot << Hired << std::endl;
                candidatehiredOrnot.close();
            }

            std::ofstream packagereceivedifHired;
            packagereceivedifHired.open(ColumnPath+"Package.txt", std::ios::app);
            if (packagereceivedifHired.is_open()){
                packagereceivedifHired << Package << std::endl;
                packagereceivedifHired.close();
            }

    }


};

#endif
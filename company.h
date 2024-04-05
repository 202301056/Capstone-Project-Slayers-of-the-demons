#include <fstream>
#include <string>

#ifndef COMPANY_H
#define COMPANY_H

class Company {
    
    private:

    std::string CompanyName;
    std::string CompanyEmail;
    int CompanyContactNumber;

    std::string ColumnPath = "Database/PlacementManager/Company/";

    public:

    //constructor
    Company(const std::string& companyname, const std::string companyemail, int companycontactnumber)
        :CompanyName(companyname), CompanyEmail(companyemail), CompanyContactNumber(companycontactnumber) {
            
            std::ofstream constructorcompanyname;
            constructorcompanyname.open(ColumnPath+"CompanyName.txt", std::ios::app);
            if (constructorcompanyname.is_open()){
                constructorcompanyname << CompanyName << std::endl;
                constructorcompanyname.close();
            }
            std::ofstream constructorcompanyemail;
            constructorcompanyemail.open(ColumnPath+"CompanyEmail.txt", std::ios::app);
            if (constructorcompanyemail.is_open()){
                constructorcompanyemail << CompanyEmail << std::endl;
                constructorcompanyemail.close();
            }
            std::ofstream constructorcompanycontactnumber;
            constructorcompanycontactnumber.open(ColumnPath+"CompanyContactNumber.txt", std::ios::app);
            if (constructorcompanycontactnumber.is_open()){
                constructorcompanycontactnumber << CompanyContactNumber << std::endl;
                constructorcompanycontactnumber.close();
            }

    }

    std::string getCompanyName(){
        return CompanyName;
    }
};

#endif
#ifndef COMPANY_H
#define COMPANY_H

class Company {
    private:
    std::string CompanyName;
    std::string CompanyEmail;
    int CompanyContactNumber;

    public:

    //constructor
    Comapny(const std::string& companyname, const std::string companyemail, int companycontactnumber)
        :CompanyName(companyname), CompanyEmail(companyemail), CompanyContactNumber(companycontactnumber) {
    }
};

#endif
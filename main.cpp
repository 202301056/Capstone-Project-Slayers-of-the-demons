
//Modules 
#include <iostream>
#include <string>
#include "students.h"
// #include "sqlite3.h"
#include "company.h"
#include "interview.h"

int main(){
    std::string var = "fart";
    Student raj(202301056, "gd", "dgd", "edgewrq", 353, 3523, 4622, "hknrik");
    Company google("Google", "google@fart.com", 94094098);
    Interview first(google, raj, "10/12/2005", "20:40", "BabaKaThela");
    std::cout<<var<<"?gad";

    return 0;
}
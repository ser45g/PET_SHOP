#include <iostream>
#include "journal.h"

using namespace std;



int main()
{
    legend _legend("C:\\Users\\Logan\\CLionProjects\\Journal\\legend");
    journal _journal("C:\\Users\\Logan\\CLionProjects\\Journal\\Journal",&_legend);

    _journal.deduct_student("Ivanovskij", "Mihail", "Asadovich");
    _journal.deduct_student("Simonov Aleksej Aleksandrovich");
    _journal.deduct_student("Mjagkohod Igor' Andreevich");
    _journal.add_student("Gornostayev German Sergeevich",{"+","H"});

    _journal.change_last_name("Mashkova Oksana Sergeevna", "Shibkova");
    _journal.erase_date(date("23.12.17"));
    _journal.add_date(date("28.12.17"));

    return 0;
}
//
// Created by Logan on 26.12.2017.
//

#ifndef JOURNAL_JOURNAL_H
#define JOURNAL_JOURNAL_H

#include "student.h"

class journal
{
public:

    //Constructor & Destructor
    journal(const std::string &_file_name, const legend* _legend);
    ~journal();

    // Methods with students
    bool deduct_student(std::string full_name);
    bool deduct_student(std::string last_name,std::string first_name,std::string father_name);
    void add_student(std::string full_name, std::vector<std::string> student_date_content);
    void add_student(std::string last_name,std::string first_name,std::string father_name, std::vector<std::string> student_date_content);

    //Change student names
    bool change_first_name(std::string full_name, std::string new_first_name);
    bool change_first_name(std::string first_name, std::string last_name, std::string father_name, std::string new_first_name);
    bool change_last_name(std::string full_name, std::string new_last_name);
    bool change_last_name(std::string first_name, std::string last_name, std::string father_name, std::string new_last_name);
    bool change_father_name(std::string full_name, std::string new_father_name);
    bool change_father_name(std::string first_name, std::string last_name, std::string father_name, std::string new_father_name);

    //Methods with dates
    bool erase_date(date _date);
    bool add_date(date _date);



private:
    std::set<student> _students;
    std::set<date> _dates;
    const legend* _legend;
    std::string _file_name;

    //tmp's for student changes
    std::string _tmp_first_name;
    std::string _tmp_last_name;
    std::string _tmp_father_name;

    void parse_names(std::string full_name);

    // To make this methods unavailiable
    journal(const journal& orig) {}
    journal operator = (const journal& orig) { return *this;}
};


#endif //JOURNAL_JOURNAL_H

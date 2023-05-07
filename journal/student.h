//
// Created by Logan on 26.12.2017.
//

#ifndef JOURNAL_STUDENT_H
#define JOURNAL_STUDENT_H

#include <set>
#include "cell.h"


class student
{
public:
    //Getters & Setters
    const std::string &get_first_name() const;
    void set_first_name(const std::string &_first_name);
    const std::string &get_last_name() const;
    void set_last_name(const std::string &_last_name);
    const std::string &get_father_name() const;
    void set_father_name(const std::string &_father_name);

    //Constructors

    student(const std::string &_first_name, const std::string &_last_name, const std::string &_father_name,
            const std::set<cell> &_cells);

    student(const std::string &_first_name, const std::string &_last_name, const std::string &_father_name);

    //Operators
    bool operator==(const student& right) const;
    bool operator< (const student& right) const;

    //Methods
    std::string get_student_as_a_string() const;
    std::string get_set_as_string() const;
    void erase_cell_with_date(date _date);
    void add_cell_with_date(const date* _date, const legend* _legend);


private:
    std::string _first_name;
    std::string _last_name;
    std::string _father_name;
    std::set<cell> _cells;
};


#endif //JOURNAL_STUDENT_H

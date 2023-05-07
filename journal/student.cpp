//
// Created by Logan on 26.12.2017.
//

#include "student.h"


const std::string &student::get_first_name() const
{
    return _first_name;
}

void student::set_first_name(const std::string &_first_name)
{
    student::_first_name = _first_name;
}

const std::string &student::get_last_name() const
{
    return _last_name;
}

void student::set_last_name(const std::string &_last_name)
{
    student::_last_name = _last_name;
}

const std::string &student::get_father_name() const
{
    return _father_name;
}

void student::set_father_name(const std::string &_father_name)
{
    student::_father_name = _father_name;
}

student::student(const std::string &_first_name, const std::string &_last_name, const std::string &_father_name,
                 const std::set<cell> &_cells) : _first_name(_first_name), _last_name(_last_name),
                                                 _father_name(_father_name), _cells(_cells) {}

student::student(const std::string &_first_name, const std::string &_last_name, const std::string &_father_name)
        : _first_name(_first_name), _last_name(_last_name), _father_name(_father_name) {}

bool student::operator==(const student &right) const
{
    return (get_last_name() + get_first_name() + get_father_name()) == (right.get_last_name() + right.get_first_name() + right.get_father_name());
}

bool student::operator<(const student &right) const
{
    return (get_last_name() + get_first_name() + get_father_name()) < (right.get_last_name() + right.get_first_name() + right.get_father_name());
}

std::string student::get_student_as_a_string() const
{
    return get_last_name() + " " + get_first_name() + " " + get_father_name() + " " + get_set_as_string();
}

std::string student::get_set_as_string() const {

    std::string result;

    auto iter = _cells.cbegin();
    auto last = _cells.cend();
    last--;

    for(;iter!=_cells.end();iter++)
    {
        result += iter->get_content();
        if(iter != last)
            result = result + " ";
    }

    return result;
}

void student::erase_cell_with_date(date _date)
{
    auto range = _cells.equal_range(cell(&_date));
    _cells.erase(range.first,range.second);
}

void student::add_cell_with_date(const date* _date,const legend* _legend)
{
    _cells.insert(cell(_date, _legend));
}



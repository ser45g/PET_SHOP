//
// Created by Logan on 18.12.2017.
//

#include "date.h"

unsigned int date::get_day() const
{
    return _day;
}

void date::set_day(unsigned int _day)
{
    date::_day = _day;
    chesk_the_date();
}

month date::get_month() const
{
    return _month;
}

void date::set_month(month _month)
{
    date::_month = _month;
    chesk_the_date();
}

unsigned int date::get_year() const
{
    return _year;
}

void date::set_year(unsigned int year)
{
    date::_year = year;
    chesk_the_date();
}

date::date(unsigned int _day, month _month, unsigned int _year) : _day(_day), _month(_month), _year(_year)
{
    chesk_the_date();
}

date::date(unsigned int _day, unsigned int _month, unsigned int _year) : date(_day,(month)_month, _year) {}

date::date(std::string _date) : date(
        std::stoi(std::string (_date.begin(),_date.begin() + _date.find('.'))),
        std::stoi(std::string (_date.begin() + _date.find('.') + 1,_date.begin() + _date.rfind('.'))),
        std::stoi(std::string (_date.begin() + _date.rfind('.') + 1, _date.end()))
) {}

bool date::is_it_leap_year() const
{
    if(!(get_year()%400))
        return true;
    if(!(get_year()%100))
        return false;
    if(!(get_year()%4  ))
        return true;
    return false;
}

unsigned int date::get_last_day() const
{
    int result;

    if(get_month() < August)
        if(get_month()%2)
            result = 30;
        else
            result = 31;
    else
        if(get_month()%2)
            result = 31;
        else
            result = 30;

    if(get_month() == February)
        if(is_it_leap_year())
            result = 29;
        else
            result = 28;

    return result;
}

void date::chesk_the_date()
{
    if(get_year() < 100)
        set_year(2000 + get_year());

    if((get_day()!=0) && (get_day() <= get_last_day()))
        if(get_month() <= December)
        {
            _is_wrong_date = false;
            return;
        }
    _is_wrong_date = true;
}

bool date::is_the_date_wrong() const
{
    return _is_wrong_date;
}

std::string date::get_month_as_a_string() const
{
    switch(get_month())
    {
        case January    :
            return "January";
        case February   :
            return "February";
        case March  :
            return "March";
        case April  :
            return "April";
        case May    :
            return "May";
        case June   :
            return "June";
        case July   :
            return "July";
        case August :
            return "August";
        case September  :
            return "September";
        case October    :
            return "October";
        case November   :
            return "November";
        case December   :
            return "December";
        default:
            return "";
    };
}

std::string date::get_short_date_as_a_string() const {
    if(is_the_date_wrong())
        return "";
    else
        return std::to_string(_day) + "." + std::to_string(_month) + "." + std::to_string(_year%100);
}

std::string date::get_full_date_as_a_string() const {
    if(is_the_date_wrong())
        return "";
    else
        return std::to_string(_day) + "." + get_month_as_a_string() + "." + std::to_string(_year);
}

bool date::operator < (const date &right) const
{
    if(get_year() < right.get_year())
        return true;

    if(get_year() == right.get_year())
        if(get_month() < right.get_month())
            return true;

    if(get_year() == right.get_year())
        if(get_month() == right.get_month())
            if(get_day() < right.get_day())
                return true;

    return false;
}

bool date::operator == (const date &right) const
{
    return
            get_year()  == right.get_year() &&
            get_month()  == right.get_month() &&
            get_day() == right.get_day();
}





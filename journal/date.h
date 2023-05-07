//
// Created by Logan on 18.12.2017.
//

#ifndef JOURNAL_DATE_H
#define JOURNAL_DATE_H

#include <string>

enum month
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class date
{
public:
    //Getters & Setters
    unsigned int get_day() const;
    void set_day(unsigned int _day);
    month get_month() const;
    void set_month(month _month);
    unsigned int get_year() const;
    void set_year(unsigned int year);

    // Constructors
    date(unsigned int _day, month _month, unsigned int _year);
    date(unsigned int _day, unsigned int _month, unsigned int _year);
    date(std::string _date);

    //Methods
    bool is_the_date_wrong() const;
    std::string get_month_as_a_string() const;
    std::string get_short_date_as_a_string() const;
    std::string get_full_date_as_a_string() const;

    //Operators
    bool operator <  (const date& right) const;
    bool operator == (const date& right) const;

private:
    unsigned int _day;
    month _month;
    unsigned int _year;
    bool _is_wrong_date;

    //Private methods
    bool is_it_leap_year() const;
    unsigned int get_last_day() const;
    void chesk_the_date();



};


#endif //JOURNAL_DATE_H

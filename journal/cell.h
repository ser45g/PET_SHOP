//
// Created by Logan on 26.12.2017.
//

#ifndef JOURNAL_CELL_H
#define JOURNAL_CELL_H
#include "legend.h"


class cell
{

public:
    // Getters & Setters
    const std::string &get_content() const;
    void set_content(const std::string &_content);
    const date *get_date() const;
    void set_date(const date *_date);
    const legend *get_legend() const;
    void set_legend(const legend *_legend);

    // Constructors
    cell(const std::string &_content, const date *_date, const legend *_legend);
    cell(const date *_date, const legend *_legend);
    cell(const date *_date);

    //Operators
    bool operator <(const cell& right) const;
    bool operator ==(const cell& right) const;

    //Methods
    std::string get_context() const;
    std::string get_context_if_date_is_equal(date _date) const;
    void set_content_if_date_is_equal(date _date, std::string content);
    bool is_call_of_date(date _date) const;


private:
    std::string _content;
    const date* _date;
    const legend* _legend;
};


#endif //JOURNAL_CELL_H

//
// Created by Logan on 26.12.2017.
//

#include "cell.h"

const std::string &cell::get_content() const
{
    return _content;
}

void cell::set_content(const std::string &_content)
{
    cell::_content = _content;
}

const date *cell::get_date() const
{
    return _date;
}

void cell::set_date(const date *_date)
{
    cell::_date = _date;
}

const legend *cell::get_legend() const
{
    return _legend;
}

void cell::set_legend(const legend *_legend)
{
    cell::_legend = _legend;
}

cell::cell(const std::string &_content, const date *_date, const legend *_legend) : _content(_content), _date(_date),
                                                                                    _legend(_legend) {}

cell::cell(const date *_date, const legend *_legend) : cell("+",_date, _legend) {}

cell::cell(const date *_date) : cell(_date, NULL) {}

bool cell::operator<(const cell &right) const
{
    return *get_date() < *right.get_date();
}

bool cell::operator==(const cell &right) const
{
    return *get_date() == *right.get_date();
}

std::string cell::get_context() const
{
    return _legend->get_context(_content);
}

bool cell::is_call_of_date(date _date) const
{
    return _date == *get_date();
}

std::string cell::get_context_if_date_is_equal(date _date) const
{
    if(is_call_of_date(_date))
        return get_content();
    else
        return "";
}

void cell::set_content_if_date_is_equal(date _date, std::string content)
{
    if(is_call_of_date(_date))
        set_content(_content);
}

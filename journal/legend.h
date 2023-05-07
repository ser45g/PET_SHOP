//
// Created by Logan on 18.12.2017.
//

#ifndef JOURNAL_LEGEND_H
#define JOURNAL_LEGEND_H

#include <map>
#include <vector>
#include "date.h"


class legend
{
public:

    //Constructor & Destructor
    legend(const std::string &_file_name);
    virtual ~legend();

    //Methods
    std::vector<std::string> get_legend() const;
    void add_element(std::string key, std::string value);
    void remove_element(std::string key);
    std::string get_context(std::string key) const;

private:
    std::map<std::string, std::string> _tesaurus;
    std::string _file_name;

    //To make this methods unavailiable
    legend(const legend& orig) {}
    legend operator=(const legend& orig) {return *this;}
};


#endif //JOURNAL_LEGEND_H

//
// Created by Logan on 18.12.2017.
//

#include <fstream>
#include "legend.h"

legend::legend(const std::string &_file_name) : _file_name(_file_name)
{
    std::ifstream fin(_file_name);
    if(fin.is_open())
        while (!fin.eof())
        {
            std::string key;
            std::string value;
            fin >> key >> value;
            _tesaurus.insert(std::make_pair(key,value));
        }
}

legend::~legend()
{
    std::ofstream fout(_file_name);
    if(fout.is_open())
    {
        auto last_element_iter = _tesaurus.end();
        last_element_iter--;
        for(auto iter = _tesaurus.cbegin(); iter != _tesaurus.cend(); iter++)
        {
            fout << iter->first << " " << iter->second;
            if(iter != last_element_iter)
                fout << std::endl;
        }
    }
}

std::vector<std::string> legend::get_legend() const {
    std::vector<std::string> result;
    result.reserve(_tesaurus.size());
    for(auto iter = _tesaurus.cbegin(); iter != _tesaurus.cend(); iter++)
        result.push_back(iter->first + " " + iter->second);
    return result;
}

void legend::add_element(std::string key, std::string value)
{
    _tesaurus.insert(std::make_pair(key, value));
}

void legend::remove_element(std::string key)
{
    _tesaurus.erase(key);
}

std::string legend::get_context(std::string key) const {
    std::string result;

    auto iter = _tesaurus.find(key);
    if(iter == _tesaurus.cend())
        result = "no context";
    else
        result = iter->second;

    return result;
}

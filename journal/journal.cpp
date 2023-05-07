//
// Created by Logan on 26.12.2017.
//

#include "journal.h"
#include <fstream>
#include <algorithm>


journal::journal(const std::string &_file_name, const legend* _legend) : _file_name(_file_name), _legend(_legend)
{
    std::ifstream fin(_file_name);
    if(fin.is_open())
    {
        std::string space;
        int raw_number;
        int colum_number;
        fin >> space;
        fin >> space;
        fin >> raw_number;
        fin >> colum_number;

        //reading the dates
        for(int i = 0; i < colum_number; i++)
        {
            std::string str_date;
            fin >> str_date;
            _dates.insert(date(str_date));
        }

        //reading the students
        for(int i = 0; i <raw_number; i++)
        {

            std::string first_name;
            std::string last_name;
            std::string father_name;

            fin >> space;
            fin >> last_name;
            fin >> first_name;
            fin >> father_name;

            std::set<cell> cells;
            //reading cells
            auto iterator = _dates.cbegin();
            for(int j = 0; j < colum_number; j++)
            {
                std::string content;
                fin >> content;
                cells.insert(cell(content,&*iterator,_legend));
                iterator++;
            }
            _students.insert(student(first_name,last_name,father_name,cells));
        }
    }
}

journal::~journal()
{
    std::ofstream fout(_file_name);
    if(fout.is_open())
    {
        fout << "Num FIO " << _students.size() << " " << _dates.size();
        for(auto obj : _dates)
            fout << " " << obj.get_short_date_as_a_string();

        int student_number = 1;
        for(auto obj : _students)
        {
            fout << std::endl << student_number << " " << obj.get_student_as_a_string();
            student_number++;
        }

    }
}

bool journal::deduct_student(std::string full_name)
{
    parse_names(full_name);
    return deduct_student(_tmp_last_name,_tmp_first_name,_tmp_father_name);
}

bool journal::deduct_student(std::string last_name, std::string first_name, std::string father_name)
{
    student etalone(first_name,last_name,father_name);
    if(_students.find(etalone) == _students.end())
        return false;

    _students.erase(etalone);
    return true;
}

void journal::add_student(std::string full_name, std::vector<std::string> student_date_content)
{
    parse_names(full_name);
    add_student(_tmp_last_name,_tmp_first_name,_tmp_father_name,student_date_content);
}

void journal::add_student(std::string last_name, std::string first_name, std::string father_name,
                          std::vector<std::string> student_date_content)
{
    // Take the size to norma
    while(student_date_content.size() > _dates.size())
        student_date_content.pop_back();

    while(student_date_content.size() < _dates.size())
        student_date_content.push_back("+");

    // create new student
    std::set<cell> cells;
    auto iter = _dates.cbegin();
    for(auto obj : student_date_content)
    {
        cells.insert(cell(obj,&*iter,_legend));
                iter++;
    }

    student new_student(first_name,last_name,father_name,cells);
    _students.insert(new_student);
}

bool journal::change_first_name(std::string full_name, std::string new_first_name)
{
    parse_names(full_name);
    return change_first_name(_tmp_last_name, _tmp_first_name, _tmp_father_name, new_first_name);
}

bool journal::change_first_name(std::string last_name, std::string first_name, std::string father_name,
                                std::string new_first_name)
{
    student etalone(first_name, last_name, father_name);
    auto iter = _students.find(etalone);
    if(iter == _students.end())
        return false;

    auto obj = *iter;
    _students.erase(iter);
    obj.set_first_name(new_first_name);
    _students.insert(obj);
    return true;
}

bool journal::change_last_name(std::string full_name, std::string new_last_name)
{
    parse_names(full_name);
    return change_last_name(_tmp_last_name, _tmp_first_name, _tmp_father_name, new_last_name);
}

bool journal::change_last_name(std::string last_name, std::string first_name, std::string father_name,
                               std::string new_last_name)
{
    student etalone(first_name, last_name, father_name);
    auto iter = _students.find(etalone);
    if(iter == _students.end())
        return false;

    auto obj = *iter;
    _students.erase(iter);
    obj.set_last_name(new_last_name);
    _students.insert(obj);
    return true;
}

bool journal::change_father_name(std::string full_name, std::string new_father_name)
{
    parse_names(full_name);
    return change_father_name(_tmp_last_name, _tmp_first_name, _tmp_father_name, new_father_name);
}

bool journal::change_father_name(std::string last_name, std::string first_name, std::string father_name,
                                 std::string new_father_name)
{
    student etalone(first_name, last_name, father_name);
    auto iter = _students.find(etalone);
    if(iter == _students.end())
        return false;

    auto obj = *iter;
    _students.erase(iter);
    obj.set_father_name(new_father_name);
    _students.insert(obj);
    return true;
}

void journal::parse_names(std::string full_name)
{
    _tmp_last_name.assign(full_name.begin(),full_name.begin() + full_name.find(' '));
    _tmp_first_name.assign(full_name.begin() + full_name.find(' ')+1,full_name.begin() + full_name.rfind(' '));
    _tmp_father_name.assign(full_name.begin() + full_name.rfind(' ') + 1,full_name.end());
}

bool journal::erase_date(date _date)
{
    if(_dates.find(_date) == _dates.end())
    return false;

    std::set<student> new_students;
    for(auto iter = _students.begin(); iter != _students.end(); iter++)
    {
        auto obj = *iter;
        obj.erase_cell_with_date(_date);
        new_students.insert(obj);
    }

    _students = new_students;
    _dates.erase(_date);

    return true;
}

bool journal::add_date(date _date)
{
    if(_dates.find(_date) != _dates.end())
        return false;

    _dates.insert(_date);
    std::set<date>::const_iterator date_place = _dates.find(_date);
    std::set<student> new_students;
    for(auto iter = _students.begin(); iter != _students.end(); iter++)
    {
        auto obj = *iter;
        obj.add_cell_with_date(&*date_place, _legend);
        new_students.insert(obj);
    }
    _students = new_students;
    return true;
}


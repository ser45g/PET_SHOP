#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class product
{
public:
    product() {}
    product(string _name, string _factory, int _amount, double _price, int _expiration_date) :
        _name(_name), _factory(_factory), _amount(_amount), _price(_price), _expiration_date(_expiration_date) {}
    product(const map<string, string>& _data) :
        product
        (
            _data.find("name") == _data.end() ? "product" : _data.find("name")->second,
            _data.find("factory") == _data.end() ? "factory" : _data.find("factory")->second,
            stoi(_data.find("amount") == _data.end() ? "0" : _data.find("amount")->second),
            stod(_data.find("price") == _data.end() ? "0" : _data.find("price")->second),
            stoi(_data.find("expiration_date") == _data.end() ? "0" : _data.find("expiration_date")->second)

        ) {}

    virtual string type() const = 0;

    virtual string review() const
    {
        return type() + ": " + _name + ". �������������: " + _factory + ". ����������: " + to_string(_amount) + ". ����: " + to_string(_price) + ". ���� ��������: " + to_string(_expiration_date) + " ����";
    }

private:
    string _name;
    string _factory;
    int _amount;
    double _price;
    int _expiration_date;


};

class vino : public product
{
public:
    vino(string _name, string _factory, int _amount, double _price, int _expiration_date) : product(_name, _factory, _amount, _price, _expiration_date) {}
    vino(const map<string, string>& _data) : product(_data),
        color(_data.find("color") == _data.end() ? true : (_data.find("color")->second == "white" ? false : true)) {}
    string type() const { return "����"; }

    virtual string review() const
    {
        return string(color ? "�������" : "�����") + " " + product::review();
    }

private:
    bool color;

};

class lobsters : public product
{
public:
    lobsters(string _name, string _factory, int _amount, double _price, int _expiration_date) : product(_name, _factory, _amount, _price, _expiration_date) {}

    string type() const { return "�������"; }

};

class bread : public product
{
public:
    bread(string _name, string _factory, int _amount, double _price, int _expiration_date) : product(_name, _factory, _amount, _price, _expiration_date) {}

    string type() const { return "����"; }

};

int main()
{
    map<string, string> _data;
    _data.insert(make_pair("name", "tendida"));
    _data.insert(make_pair("amount", "50"));
    _data.insert(make_pair("price", "400"));
    _data.insert(make_pair("color", "white"));


    vino _vino(_data);
    product& _new_product = _vino;

    cout << _new_product.review();



    return 0;
}



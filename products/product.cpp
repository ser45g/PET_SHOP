#pragma once
#include "ID.cpp"
#include <string>
#include <sstream>
//#include <strstream>

class product {
private:
    ID _id;
    double _price = 0;
public:
    product(ID id, double price = 0) : _id(id), _price(price) {   }

    void set_price(double price) { _price = price; }
    double get_price()const { return _price; }
    ID get_id() const { return _id; }

    virtual std::string to_string() const noexcept {
        std::stringstream strstr;
        strstr << int(_id) << ' ' << _price << ' ';
        return strstr.str();
    }

    virtual ~product() {}

    virtual bool operator==(const product& pr) const noexcept {
        return to_string() == pr.to_string();
    }
    //friend bool operator==(const product& pr1, const product& pr2) {
    //    return ((pr1.get_id() == pr2.get_id()) and (pr1.get_price() == pr2.get_price())) ? true : false;
    //
    //}
};

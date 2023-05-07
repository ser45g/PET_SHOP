#pragma once
#include"product.cpp"

class fish : public product {
private:
    std::string _color;
    std::string _breed;
public:
    fish(double price, std::string color, std::string breed) :_color(color),
        _breed(breed), product(ID::FISH, price) { }

    fish(const std::string& str) :product(ID::FISH) {
        std::stringstream strstr(str);
        int id;
        double price;
        strstr >> id >> price;
        product::set_price(price);
        strstr >> _color;
        strstr >> _breed;
    }
    std::string to_string() const noexcept {

        std::stringstream strstr;
        strstr << _color << ' ' << _breed << ' ';
        return product::to_string() + strstr.str();
    }
    //bool operator==(const fish& pr)const noexcept {
    //    return (product::operator==(pr) and
    //        (_color == pr._color) and (_breed == pr._breed)) ? true : false;
    //}

};
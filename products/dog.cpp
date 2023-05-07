#pragma once
#include"product.cpp"

class dog : public product {
private:
    std::string _nickname;
    std::string _breed;
public:
    dog(double price, std::string nickname, std::string breed) :_nickname(nickname),
        _breed(breed), product(ID::DOG, price) { }

    dog(const std::string& str) :product(ID::DOG) {
        std::stringstream strstr(str);
        int id;
        double price;
        strstr >>id>> price;
        product::set_price(price);
        strstr >> _nickname;
        strstr >> _breed;
    }
    std::string to_string() const noexcept {

        std::stringstream strstr;
        strstr << _nickname << ' ' << _breed << ' ';
        return product::to_string() + strstr.str();
    }
    //bool operator==(const dog& pr)const noexcept {
    //    return (product::operator==(pr) and
    //        (_nickname == pr._nickname) and (_breed == pr._breed)) ? true : false;
    //}

};
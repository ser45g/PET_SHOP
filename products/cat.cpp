#pragma once
#include"product.cpp"

class cat : public product {
private:
    std::string _nickname;
public:
    cat(double price, std::string nickname) :_nickname(nickname), product(ID::CAT, price) { }

    cat(const std::string& str) :product(ID::CAT) {
        std::stringstream strstr(str);
        int id;
        double price;
        strstr >> id >> price;
        product::set_price(price);
        strstr >> _nickname;
    }

    std::string get_nickname() const {
        return _nickname;
    }
    std::string to_string() const noexcept {

        std::stringstream strstr;
        strstr << _nickname ;
        return product::to_string() + strstr.str();
    }
    //bool operator==(const cat& pr) const noexcept {
    //    
    //}
};

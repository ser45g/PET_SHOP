#pragma once
#include"product.cpp"

class aqaurium : public product {
private:
    double volume_m3 = 0;
public:
    aqaurium(double price, double volume_m3) :volume_m3(volume_m3), product(ID::ACQUAIRIUM, price) { }

    aqaurium(const std::string& str) :product(ID::ACQUAIRIUM) {
        std::stringstream strstr(str);
        int id;
        double price;
        strstr >> id >> price;
        product::set_price(price);
        strstr >> volume_m3;
    }

    std::string to_string() const noexcept {

        std::stringstream strstr;
        strstr << volume_m3 << ' ';
        return product::to_string() + strstr.str();
    }
    //bool operator==(const aqaurium& pr)const noexcept {
    //    return (product::operator==(pr) and
    //        (volume_m3== pr.volume_m3) ) ? true : false;
    //}

};
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//
//#include "fabric.cpp"
//#include "loaders.cpp"
//#include "product.cpp"
//#include "cat.cpp"
//#include "dog.cpp"
//#include "aqaurium.cpp"
//#include "fish.cpp"
//

#include "PET_SHOP.cpp"
#include "Control.cpp"


//only three first letters
#pragma once
#include <unordered_map>
enum class ID { CAT = 1, DOG, ACQUAIRIUM, FISH };

std::unordered_map<ID, std::string> ClassNames{
    std::pair<ID, std::string>(ID::CAT, "cat price name"),
    std::pair<ID, std::string>(ID::DOG, "dog price name breed"),
    std::pair<ID, std::string>(ID::FISH, "fis price color breed"),
    std::pair<ID, std::string>(ID::ACQUAIRIUM, "acq price volume m^3")
};

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
        strstr >> id >> price;
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
        strstr << _nickname;
        return product::to_string() + strstr.str();
    }
    //bool operator==(const cat& pr) const noexcept {
    //    
    //}
};

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

void RegisterProducts(GenericObjectFactory<ID,product>* gen) {
    gen->add<cat>(ID::CAT);
    gen->add<dog>(ID::DOG);
    gen->add<aqaurium>(ID::ACQUAIRIUM);
    gen->add<fish>(ID::FISH);
}





int main() {
    using std::string;
    using std::cout;
    using std::cin;

    pet_shop<product> shop;
    GenericObjectFactory<ID, product> gen;
    Control<std::ostream, std::istream> control(cout, cin, &shop, &gen);

    RegisterProducts(&gen);


    text_downloader<product ,GenericObjectFactory<ID, product> > download("prices.txt", &gen );
    text_uploader upload("prices.txt");
    
    for (auto el : download.load()) {
        shop.add(el);
    }

    int input=-1;
    char ch = ' ';
    control.DrawMenu();
    cout << "0 -- terminate the program\n";

    while (true) {
        cin >> input;
        if (input == 0)
            break;
        control.HandleInput(CommandID(input));
        cout << "Draw Menu? (yes - space)";
        cin >> ch;
        if (ch == ' ') {
            control.DrawMenu();
            cout << "0 -- terminate the program\n";
        }
    }
    
    upload.upload(shop.content_to_string());
    return 0;
    }




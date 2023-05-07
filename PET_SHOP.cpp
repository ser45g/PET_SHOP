#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include "product.cpp"

template <typename product>
class pet_shop {
private:
    std::list<product* > content;
    long long _amount_of_products = 0;
    double _money = 0;
public:
    void add(product* newprod) {
        content.push_back(newprod);
        ++_amount_of_products;
    }


    product* find_product(ID id) {
        auto it = find_if(content.begin(), content.end(), [id](product* pr) {return pr->get_id() == id; });
        return it != content.end() ? *it : nullptr;
    }
    //template<typename Derived>
    product* find_exact_product(const product& pr) {
        auto it = find_if(content.begin(), content.end(), [&pr](product* p) {
            //std::cout << pr.to_string() << " **** " << p->to_string()<<"\n";
            return ((pr.to_string())==(p->to_string())); 
            });
        return it != content.end() ? *it : nullptr;
    }

    bool remove_item(product* prod) {
        //auto it = find_exact_product(pr);
        //auto it = find(content.begin(), content.end(), prod);
        if (prod != nullptr) {
            content.erase(find(content.begin(), content.end(), prod));
            return true;
        }
        return false;
    }

    bool sell_product(product* prod){
        //product* prod = find_exact_product(*pr);
        if (prod != nullptr) {
            _money += prod->get_price();
            --_amount_of_products;
            remove_item(prod);
            return true;
        }
        return false;
    }

    const std::list<product*>& get_content() const noexcept{
        return content;
    }
    double get_money()const {
        return _money;
    }
    int get_amount_of_products()const noexcept{
        return _amount_of_products;
    }
    void set_money(double money) noexcept {
        _money = money;
    }
    
    void set_amount_of_products(int amount)noexcept {
        _amount_of_products = amount;
    }

    std::vector<std::string> content_to_string() const noexcept {
        std::vector<std::string> temp;
        for (auto el : content) {
            temp.push_back(el->to_string());
        }
        return temp;
    }

    void erase(product* prod) {
        auto it = find(content.begin(), content.end(), prod);
        if (it != content.end())
            content.erase(it);
    }


    void clear() {
        for (auto el : content) {
            delete el;
        }
    }
    ~pet_shop() { clear(); }
};









/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<map>
#include <sstream>
#include <strstream>

enum class ID { CAT, DOG, ACQUAIRIUM };
//double _weight = 0;
   //double _shelf_life = 0;
   //std::string _name_for_sale;
   //static unsigned int _count;

// double price()const { return _price; }

     //double weight()const { return _weight; }

     //double shelf_life() const { return _shelf_life; }

     //friend std::ostream& operator <<(std::ostream & c, const product & pr) {
     //    c << pr._price << ' ' << pr._weight << ' ' << pr._shelf_life << pr._name_for_sale;
     //}
//unsigned int product::_count = 0;

class product;




class pet_shop {
private:
    std::list<product* > content;
    //factory* _fact;
public:
    void add(product* newprod) {
        content.push_back(newprod);
    }

    void erase(std::list<product* >::const_iterator it) {
        content.erase(it);
    }

    //template <typename T>
    //std::shared_ptr<product*> find_animal() {
    //    std::find_if(content.begin(), content.end(), [](auto x) {});
    //}

    bool save() const {

    }

    void clear() {
        content.clear();
    }
};

//class factory {
//private:
//    
//public:
//    product* create(const std::string& str) const {
//        
//    }
//    
//};


class factory {
private:
    factory* _next;
public:
    ~factory() { delete _next; }
    factory() : _next(nullptr) {}
    virtual bool is_mine(ID id) const = 0;

    virtual  product* create(const std::string& str) const = 0;
    //virtual int create(const std::string& str) const = 0;

    void push_back(factory* const fact) {
        if (_next) {
            _next->push_back(fact);
        }
        else {
            _next = fact;
        }
    }

    bool erase(ID id) {
        if (_next->is_mine(id)) {
            factory* tmp = _next;
            _next = _next->_next;
            tmp->_next = NULL;
            delete tmp;
            return true;
        }
        else
            return _next->erase(id);
        return false;
    }
};

template <typename T, typename... Args>
class available_products : public available_products<Args...> {
public:
    available_products() {
        this->push_back(new T);
    }
};

template <typename T>
class available_products<T> :public factory {
public:
    available_products() {
        this->push_back(new T);
    }

    bool is_mine(ID id) const override { return false; }

    product* create(const std::string&) const override {
        return nullptr;
    }
};

class product :public factory {
private:
    ID _id;
    double _price = 0;
public:
    product( ID id, double price) : _id(id),  _price(price){   }
    product() {}
    ID get_id() const { return _id; }

    bool is_mine(ID id)const override final {
        return get_id() == id;
    }
    //virtual bool is_mine(ID id) const override = 0;
    product* create(const std::string& str) {
        std::stringstream is(str);
        product* pr;
        int i;
        is >> i;
        pr->_id = ID(i);

        
        
    }
    virtual ~product() {}


};

//class aquairium : public product {
//private:
//    double _volume;
//public:
//    aquairium(double price, double volume) :_volume(volume), product(price, ID::ACQUAIRIUM) { }
//    aquairium():aquairium(0,0){}
//    
//    product* create(const std::string& str)  const override {
//        std::istringstream is(str);
//    }
//};


class cat : public product {
private:
    std::string _nickname;
public:
    cat(double price, std::string nickname) :_nickname(nickname), product(price, ID::CAT) { }

    product* create(const std::string& str)  const override {

    }
};

class dog : public product {
private:
    std::string _nickname;
    std::string _breed;
public:
    dog(double price, std::string nickname, std::string breed) :_nickname(nickname),
        _breed(breed), product(price, ID::DOG) { }

    product* create(const std::string& str)  const override {
        std::istringstream is(str);
        

};



//std::string _path;
    //pet_shop* _shop;
    //factory* _fact;

class loader {
private:
    std::string _path;
public:
    loader(std::string path): _path(path) {}
    const std::list<product*> load() {
        std::fstream f(_path);
        std::string temp;
        available_products<cat, dog, aquairium> _fact;
        std::list<product*> cont;
        if (f.good()) {
            while (!f.eof()) {
                std::getline(f, temp);
                if (temp == "")
                    continue;
                cont.push_back(_fact.create(temp));
            }
        }
        return cont;
    }
};

int main() {
    using std::string;
    using std::cout;
    using std::cin;
   
    pet_shop pet;
    loader l("prices.txt");
    for (auto el : l.load()) {
        pet.add(el);
    }
    char choice;
    do
    {
        cout << "Welcome to our petsop system! You have some options here:\n";
        cout << " 1 - add an animal\n";
        cout << " 2 - remove an animal\n";
        cout << " 3 - sell an animal\n";
        cout << " 4 - log the sum of money in out store\n";
        //Programm menue

        switch (choice) {
        case '1': 
            break;
        case '2': 
            break;
        case '3': 
            break;
        case '4':
            break;
        }
        while (true)
        {
            cout << '\n' << "Do you want to leave the programm? [Y/N]:";
            cin >> choice;
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                break;
            cout << "Unrecognized ansver! Try agan please!";
        }
    } while (choice == 'n' || choice == 'N');
    return 0;
}



*/
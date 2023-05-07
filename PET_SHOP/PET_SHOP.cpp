#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<map>

enum class ID { CAT,DOG,ACQUAIRIUM };
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
    factory(): _next(nullptr){}
    virtual bool is_mine(ID id) const = 0;

    virtual product* create(const std::string& str) const = 0;
    //virtual int create(const std::string& str) const = 0;

    void push_back( factory* const fact) {
        if (_next) {
            _next->push_back(fact);
        } else {
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
class producato : public producato<Args...> {
    producato() {
        this->push_back(new T);
    }
};

template <typename T>
class producato<T> :public factory {
    producato() {
        this->push_back(new T);
    }
};

class product :public factory {
private:
    double _price = 0;
    ID _id;
public:
    product(double price, ID id) : _price(price), _id(id) {   }
    //virtual bool is_mine(ID id) const override = 0;
    //virtual product* create()
    virtual ~product() {}


};

class aquairium : public product {
private:
    double _volume;
public:
    aquairium(double price, double volume) :_volume(volume), product(price, ID::ACQUAIRIUM) { }
    bool is_mine(ID id)const override {

    }
    //virtual product const* create(const std::string& str) const = 0;

    product* create(const std::string& str)  const override {

    }
};


class cat : public product {
private:
    std::string _nickname;
public:
    cat(double price, std::string nickname) :_nickname(nickname), product(price, ID::CAT) { }
};

class dog : public product {
private:
    std::string _nickname;
    std::string _breed;
public:
    dog(double price, std::string nickname, std::string breed) :_nickname(nickname),
        _breed(breed), product(price, ID::DOG) { }

};




class loader {
private:
    std::string _path;
    pet_shop* _shop;
    factory* _fact;
public:
    loader(std::string path): _path(path) {
        std::fstream f(path);
        std::string temp;
        if (f.good()) {
            while (!f.eof()) {
                std::getline(f, temp);
                _shop->add(_fact->create(temp));
            }
        }
    }
};

int main() {
    return 0;
}

//template <typename T>
//product* register_product(const std::map<std::string, std::string>& _data) {
//    return new T(_data);
//}



#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace  std;

enum ID{SOAP=1,BUCKET,TOOTHPASTE};

class Products
{
public:
    //Constructor
    Products(ID id, int price, int amount, const string& name ) :Id(id), Price(price),
        Amount(amount), Name(name) {}
    Products() {}

    //Getters
    int getPrice() const { return Price; }
    int getAmount() const { return Amount; }

    void setAmount(int amount) {
        Amount = amount;
    }
    const string& getName() const { return Name; }
    ID getID() const { return Id; }

    virtual string Presentation() const
    {
        return
            //"Id = " + to_string(Id) + ". " +
            "Price = " + to_string(getPrice()) + ". " +
            "Amount =" + to_string(getAmount()) + ". " +
            "Name =" + getName() + ".";
    }
    virtual bool operator==(const Products& pr) {
        if (Id == pr.Id and Price == pr.Price and Name == pr.Name)
            return true;
        return false;
    }
private:
    ID Id;
    int Price;
    int Amount;
    string Name;
};


class Soap : public Products
{
public:
    //Constructor
    Soap(int price, int amount, const string& name, int expiryDateInDays, int weightInGram) :
        Products(ID::SOAP,price, amount, name ), ExpiryDateInDays(expiryDateInDays), WeightInGram(weightInGram) {}

    string Presentation() const
    {
        return Products::Presentation() +
            "ExpiryDateInDays = " + to_string(ExpiryDateInDays) + ". " +
            "WeightInKilograms = " + to_string(WeightInGram) + ". ";
    }

private:
    int ExpiryDateInDays;
    int WeightInGram;
};


class Bucket : public Products
{
public:
    Bucket(int price, int amount, const string& name, const string& material, int numberOfLiters) :
        Products(ID::BUCKET,price, amount, name), Material(material), NumberOfLiters(numberOfLiters) {}

    string Presentation() const
    {
        return Products::Presentation() +
            "NumberOfLiters = " + to_string(NumberOfLiters) + ". " +
            "Material = " + Material + ". ";
    }

private:
    string Material;
    int NumberOfLiters;
};


class Toothpaste : public Products
{
public:
    Toothpaste(int price, int amount, const string& name, const string& color, const string& brand, int weightInGram) :
        Products(ID::TOOTHPASTE,price, amount, name ), Color(color), Brand(brand), WeightInGram(weightInGram) {}

    string Presentation() const
    {
        return Products::Presentation() +
            "Color = " + Color + ". " +
            "Brand = " + Brand + ". "
            "WeightInGram = " + to_string(WeightInGram) + ". ";
    }

private:
    string Color;
    string Brand;
    int WeightInGram;
};
class fabric {
public:
    Products* create(const Products& _product) {
        switch (_product.getID()) {

        }
    }
};

class Shop
{
public:
    Shop() {}
    
    bool add_product(const Products& _product)
    {
        auto it = find_product(_product);
        if (it != nullptr) {
            it->setAmount(it->getAmount() + _product.getAmount());
            return true;
        } 
        
        return false;
    }
    void register_product(Products* prod) {
    
    }

    Products* find_product(const Products& _product) {
        auto it = find_if(_products.begin(), _products.end(), [_product](Products* pr) {
            return *pr==_product; });
        return it != _products.end() ? *it : nullptr;
    }

    bool remove_item(const Products& _product) {
        auto it = find_product(_product);
        if (it != nullptr and it->getAmount() - _product.getAmount()>=0) {
            it->setAmount(it->getAmount() - _product.getAmount());
            return true;
        }
        return false;
    }

    bool sell_product(const Products& _product) {
        bool temp = remove_item(_product);
        if (temp) {
            _money += _product.getPrice() * _product.getAmount();
        }
        return false;
    }
    const list<Products*>& getContent() const {
        return _products;
    }
    double getMoney()const {
        return _money;
    }
    int getAmount()const {
        return _amount_of_products;
    }
    //Правило 3 в С++
    Shop(const Shop& _argument) = delete;
    const Shop& operator=(const Shop& _argument) = delete;
    ~Shop() {
        for (auto el : _products) {
            delete el;
        }
    }

private:
    list<Products*> _products;
    double _money = 0;
    int _amount_of_products = 0;
};


int main()
{
    Shop shop;
    Products*s=new Soap (10, 230, "dove", 100, 2);
    Products*t1=new Toothpaste (100, 2, "paste", "white", "lospollos", 50);
    Products*t2=new Toothpaste (200, 4, "clean_teeth", "pink", "CT.company", 70);
    Products*b=new Bucket (300, 1, "simple_bucket", "steel", 10);
    shop.register_product(t1);
    shop.register_product(t2);
    shop.register_product(b);
    shop.register_product(s);
    //shared_ptr<Soap> jed(&p);

    cout << "shop money = " << shop.getMoney() << '\n';

    shop.sell_product(Toothpaste (200, 2, "clean_teeth", "pink", "CT.company", 70));
    cout << "shop money = " << shop.getMoney() << '\n';

    cout << "       CONTENT:\n";
    for (auto el : shop.getContent()) {
        cout << el->Presentation() << '\n';
    }
    shop.add_product(Soap(10, 20, "dove", 100, 2));
    cout << "shop money = "<<shop.getMoney() << '\n';
    cout << "the amount of items = "<<shop.getAmount() << '\n';
    cout << "       CONTENT:\n";
    for (auto el : shop.getContent()) {
        cout << el->Presentation()<<'\n';
    }

    //shop.add_product(new Soap())
    //char choice;
    //do
    //{
    //    cout << "Welcome to our petsop system! You have some options here:\n";
    //    cout << " 1 - add a product to our storage\n";
    //    cout << " 2 - remove a product from our storage\n";
    //    cout << " 3 - sell a product\n";
    //    cout << " 4 - log the sum of money\n";
    //    cout << " 5 - log the content";
    //    //Programm menue
    //
    //    switch (choice) {
    //    case '1':
    //        cout << "What product do you want to add to the store?\n";
    //        cout << "1 - soap\n";
    //        cout << "2 - bucket\n";
    //        cout << "3- toothpaste\n";
    //        char answer;
    //        cin >> answer;
    //        Products* prod;
    //        switch (answer) {
    //        case '1':
    //            cout << "log the attributes\n";
    //
    //            shop.add_product()
    //            break;
    //        case '2':
    //            break;
    //        case '3':
    //            break;
    //        }
    //        break;
    //    case '2':
    //        break;
    //    case '3':
    //        break;
    //    case '4':
    //        break;
    //    }
    //    while (true)
    //    {
    //        cout << '\n' << "Do you want to leave the programm? [Y/N]:";
    //        cin >> choice;
    //        if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
    //            break;
    //        cout << "Unrecognizable answer! Try again, please!";
    //    }
    //} while (choice == 'n' || choice == 'N');
    return 0;
}

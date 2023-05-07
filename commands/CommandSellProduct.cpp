#pragma once
#include "OutputCommand.cpp"
#include "CommandShowContent.cpp"

template <typename Output, typename Input>
class CommandSellProduct : public OutputCommand<Output, Input> {
private:
public:
    using OutputCommand<Output, Input>::OutputCommand;
    using Base = OutputCommand<Output, Input>;

    void Execute() const override {
        OutputCommand<Output, Input>::get_output() << "Sell a product - What product would you like to choose?\n" <<
            "(write all the atributes)\n\n";
        std::string input;
        CommandShowContent<Output, Input>(Base::get_output(), Base::get_input(),
            Base::get_shop(), Base::get_fabric()).Execute();

        std::getline(Base::get_input() >> std::ws, input);
        int it = input.find(' ');
        int id = std::stoi(input.substr(0, it));
        product* temp = Base::get_fabric()->get(ID(id))(input);
        bool rem = Base::get_shop()->
            remove_item(Base::get_shop()->find_exact_product(*temp));
        Base::get_shop()->set_money(Base::get_shop()->get_money() + rem ? temp->get_price() : 0);
        Base::get_output() << (rem ? "The product is sold from the shop succesfully\n" :
            "There's no such product");
        delete temp;

    }
    std::string info() const noexcept override {
        return "sell a product";
    }
};

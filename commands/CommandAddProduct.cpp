#pragma once

#include "OutputCommand.cpp"

template <typename Output, typename Input>
class CommandAddProduct : public OutputCommand<Output, Input> {
private:
public:
    using OutputCommand<Output, Input>::OutputCommand;
    using Base = OutputCommand<Output, Input>;

    void Execute() const override {
        OutputCommand<Output, Input>::get_output() << "Add a product - What product would you like to choose?\n" <<
            "(write all the atributes)\n";
        std::string input;

        for (std::pair<ID, std::string> p : ClassNames) {
            OutputCommand<Output, Input>::get_output() <<
                p.second.substr(0, 3)
                << '(' << int(p.first) << ')' << ' ' << p.second.substr(4) << '\n';
        }
        //Base::get_output().flush();
        std::getline(OutputCommand<Output, Input>::get_input() >> std::ws, input);
        int it = input.find(' ');
        int id = std::stoi(input.substr(0, it));
        OutputCommand<Output, Input>::get_shop()->
            add(OutputCommand<Output, Input>::get_fabric()->get(ID(id))(input));
        OutputCommand<Output, Input>::get_output() << "The product is added to the shop succesfully\n";

    }

    std::string info() const noexcept override {
        return "add a product";
    }
};

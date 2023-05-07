#pragma once
#include "OutputCommand.cpp"


template <typename Output, typename Input>
class CommandShowAmount : public OutputCommand<Output, Input> {
private:
public:
    using OutputCommand<Output, Input>::OutputCommand;
    using Base = OutputCommand<Output, Input>;

    void Execute() const override {
        Base::get_output() << "The amount of products = " << Base::get_shop()->get_amount_of_products() << "\n";
    }
    std::string info() const noexcept override {
        return "show the amount of products";
    }
};

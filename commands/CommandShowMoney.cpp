#pragma once
#include "OutputCommand.cpp"


template <typename Output, typename Input>
class CommandShowMoney : public OutputCommand<Output, Input> {
private:
public:
    using OutputCommand<Output, Input>::OutputCommand;
    using Base = OutputCommand<Output, Input>;

    void Execute() const override {
        Base::get_output() << "Show money = " << Base::get_shop()->get_money() << "rubles\n";
    }
    std::string info() const noexcept override {
        return "show the amount of money";
    }
};
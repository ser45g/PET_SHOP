
#pragma once
#include "OutputCommand.cpp"


template <typename Output, typename Input>
class CommandShowContent : public OutputCommand<Output, Input> {
private:
public:
    using OutputCommand<Output, Input>::OutputCommand;
    using Base = OutputCommand<Output, Input>;

    void Execute() const override {

        Base::get_output() << "Show the content of this shop:\n";

        for (std::pair<ID, std::string> p : ClassNames) {
            OutputCommand<Output, Input>::get_output() <<
                p.second.substr(0, 3)
                << '(' << int(p.first) << ')' << ' ' << p.second.substr(4) << '\n';
        }
        Base::get_output() << "\n\n";
        for (auto& el : Base::get_shop()->content_to_string()) {
            Base::get_output() << el << '\n';
        }
    }
    std::string info() const noexcept override {
        return "show the content of the store";
    }
};
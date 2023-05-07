#pragma once
#include "PET_SHOP.cpp"
#include "fabric.cpp"
#include <unordered_map>
#include "CommandID.cpp"
#include "OutputCommand.cpp"

#include "CommandAddProduct.cpp"
#include "CommandRemoveProduct.cpp"
#include "CommandSellProduct.cpp"
#include "CommandShowContent.cpp"
#include "CommandShowMoney.cpp"
#include "CommandShowAmount.cpp"

template <typename Output, typename Input>
class Control {
private:
    Output& _out;
    Input& _in;
    pet_shop<product>* _shop;
    GenericObjectFactory<ID, product>* _gen;
    std::unordered_map<CommandID,
        OutputCommand<Output, Input>*> commands;
public:
    Control(Output& out, Input& in,
        pet_shop<product>* shop, GenericObjectFactory<ID, product>* gen) :_out(out),
        _in(in), _shop(shop), _gen(gen) {
        RegisterCommands();
    }

    Output& get_output()const noexcept { return _out; }
    Input& get_input()const noexcept { return _in; }
    pet_shop<product>* get_shop()const noexcept { return _shop; }
    GenericObjectFactory<ID, product>* get_fabric() const noexcept { return _gen; }

    void HandleInput(CommandID input) {
        auto it = commands.find(input);
        if (it != commands.end()) {
            commands[input]->Execute();
        }
    }
    void DrawMenu() {
        _out << " YOU HAVE THESE OPTIONS:\n";
        for (auto& el : commands) {
            _out << int(el.first) << " -- " << el.second->info() << '\n';
        }
    }

    void RegisterCommands() {
        commands[CommandID::ShowContent] = new CommandShowContent<Output, Input>(_out, _in, _shop, _gen);
        commands[CommandID::AddProduct] = new CommandAddProduct<Output, Input>(_out, _in, _shop, _gen);
        commands[CommandID::RemoveProduct] = new CommandRemoveProduct<Output, Input>(_out, _in, _shop, _gen);
        commands[CommandID::ShowMoney] = new CommandShowMoney<Output, Input>(_out, _in, _shop, _gen);
        commands[CommandID::ShowAmount] = new CommandShowAmount<Output, Input>(_out, _in, _shop, _gen);
        commands[CommandID::SellProduct] = new CommandSellProduct<Output, Input>(_out, _in, _shop, _gen);
    }
};

#pragma once

#include "PET_SHOP.cpp"
#include "fabric.cpp"


template <typename Output, typename Input>
class OutputCommand {
private:
    Output& _out;
    Input& _in;
    pet_shop<product>* _shop;
    GenericObjectFactory<ID, product>* _gen;
public:

    Output& get_output()const noexcept { return _out; }
    Input& get_input()const noexcept { return _in; }
    pet_shop<product>* get_shop()const noexcept { return _shop; }
    GenericObjectFactory<ID, product>* get_fabric() const noexcept { return _gen; }
    OutputCommand(Output& out, Input& in,
        pet_shop<product>* shop, GenericObjectFactory<ID, product>* gen) :_out(out),
        _in(in), _shop(shop), _gen(gen) {}
    virtual void Execute() const = 0;
    virtual std::string info() const noexcept = 0;
};
#pragma once
#include <string>
#include <unordered_map>

template<class ID, class Base >
class GenericObjectFactory {
private:
    typedef Base* (*funk)(const std::string&);

    template<class Derived>
    static Base* instantiator(const std::string& str) {
        return new Derived(str);
    }
    std::unordered_map<ID, funk> classes;

public:
    GenericObjectFactory() {}
    template<class Derived>
    void add(ID id) {
        classes[id] = instantiator<Derived>;
    }
    funk get(ID id) {
        return classes[id];
    }
};

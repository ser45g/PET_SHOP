//
// Created by Logan on 01.03.2018.
//

#ifndef UNTITLED9_UNARY_OPERATION_CHAIN_H
#define UNTITLED9_UNARY_OPERATION_CHAIN_H

#include <string>

class unary_operation_chain
{
public:
    //Constructor & Destructor
    unary_operation_chain();
    ~unary_operation_chain();


    //public methods
    double calculate(std::string _binary_operation, double value) const;
    void push_back(unary_operation_chain* _chain);
    bool remove(std::string _binary_operation);



protected:
    virtual bool is_mine(std::string _binary_operation) const = 0;
    virtual double answer_request(double value) const = 0;
    double default_answer() const;

private:
unary_operation_chain* _next;
};

template <typename TYPE, typename ... OTHERS>
class unary_operation : public unary_operation<OTHERS...>
{
public:
    unary_operation()
    {
        this->push_back(new TYPE);
    }
};

template <typename TYPE>
class unary_operation<TYPE> : public unary_operation_chain
{
public:
    unary_operation()
    {
        this->push_back(new TYPE);
    }

protected:
    bool is_mine(std::string _binary_operation) const {
        return false;
    }

    double answer_request(double value) const {
        return default_answer();
    }
};

#endif //UNTITLED9_UNARY_OPERATION_CHAIN_H

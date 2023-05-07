//
// Created by Logan on 02.03.2018.
//

#ifndef UNTITLED9_MATHIMATICLE_CLASS_H
#define UNTITLED9_MATHIMATICLE_CLASS_H

#endif //UNTITLED9_MATHIMATICLE_CLASS_H

#include "unary_operation_chain.h"
#include <math.h>


class sin_unary_operation_chain : public unary_operation_chain
{
protected:
    bool is_mine(std::string _binary_operation) const
    {
        return _binary_operation == "sin";
    }
    double answer_request(double value) const
    {
        return sin(value);
    }
};

class cos_unary_operation_chain : public unary_operation_chain
{
protected:
    bool is_mine(std::string _binary_operation) const
    {
        return _binary_operation == "cos";
    }
    double answer_request(double value) const
    {
        return cos(value);
    }
};

class tan_unary_operation_chain : public unary_operation_chain
{
protected:
    bool is_mine(std::string _binary_operation) const
    {
        return _binary_operation == "tan";
    }
    double answer_request(double value) const
    {
        return tan(value);
    }
};

class ctan_unary_operation_chain : public unary_operation_chain
{
protected:
    bool is_mine(std::string _binary_operation) const
    {
        return _binary_operation == "ctan";
    }

    double answer_request(double value) const
    {
        return 1.0/tan(value);
    }
};

class log_unary_operation_chain : public unary_operation_chain
{
public:
    log_unary_operation_chain(int _base) : _name(std::string("log") + std::to_string(_base)), _base(_base) {}
    log_unary_operation_chain() : _name("ln"), _base(exp(1)) {}

protected:
    bool is_mine(std::string _binary_operation) const
    {
        return _binary_operation == _name;
    }

    double answer_request(double value) const
    {
        return log(value)/log(_base);
    }

private:
    std::string _name;
    double _base;
};

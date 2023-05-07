d//
// Created by Logan on 01.03.2018.
//

#include "unary_operation_chain.h"
#include <iostream>

double unary_operation_chain::default_answer() const
{
    std::cout<<std::endl << " Urecognized function " << std::endl;
    return 0;
}

double  unary_operation_chain::calculate(std::string _binary_operation, double value) const
{
    if(is_mine(_binary_operation))
        return answer_request(value);
    if(_next)
        return _next->calculate(_binary_operation, value);
    else
        return default_answer();
}

unary_operation_chain::unary_operation_chain()
{
    _next = NULL;
}

unary_operation_chain::~unary_operation_chain()
{
    delete _next;
}

void unary_operation_chain::push_back(unary_operation_chain *_chain)
{
    if(_next)
        _next->push_back(_chain);
    else
        _next = _chain;
}

bool unary_operation_chain::remove(std::string _binary_operation)
{
    if(_next)
        if(_next->is_mine(_binary_operation))
        {
            auto tmp = _next;
            _next = _next->_next;
            tmp->_next = NULL;
            delete tmp;
            return true;
        }
    else
            return _next->remove(_binary_operation);
    else
        return false;
}

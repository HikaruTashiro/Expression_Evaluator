#include "../../headers/nodes/Func.hpp"
#include <memory>
#include "../../Config.hpp"
#ifdef DEBUG_NODE
#include <iostream>
#endif


// Works for Unary and Binary, kind of stupid.
// When using Unary, the first expression is used
Func::Func(Token* op, std::shared_ptr<Expr> expr1, std::shared_ptr<Expr> expr2) : 
                                expression1(expr1), expression2(expr2)
{
    tok = op;
}

double Func::eval() 
{
    if (tok->getTag() == ELEM_UN_FN)
    {
        auto var = ((UnaryFunc*)tok)->fn(expression1->eval());
#ifdef DEBUG_NODE
        std::cout << "UnaryFunc : " << var << '\n';
#endif
        return var;
    }
    else if(tok->getTag() == ELEM_BIN_FN)
    {
        auto var = ((BinaryFunc*)tok)->fn(expression1->eval(), expression2->eval());
#ifdef DEBUG_NODE
        std::cout << "BinaryFunc : " << var << '\n';
#endif
        return var;
    }
    else
        return 0.0;
}

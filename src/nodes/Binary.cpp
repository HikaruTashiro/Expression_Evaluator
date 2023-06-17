#include "../../headers/nodes/Binary.hpp"
#include "../../Config.hpp"
#include <string>
#ifdef DEBUG_NODE
#include <iostream>
#endif
#include <cmath>

Binary::Binary(std::shared_ptr<Expr> expr1, Token* op, std::shared_ptr<Expr> expr2) : expression1(expr1), expression2(expr2)
{
    tok = op;
}

double Binary::eval()
{
    double var;
    switch (tok->getTag())
    {
        case '+':
            var = expression1->eval() + expression2->eval();
#ifdef DEBUG_NODE
            std::cout << "Binary : " << var << '\n';
#endif
            return var;
        case '-':
            var = expression1->eval() - expression2->eval();
#ifdef DEBUG_NODE
            std::cout << "Binary : " << var << '\n';
#endif
            return var;
        case '*':
            var = expression1->eval() * expression2->eval();
#ifdef DEBUG_NODE
            std::cout << "Binary : " << var << '\n';
#endif
            return var;
        case '/':
            var = expression1->eval() / expression2->eval();
#ifdef DEBUG_NODE
            std::cout << "Binary : " << var << '\n';
#endif
            return var;
        case '^':
            var = std::pow(expression1->eval(), expression2->eval());
#ifdef DEBUG_NODE
            std::cout << "Binary : " << var << '\n';
#endif
            return var;
    }
    return 0.0;
}

std::string Binary::derivative()
{
    std::string expr1, expr2, res;
    expr1 = expression1->derivative();
    expr2 = expression2->derivative();
    res.reserve(expr1.size() + expr2.size() + 1);
    bool const_in_1 = expr1[0] == '0';
    bool const_in_2 = expr2[0] == '0';

    switch (tok->getTag())
    {
        case '+':
        case '-':
            if(const_in_1 && const_in_2)
                return "0";
            if(!const_in_1)
            {
                res += expr1;
                if(!const_in_2)
                {
                    res += tok->getLexeme();
                    res += expr2;
                }
                return res;
            }
            return expr2;
        case '*':
            return "";
    }
    return "";
}

std::string Binary::get_expr()
{
    /*STUBS*/
    return "";
}

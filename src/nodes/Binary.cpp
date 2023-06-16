#include "../../headers/nodes/Binary.hpp"
#include "../../Config.hpp"
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

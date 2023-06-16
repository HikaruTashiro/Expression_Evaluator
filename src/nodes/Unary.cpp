#include "../../headers/nodes/Unary.hpp"
#include <memory>
#include "../../Config.hpp"
#ifdef DEBUG_NODE
#include <iostream>
#endif

Unary::Unary(Token* op, std::shared_ptr<Expr> expr) : expression(expr)
{
    tok = op; 
}

double Unary::eval()
{
    if (tok != nullptr)
    {
        auto var = - expression->eval();
#ifdef DEBUG_NODE
        std::cout << "- Unary : " << var << '\n';
#endif
        return var;
    }
    auto var = expression->eval();
#ifdef DEBUG_NODE
    std::cout << "Unary : " << var << '\n';
#endif
    return var;
}

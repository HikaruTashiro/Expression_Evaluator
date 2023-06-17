#include "../../headers/nodes/Var.hpp"
#include "../../Config.hpp"
#ifdef DEBUG_NODE
#include <iostream>
#endif

Var::Var(Number* val)
{
    tok = val;
}

double Var::eval()
{
    auto var = ((Number*)tok)->value;
#ifdef DEBUG_NODE
    std::cout << "Var : " << var << '\n';
#endif
    return var;
}

std::string Var::derivative()
{
    return "1";
}

std::string Var::get_expr()
{
    return tok->getLexeme();
}

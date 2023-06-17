#include "Expr.hpp"

class Var : public Expr
{
    public:
        explicit Var(Number* val);
        double eval() override;
        std::string derivative() override;
        std::string get_expr() override;
};

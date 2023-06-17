#include "Expr.hpp"

class Const : public Expr
{
    public:
        explicit Const(Number* val);
        double eval() override;
        std::string derivative() override;
        std::string get_expr() override;
};

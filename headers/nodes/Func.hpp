#include <memory>
#include "Expr.hpp"

class Func : public Expr
{
    public:
        std::shared_ptr<Expr> expression1, expression2;
        explicit Func(Token* op, std::shared_ptr<Expr> expr1, std::shared_ptr<Expr> expr2);
        double eval() override;
};

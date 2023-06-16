#include "Expr.hpp"
#include <memory>

class Unary : public Expr
{
    public: 
        std::shared_ptr<Expr> expression;
        explicit Unary(Token* op, std::shared_ptr<Expr> expr);
        double eval() override;
};

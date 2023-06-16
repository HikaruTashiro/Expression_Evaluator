#include "../headers/Token.hpp"

Token::Token(std::string& lex, Tag tag) : lexeme(lex), type(tag) {}
Token::Token(const char* lex, Tag tag) : lexeme(lex), type(tag) {}

std::ostream& operator<<(std::ostream& stream, Token& tok)
{
    stream << tok.getTag() << " : " << tok.getLexeme() << '\n';
    return stream;
}

Number::Number(std::string& lex, Tag tag, double val) : Token(lex, tag), value(val) {}
Number::Number(const char* lex, Tag tag, double val) : Token(lex, tag), value(val) {}

UnaryFunc::UnaryFunc(std::string& lex, Tag tag, double (*func)(double)) : Token(lex, tag), fn(func)
{}

UnaryFunc::UnaryFunc(const char* lex, Tag tag, double (*func)(double)) : Token(lex, tag), fn(func)
{}

BinaryFunc::BinaryFunc(std::string& lex, Tag tag, double (*func)(double, double)) : Token(lex, tag), fn(func)
{}
BinaryFunc::BinaryFunc(const char* lex, Tag tag, double (*func)(double, double)) : Token(lex, tag), fn(func)
{}

#include <ostream>
#include <string>
#pragma once

enum tag : int
{
    CONST = 255,
    ELEM_BIN_FN,
    ELEM_UN_FN,
    X_VALUE,
    END_OF_FILE
};

typedef int Tag;

class Token
{
    private:
        std::string lexeme;
        Tag type;

    public:
        explicit Token(std::string& lex, Tag tag);
        explicit Token(const char* lex, Tag tag);
        inline const std::string& getLexeme() noexcept {return lexeme;}
        inline const Tag getTag() noexcept {return type;}

        friend std::ostream& operator<<(std::ostream& stream, Token& tok);
};

class Number : public Token
{
    public:
        double value;        
        explicit Number(std::string& lex, Tag tag, double val);
        explicit Number(const char* lex, Tag tag, double val);
};

class UnaryFunc : public Token
{
    public:
        double (*fn)(double);
        explicit UnaryFunc(std::string& lex, Tag tag, double (*func)(double));
        explicit UnaryFunc(const char* lex, Tag tag, double (*func)(double));
};

class BinaryFunc : public Token
{
    public:
        double (*fn)(double, double);
        explicit BinaryFunc(std::string& lex, Tag tag, double (*func)(double, double));
        explicit BinaryFunc(const char* lex, Tag tag, double (*func)(double, double));
};

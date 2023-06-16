PHASES = ./src
NODES = $(PHASES)/nodes
SOURCE = main.cpp
SOURCE += $(PHASES)/Lexer.cpp $(PHASES)/Parser.cpp $(PHASES)/Token.cpp
SOURCE += $(NODES)/Binary.cpp $(NODES)/Unary.cpp $(NODES)/Var.cpp $(NODES)/Const.cpp $(NODES)/Func.cpp
TARGET = $(addsuffix .o, $(basename $(notdir $(SOURCE))))

Link: Compile
	g++ -g -o main $(TARGET)

Compile:
	g++ -c $(SOURCE)

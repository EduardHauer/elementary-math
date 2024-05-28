SRC=src
INC=include
BIN=bin
OBJ=obj

LIBE=
EXEE=
OBJE=

ifeq ($(OS), Windows_NT)
	LIBE := .lib
	EXEE := .exe
	OBJE := .obj
else
	LIBE := .a
	EXEE :=
	OBJE := .o
endif

TARGET_EXE=main$(EXEE)
TARGET_LIB=$(BIN)/emath$(LIBE)

CPPC=g++
CPPCFLAGS=-std=c++23 -I./$(INC)/

CPPSRC=$(wildcard $(SRC)/*.cpp)
CPPOBJ=$(patsubst $(SRC)/%.cpp, $(OBJ)/%$(OBJE), $(CPPSRC))
CPPINC=$(wildcard $(INC)/*.h)

.PHONY: all exe lib clean

all: $(TARGET_EXE) $(TARGET_LIB)

exe: $(TARGET_EXE)

lib: $(TARGET_LIB)

clean:
	rm -rf $(TARGET_EXE) $(OBJ)/*$(OBJE)

$(OBJ)/%$(OBJE): $(SRC)/%.cpp $(CPPINC)
	$(CPPC) -c -o $@ $< $(CPPCFLAGS)

$(OBJ)/main$(OBJE): main.cpp $(CPPINC)
	$(CPPC) -c -o $@ $< $(CPPCFLAGS)

$(TARGET_EXE): $(OBJ)/main$(OBJE) $(TARGET_LIB)
	$(CPPC) -o $@ $^ -L./bin/ -lemath $(CPPCFLAGS)

$(TARGET_LIB): $(CPPOBJ)
	ar rcs $@ $^

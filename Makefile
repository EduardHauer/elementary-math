SRC=src
INC=include
BIN=bin
OBJ=obj

LIBE=
EXEE=
OBJE=
LIBP=

ifeq ($(OS), Windows_NT)
	LIBE := .lib
	EXEE := .exe
	OBJE := .obj
	LIBP := 
else
	LIBE := .a
	EXEE :=
	OBJE := .o
	LIBP := lib
endif

TARGET_EXE=main$(EXEE)
TARGET_LIB=$(BIN)/$(LIBP)emath$(LIBE)

CPPC=g++
CPPCFLAGS=-std=c++23 -I./$(INC)/
MKDIR=mkdir -p $(@D)
RM=rm -rf
LINKER=ar rcs

CPPSRC=$(wildcard $(SRC)/*.cpp)
CPPOBJ=$(patsubst $(SRC)/%.cpp, $(OBJ)/%$(OBJE), $(CPPSRC))
CPPINC=$(wildcard $(INC)/*.h)

.PHONY: all exe lib clean

all: $(TARGET_EXE) $(TARGET_LIB)

exe: $(TARGET_EXE)

lib: $(TARGET_LIB)

clean:
	$(RM) $(TARGET_EXE) $(OBJ)/*$(OBJE)

$(OBJ)/%$(OBJE): $(SRC)/%.cpp $(CPPINC)
	$(MKDIR)
	$(CPPC) -c -o $@ $< $(CPPCFLAGS)

$(OBJ)/main$(OBJE): main.cpp $(CPPINC)
	$(MKDIR)
	$(CPPC) -c -o $@ $< $(CPPCFLAGS)

$(TARGET_EXE): $(OBJ)/main$(OBJE) $(TARGET_LIB)
	$(MKDIR)
	$(CPPC) -o $@ $^ -L./bin/ -lemath $(CPPCFLAGS)

$(TARGET_LIB): $(CPPOBJ)
	$(MKDIR)
	$(LINKER) $@ $^

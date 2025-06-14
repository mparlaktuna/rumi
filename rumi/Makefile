CC      := g++
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.cpp)
OBJS    := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/init
INIT    := ../initramfs/init
CFLAGS  := -I$(INCLUDE) -static
LDFLAGS := -static

.PHONY: all run clean

all: $(EXE)
	rm $(INIT)
	cp $(EXE) $(INIT)

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir $@

clean:
	rm -rf $(OBJ) $(BIN)

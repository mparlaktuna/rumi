CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/init
INIT    := ../initramfs/bin/init
CFLAGS  := -I$(INCLUDE) -static
LDFLAGS := -static

.PHONY: all run clean

all: $(EXE)
	mv $(EXE) $(INIT)

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir $@

clean:
	rm $(OBJ) $(BIN)

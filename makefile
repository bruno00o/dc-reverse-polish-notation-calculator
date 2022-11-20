CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lreadline

SRC_DIR=src
OBJ_DIR=obj
INCLUDE_DIR=include

OBJ=$(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/stack.o $(OBJ_DIR)/calc.o $(OBJ_DIR)/test.o
EXEC=calc

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/main.o: main.c $(INCLUDE_DIR)/parser.h $(INCLUDE_DIR)/stack.h $(INCLUDE_DIR)/test.h
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c $(INCLUDE_DIR)/parser.h $(INCLUDE_DIR)/stack.h $(INCLUDE_DIR)/calc.h

$(OBJ_DIR)/stack.o: $(SRC_DIR)/stack.c $(INCLUDE_DIR)/stack.h

$(OBJ_DIR)/calc.o: $(SRC_DIR)/calc.c $(INCLUDE_DIR)/calc.h $(INCLUDE_DIR)/stack.h

$(OBJ_DIR)/test.o: $(SRC_DIR)/test.c $(INCLUDE_DIR)/test.h $(INCLUDE_DIR)/parser.h $(INCLUDE_DIR)/stack.h $(INCLUDE_DIR)/calc.h

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o

mrproper: clean
	rm -rf $(EXEC)
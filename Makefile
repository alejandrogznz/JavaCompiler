COMPILER= g++ -std=c++17
COMPILE_FLAGS=
COMPILE=$(COMPILER) $(COMPILE_FLAGS)

EXE=jcompiler
SRC_DIR=src
SRC= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR=obj
OBJ=$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

run: $(EXE)
	./$(EXE)

$(EXE): $(OBJ)
	$(COMPILE) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(SRC_DIR):
	mkdir $(SRC_DIR)

clean: 
	rm -f a.out *.o $(OBJ_DIR)/*.o $(EXE)



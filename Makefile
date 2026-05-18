# Variáveis de compilação
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Diretórios do projeto
SRC_DIR = src
TEST_FUNC_DIR = test/funcional
TEST_UNIT_DIR = test/unit
BIN_DIR = bin

# Caminho dos executáveis finais
EXEC_FUNC = $(BIN_DIR)/funcional_tests
EXEC_UNIT = $(BIN_DIR)/unit_tests
EXEC_MAIN = $(BIN_DIR)/produto

SRC_API = $(SRC_DIR)/mySim.cpp


all: create_bin $(EXEC_MAIN) $(EXEC_FUNC)

create_bin:
	mkdir -p $(BIN_DIR)


$(EXEC_MAIN): $(SRC_DIR)/main.cpp $(SRC_API)
	$(CXX) $(CXXFLAGS) $^ -o $@


$(EXEC_FUNC): $(TEST_FUNC_DIR)/main.cpp $(TEST_FUNC_DIR)/funcional_tests.cpp $(SRC_API)
	$(CXX) $(CXXFLAGS) $^ -o $@



# $(EXEC_UNIT): $(TEST_UNIT_DIR)/main.cpp $(TEST_UNIT_DIR)/unit_tests.cpp $(SRC_API)
# 	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	rm -rf $(BIN_DIR)/*

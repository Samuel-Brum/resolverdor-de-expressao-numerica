# -----------------------------------------------------------------------------
# Arquivo make para Trabalho prático [numero] de Estrutura de dados-UFMG 2023/1
# Autor: Samuel Brum Martins
# -----------------------------------------------------------------------------
# Compilador automático para trabalhos do Meira que devem seguir a seguinte
# estrutura de diretórios:
# .
# |--src
# |   |--arquivo1.cpp
# |   |--arquivo2.cpp   
# |--bin
# |   |--nomeDoProjeto
# |--obj
# |   |--arquivo1.o
# |   |--arquivo2.o
# |--include
# |   |--arquivo1.hpp
# |   |--arquivo2.hpp
# |--test
# |-- |--tests.cpp
# |--Makefile
# 
# O projeto contará apenas com os arquivos .cpp e .hpp e os diretórios,
# o resto será gerado durante o processo de compilação.
#
# Essa versão conta com um adendo para utilizar o framework de testes unitários
# DOCTEST.h, basta adicioná-lo à pasta "include" e criar testes dentro de um
# arquivo .cpp qualquer dentro da pasta "test". 
#
# UTILIZAÇÃO:
# 	- make all: compila tanto testes quanto o programa e executa os dois nessa
# 							ordem.
#   - make run: compila e executa apenas o programa
#   - make test: compila e executa apenas os testes
#   - make clean: remove binarios e arquivos objeto
#
# O Makefile funciona apenas para projetos em C++, para adaptá-lo para C
# será necessário alterar as variávies CXX para um compilador como gcc ou 
# clang e substituir todas as menções a .cpp para .c, assim como .hpp para .h
# 
# Caso isso for implementado, favor submeter pull request para atualizar o
# repositório. (https://github.com/Samuel-Brum/makefile-ED-meira)
# -----------------------------------------------------------------------------

CXX := g++
CXXFLAGS := -Wall -c -Iinclude -pg -g 

HEADERS := $(wildcard include/*.hpp)
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
TEST_SRC := $(wildcard test/*.cpp)
TEST_OBJ := $(filter-out obj/main.o, $(OBJECTS))
TEST_OBJ += $(patsubst test/src/%.o, obj/%.o, $(TEST_SRC))

EXE := bin/expNum
TEST_EXE := bin/tests

$(EXE): $(OBJECTS) $(HEADERS)
	$(CXX) -o $(EXE) $(OBJECTS) 

obj/%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(TEST_EXE): $(TEST_OBJ) $(HEADERS)
	$(CXX) -Iinclude -o $(TEST_EXE) $(TEST_OBJ)

all: $(EXE) $(TEST_EXE)
	$(TEST_EXE)
	$(EXE)

run: $(EXE)
	$(EXE)
	
test: $(TEST_EXE)	
	$(TEST_EXE)

clean:
	rm -f $(EXE) $(TEST_EXE) obj/*.o

.PHONY: all run test clean

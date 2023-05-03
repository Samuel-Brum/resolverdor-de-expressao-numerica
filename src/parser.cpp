#include "parser.hpp"
#include "expVerifier.hpp"
#include "arvoreBin.hpp"
#include "pilha.hpp"
#include "fila.hpp"

  // deve definir qual foi o tipo de input e criar a estrutura de árvore
  // deve verificar se o formato é válido
void ler(string exp) {
  if (verificaInfixo(exp)) {
    // converte para estado intermediário em notação pósfixa (shunting-yard)
    // constrói arvore 
  } else if (verificaPosfixo(exp)) {
    // constrói arvore 
  } else {
    std::cout << "ERRO - Expressão inválida" << std::endl;
  }
}
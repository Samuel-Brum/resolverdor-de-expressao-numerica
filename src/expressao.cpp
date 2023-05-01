#include "expressao.hpp"
#include "parser.hpp"

  // deve definir qual foi o tipo de input e criar a estrutura de árvore
  // deve verificar se o formato é válido
int Expressao::ler(string exp) {
  if (verificaInfixo(exp)) {
    // constroi arvore para infixo
  } else if (verificaPosfixo(exp)) {
    // constroi arvore para posfixo
  } else {
    std::cout << "ERRO - Expressão inválida" << std::endl;
  }
  return 0;
}
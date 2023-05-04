#include "parser.hpp"
#include "expVerifier.hpp"
#include "arvoreBin.hpp"
#include "pilha.hpp"
#include "fila.hpp"

using std::cout;
using std::endl;

  // deve definir qual foi o tipo de input e criar a estrutura de árvore
  // deve verificar se o formato é válido
void ler(string exp) {
  if (verificaInfixo(exp)) {
    cout << "EXPRESSAO OK :" << exp;
    Fila tokens = tokenIdentifier(exp);
    Fila posfixo = shuntingYard(tokens);
    // constrói arvore
  } else if (verificaPosfixo(exp)) {
    tokenIdentifier(exp);
    // constrói arvore
  } else {
    cout << "ERRO - Expressão inválida" << endl;
  }
}
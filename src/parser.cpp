#include "parser.hpp"
#include "expVerifier.hpp"
#include "pilha.hpp"
#include "fila.hpp"

using std::cout;
using std::endl;

Parser::Parser() {
  this->expInterna = Fila();
  this->expInfixa = "";
  this->expPosfixa = "";
}

void Parser::ler(string exp) {
  if (verificaInfixo(exp)) {
      this->expInfixa = exp;
      cout << "INFIXA: " << exp;
      Fila tokens = tokenIdentifier(exp);
      this->expInterna = shuntingYard(tokens);
    } else if (verificaPosfixo(exp)) {
      this->expPosfixa = exp;
      cout << "POSFIXA: " << exp;
      this->expInterna = tokenIdentifier(exp);
    } else {
      cout << "ERRO - Expressão inválida" << endl;
    }
}

void Parser::posfixa() {
  if (this->expPosfixa == "") {
    Fila temp = this->expInterna;
    while(temp.sizeOf() != 1) {
      this->expPosfixa += temp.desenfileirar() + " ";
    }
    this->expPosfixa += temp.desenfileirar();
  }
  cout << this->expPosfixa << endl;
}

void Parser::infixa() {

}

float Parser::resolve() {

}
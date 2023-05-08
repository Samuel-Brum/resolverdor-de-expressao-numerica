#include "parser.hpp"
#include "expVerifier.hpp"
#include "pilha.hpp"
#include "fila.hpp"

using std::cout;
using std::endl;
using std::stold;

Parser::Parser() {
  this->expInterna = Fila();
  this->expInfixa = "";
  this->expPosfixa = "";
}

void Parser::ler(string exp, bool print) {
  if (verificaInfixo(exp)) {
      this->expInfixa = exp;
      if (print) {
        cout << "EXPRESSÃO OK: " << exp << endl;
      }
      Fila tokens = tokenIdentifier(exp);
      this->expInterna = shuntingYard(tokens);
    } else if (verificaPosfixo(exp)) {
      this->expPosfixa = exp;
      if (print) {
        cout << "EXPRESSÃO OK: " << exp << endl;
      }
      this->expInterna = tokenIdentifier(exp);
    } else {
      if (print) {
        cout << "ERRO - Expressão inválida" << endl;
      }
    }
}

void Parser::posfixa() {
  if (this->expPosfixa == "" && this->expInfixa != "") {
    Fila temp = this->expInterna;
    while(temp.sizeOf() != 1) {
      this->expPosfixa += temp.desenfileirar() + " ";
    }
    this->expPosfixa += temp.desenfileirar();
  }
  this->ler(this->expInfixa, false);
  cout << "POSFIXA: " << this->expPosfixa << endl;
}

void Parser::infixa() {
  Fila temp = this->expInterna;
  if (this->expInfixa == "") {
    Pilha<string> pilha = Pilha<string>();
  
    while(temp.sizeOf() != 0) {
      string token = temp.desenfileirar();
      if (token == "*" || token == "/" || token == "+" || token == "-") {
        string operando1 = pilha.desempilhar();
        string operando2 = pilha.desempilhar();
        pilha.empilhar("( " + operando2 + " " + token + " " + operando1 + " )");
      } else {
        pilha.empilhar(token);
      }
    }
    this->expInfixa = pilha.desempilhar();
  }
  this->ler(this->expPosfixa, false);
  cout << "INFIXA: " << this->expInfixa << endl;
}


void Parser::resolve() {
  Fila temp = this->expInterna;
  Pilha<long double> pilha = Pilha<long double>();
  while (temp.sizeOf() != 0) {
    string token = temp.desenfileirar();
    if (token == "+") {
      long double operando1 = pilha.desempilhar();
      long double operando2 = pilha.desempilhar();
      pilha.empilhar(operando2 + operando1);
    } else if (token == "-") {
      long double operando1 = pilha.desempilhar();
      long double operando2 = pilha.desempilhar();
      pilha.empilhar(operando2 - operando1);
    } else if (token == "*") {
      long double operando1 = pilha.desempilhar();
      long double operando2 = pilha.desempilhar();
      pilha.empilhar(operando2 * operando1);
    } else if (token == "/") {
      long double operando1 = pilha.desempilhar();
      long double operando2 = pilha.desempilhar();
      pilha.empilhar(operando2 / operando1);
    } else {
      pilha.empilhar(stold(token));
    }
  }
  if (this->expPosfixa != "") {
      this->ler(this->expPosfixa, 1);
  } else {
    this->ler(this->expInfixa, false);
  }
  cout << "VAL: " << pilha.desempilhar() << endl;
} 
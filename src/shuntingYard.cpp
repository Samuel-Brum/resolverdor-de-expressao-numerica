#include "shuntingYard.hpp"

Fila tokenIdentifier(string expressao) {
  Fila filaTokens = Fila();
  string floatNum;
  bool numCheck = false; 
  for (long unsigned int i = 0; i < expressao.length(); i++) {
    char c = expressao[i];

    if (isspace(c)){
      if ((numCheck = true)) {
        filaTokens.enfileirar(floatNum);
        floatNum = "";
        numCheck = false;
      }
      continue;
    } else {
      if(isdigit(c) || c == '.') {
        floatNum += c;
        numCheck = true;
      } else {
        if (numCheck == true) {
          filaTokens.enfileirar(floatNum);
          floatNum = "";
          numCheck = false;
          filaTokens.enfileirar(string(1,c));
          continue;
        }
        filaTokens.enfileirar(string(1,c));
      }
    }
    if (numCheck == true) {
      filaTokens.enfileirar(floatNum);
      floatNum = "";
      numCheck = false;
    }
  }
  return filaTokens;
}

Fila shuntingYard(Fila tokens) {
  int tamanho = tokens.sizeOf();
  Pilha operadores = Pilha();
  Fila posfixo  = Fila();

  for (int i = 0; i < tamanho; i++) {
    string token = tokens.desenfileirar();
    if (isdigit(token[0])) {
      posfixo.enfileirar(token);
      continue;
    } else if (token == "*" || token == "/"){
      operadores.empilhar(token);
      continue;
    } else if (token == "+" || token == "-") {
      while (operadores.getTopo() == "*" || operadores.getTopo() == "/"){
        posfixo.enfileirar(operadores.desempilhar());
      }
      operadores.empilhar(token);
      continue;
    } else if (token == "(") {
      operadores.empilhar(token);
      continue;
    } else if (token == ")") {
      while (operadores.getTopo() != "(") {
        posfixo.enfileirar(operadores.desempilhar());
      }
      operadores.desempilhar();
      continue;
    }
  }
  while (!(operadores.estaVazia())) {
    posfixo.enfileirar(operadores.desempilhar());
  }
  return posfixo;
}
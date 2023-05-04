#include "shuntingYard.hpp"

Fila tokenIdentifier(string expressao) {
  Fila filaTokens = Fila();
  string floatNum;
  bool numCheck = false; 
  for (long unsigned int i = 0; i < expressao.length(); i++) {
    char c = expressao[i];

    if (isspace(c)){
      if (numCheck == true) {
        filaTokens.enfileirar(floatNum);
        floatNum = "";
        numCheck = false;
      }
      continue;
    } else {
      if(isdigit(c) || c == '.') {
        floatNum += c;
        numCheck = true;
        if (i == expressao.length() -1) {
          filaTokens.enfileirar(floatNum);
        }
      } else {
        if (numCheck == true) {
          filaTokens.enfileirar(floatNum);
          floatNum = "";
        }
        filaTokens.enfileirar(string(1,c));
        numCheck = false;
        if (floatNum != "" && numCheck == true) {
          filaTokens.enfileirar(floatNum);
          floatNum = "";
          numCheck = false;
        }
      }
    }
    
  }
  return filaTokens;
}

Fila shuntingYard(Fila tokens) {
  int tamanho = tokens.sizeOf();
  Pilha operadores = Pilha();
  Fila posfixo  = Fila();
  bool numCheck = false;
  string floatNum = "";

  for (int i = 0; i < tamanho; i++) {
    string token = tokens.desenfileirar();
    if (isdigit(token[0]) || token == ".") {
      if (numCheck == true) {
        floatNum += token;
      } else {
        floatNum = token;
        numCheck = true;
      }
    } else if (token == "*" || token == "/"){
      if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
      operadores.empilhar(token);
      continue;
    } else if (token == "+" || token == "-") {
      if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
      while ((operadores.getTopo() == "*" || operadores.getTopo() == "/")){
        posfixo.enfileirar(operadores.desempilhar());
      }
      operadores.empilhar(token);
      continue;
    } else if (token == "(") {
      if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
      operadores.empilhar(token);
      continue;
    } else if (token == ")") {
      if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
      while (operadores.getTopo() != "(") {
        posfixo.enfileirar(operadores.desempilhar());
      }
      operadores.desempilhar();
      continue;
    }
  }
  while (!(operadores.estaVazia())) {
    if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
    posfixo.enfileirar(operadores.desempilhar());
  }
  return posfixo;
}
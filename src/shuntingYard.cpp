#include "shuntingYard.hpp"

Fila tokenIdentifier(string expressao) {
  Fila filaTokens = Fila();
  string floatNum = "";
  bool numCheck = false; // verifica se há um float sendo contruido
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
      if(isdigit(c) || c == '.') { // incrementa numFloat com token
        floatNum += c;
        numCheck = true;
        if (i == expressao.length() - 1) { // caso último token seja um número
          filaTokens.enfileirar(floatNum);
        }
      } else { // faz dump de floatNum e do token, nessa ordem
        if (numCheck == true) {
          filaTokens.enfileirar(floatNum);
          floatNum = "";
        }
        filaTokens.enfileirar(string(1,c));
        numCheck = false;
      }
    }
    
  }
  return filaTokens;
}

Fila shuntingYard(Fila tokens) {
  int tamanho = tokens.sizeOf();
  Pilha<string> operadores = Pilha<string>(); // Pilha temporária para tudo que não é número
  Fila posfixo  = Fila(); // Fila com tokens na ordem pósfixa
  bool numCheck = false; // verifica se há um float sendo contruido
  string floatNum = ""; 

  for (int i = 0; i < tamanho; i++) {
    string token = tokens.desenfileirar();
    if (isdigit(token[0]) || token == ".") { // Incrementa ou cria novo floatNum
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
  while (!(operadores.estaVazia())) { // Faz dump de todos operadores no final
    if (numCheck == true) {
        posfixo.enfileirar(floatNum);
        numCheck = false;
      }
    posfixo.enfileirar(operadores.desempilhar());
  }
  return posfixo;
}
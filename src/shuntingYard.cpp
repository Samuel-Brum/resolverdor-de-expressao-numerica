#include "shuntingYard.hpp"

Fila tokenIdentifier(string expressao) {
  Fila filaTokens = Fila();
  string floatNum;
  for (int i = 0; i < expressao.length(); i++) {
    char c = expressao[i];
    bool numCheck = false; 

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
        filaTokens.enfileirar(string(1,c));
        numCheck = true;
      }
    }
  }
  return filaTokens;
}
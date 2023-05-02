#include "expVerifier.hpp"

bool verificaInfixo(string expressao) {
  string::size_type i, n = expressao.length();
  int contador = 0;
  bool num = false;
  bool decimal = false;

  for (i = 0; i < n; i++) {
    char c = expressao[i];
    if (isspace(c)) {
      continue; // ignora espaços
    }

    if (isdigit(c) || c == '.') {
      if (c == '.') {
        if (decimal) {
          return false; // mais de um ponto decimal no número
        }
        decimal = true;
      }

      num = true;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (num == false) {
        return false; // operadores demais
      }
      num = false;
      decimal = false;
      contador--;
      if (contador < 0) {
        return false; // mais de um operador seguido 
      }
      contador++;
    } else if (c == '(') {
      if (i > 0) {
        char prev = expressao[i-1];
        if (isdigit(prev) || prev == ')') {
          return false; // falta operador
        }
      }
      contador++;
    } else if (c == ')') {
      if (num == false) {
        return false; // falta operador
      }
      decimal = false;
      contador--;
      if (contador < 0) {
        return false; // parentesis fechados demais
      }
    } else {
      return false; // caractere inválido
    }
  }

  if (num == false) {
    return false; // sem número
  }
  
  if (contador != 0) {
    return false; // parentesis não fecham
  }

  return true;
}

bool verificaPosfixo(string expressao) {
  string::size_type i, n = expressao.length();
  int contador = 0;
  bool decimal = false;

  for (i = 0; i < n; i++) {
    char c = expressao[i];

    if (isspace(c)) {
      decimal = false;
      continue; // ignora espaços
    }

    if (isdigit(c)) {
      if (!decimal) {
        contador ++;
      }
    } else if (c == '.') {
        if (decimal) {
          return false; // mais de um ponto decimal no número
        }
        decimal = true;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      decimal = false;
      contador -= 2;
      if (contador < 0) {
        return false; // operadores demais
      }
      contador++;
    } else {
      return false; // caractere inválido
    }
  }

  if (contador != 1) {
    return false; // expressão não resolve em um número
  }

  return true;
}
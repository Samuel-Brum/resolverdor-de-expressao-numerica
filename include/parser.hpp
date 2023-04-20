#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>

using std::string;

/// @brief verifica se expressão está formatada em infixo
/// @param expressao string a ser verificada
/// @return retorna true caso expressao esteja em infixo e false caso contrário
bool verificaInfixo(std::string expressao);

/// @brief verifica se expressão está formatada em posfixo
/// @param expressao string a ser verificada
/// @return retorna true caso expressao esteja em posfixo e false caso contrário
bool verificaPosfixo(std::string expressao);

/// @brief avalia se expressão está expressa corretamente em infixo ou pósfixo
/// @param expressao expressao: string a ser verificada
/// @return retorna 1 caso infixo, 2 caso pósfixo ou 3 caso contrário
int verificador(std::string expressao);

#endif
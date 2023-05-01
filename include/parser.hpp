#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>

using std::string;

/// @brief verifica se expressão está formatada em infixo
/// @param expressao string a ser verificada
/// @return retorna true caso expressao esteja em infixo e false caso contrário
bool verificaInfixo(string expressao);

/// @brief verifica se expressão está formatada em posfixo
/// @param expressao string a ser verificada
/// @return retorna true caso expressao esteja em posfixo e false caso contrário
bool verificaPosfixo(string expressao);

#endif
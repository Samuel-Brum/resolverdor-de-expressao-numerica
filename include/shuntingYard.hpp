#ifndef SHUNTING_YARD_HPP
#define SHUNTING_YARD_HPP

#include <iostream>
#include <string>
#include "fila.hpp"
#include "pilha.hpp"

using std::string;

/// @brief Separa os tokens de uma string de expressão numérica
/// @param expressao string a ser separada
/// @return Fila com tokens separados
Fila tokenIdentifier(string expressao);

/// @brief Utiliza o algoritmo shunting yard para converter expressao numerica
///        de formato infixo para posfixo;
/// @param tokens Tokens a serem convertidos para notação polonesa reversa
/// @return Fila de tokens ordenados em notação posfixa
Fila shuntingYard(Fila tokens);

#endif
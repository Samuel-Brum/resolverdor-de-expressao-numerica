#ifndef SHUNTING_YARD_HPP
#define SHUNTING_YARD_HPP

#include <iostream>
#include <string>
#include "fila.hpp"

using std::string;

/// @brief Separa os tokens de uma string de expressão numérica
/// @param expressao string a ser separada
/// @return Fila com tokens separados
Fila tokenIdentifier(string expressao);



#endif
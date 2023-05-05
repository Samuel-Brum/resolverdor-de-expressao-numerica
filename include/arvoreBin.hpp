#ifndef ARVOREBIN_HPP
#define ARVOREBIN_HPP

#include <iostream>
#include <string>

#include "fila.hpp"

using std::string;

struct NodeArvoreBin {
  NodeArvoreBin* esquerdo;
  NodeArvoreBin* direito;  
  string token;

  NodeArvoreBin(string token) {
    this->token = token;
    this->esquerdo = this->direito = nullptr;
  };

  NodeArvoreBin(string token, NodeArvoreBin* esquerdo, NodeArvoreBin* direito) {
    this->token = token;
    this->esquerdo = esquerdo;
    this->direito = direito;
  };
};

class ArvoreBinaria {
  public:
    /// @brief Contrutor da Árvore Binária
    ArvoreBinaria();
    
    /// @brief Verifica se Árvore está vazia
    /// @return true caso esteja, false caso contrário
    bool estaVazio();

    void inserir(string token);

    /// @brief Constrói árvore binária a partir de uma expressão pósfixa
    /// @param tokens Fila com tokens da expressão
    ArvoreBinaria construirPosfixo(Fila tokens);

    /// @brief Converte tokens para literais e avalia a expressão correspondente
    /// @return Valor da expressão armazenada na árvore
    float avaliarExp();

    void caminhar();

    /// @brief Imprime a expressão corresponte à árvore em notação infixa
    void imprimirInfixo();

    /// @brief Imprime a expressão correspondente à árvore em notação pósfixa
    void imprimirPosfixo();

    /// @brief Remove todos os nós da árvore
    void limpar();

  protected:
    NodeArvoreBin* raiz;

    bool ehOperador(string token) {
      return (token == "*" || token == "/" || token == "+" || token == "-");
    }
};

#endif

#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
#include <string>

using std::string;

class Pilha {
  public:
    /// @brief Construtor da pilha
    Pilha();

    /// @brief Verifica se pilha está vazia
    /// @return true caso esteja, false caso contrário
    bool estaVazia();

    /// @brief adiciona caractere novo ao topo da pilha
    /// @param token caractere a ser empilhado
    void empilhar(string token);

    /// @brief remove caractere do topo da pilha
    void desempilhar();

    /// @brief remove todos os elementos da pilha
    void limpar();

  private:
    struct NodePilha{
      NodePilha* proximo;
      string token;
    };

    NodePilha* topo;
};

#endif
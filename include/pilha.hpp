#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
#include <string>

using std::string;

template <typename T>
struct NodePilha {
  NodePilha* proximo;
  T token;
};


/// @brief Estrutura de pilha encadeada de strings
template <typename T>
class Pilha {
  public:
    /// @brief Construtor da pilha
    Pilha();

    /// @brief Retorna elemento no topo da pilha
    /// @return String no topo da pilha
    T getTopo();

    /// @brief Retorna tamanho da pilha
    /// @return Tamanho da Pilha
    int sizeOf();

    /// @brief Verifica se pilha está vazia
    /// @return true caso esteja, false caso contrário
    bool estaVazia();

    /// @brief adiciona caractere novo ao topo da pilha
    /// @param token caractere a ser empilhado
    void empilhar(T token);

    /// @brief remove caractere do topo da pilha
    T desempilhar();

    /// @brief remove todos os elementos da pilha
    void limpar();

  private:
    /// @brief Célula da pilha
    NodePilha<T>* topo;
    int tamanho;
};

#endif
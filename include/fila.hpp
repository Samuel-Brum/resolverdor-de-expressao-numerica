#ifndef FILA_HPP
#define FILA_HPP

#include <string>

using std::string;

/// @brief Estrutura de fila encadeada de strings 
class Fila {
  public: 
    Fila();
    
    /// @brief Verifica se lista está vazia
    /// @return true se estiver, false caso contrário
    bool estaVazia();

    /// @brief Adiciona elemento no final da fila
    /// @param token string a ser adicionada
    void enfileirar(string token);

    /// @brief Remove elemento no início da fila e desaloca ponteiro do elemento
    /// @return Elemento removido
    string desenfileirar();

    /// @brief Remove e desaloca todos os elementos da fila
    void limpar();

    int sizeOf();
  
  private:
    /// @brief Células da fila
    struct NodeFila {
      NodeFila* proximo;
      string token;
    };

    NodeFila* frente;
    NodeFila* tras;
    int tamanho;
};

#endif
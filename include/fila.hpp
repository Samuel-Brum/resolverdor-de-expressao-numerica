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

    /// @brief 
    /// @param token 
    void enfileirar(string token);

    /// @brief
    /// @param token
    string desenfileirar(string token);

    /// @brief
    void limpar();
  
  private:
    /// @brief
    struct NodeFila {
      
    };
};

#endif
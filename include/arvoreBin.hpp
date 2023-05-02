#ifndef ARVOREBIN_HPP
#define ARVOREBIN_HPP

#include <iostream>

class ArvoreBinaria {
  public:
    ArvoreBinaria();

    ~ArvoreBinaria();
    
    bool estaVazio();

    void inserir(char c);

    void caminhar();

  private:
    struct Node {
      Node* esquerdo;
      Node* direito;  
      char token;
    };

    Node* raiz;
};



#endif
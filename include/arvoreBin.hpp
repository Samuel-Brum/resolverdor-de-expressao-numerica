#ifndef ARVOREBIN_HPP
#define ARVOREBIN_HPP

#include <iostream>
#include <string>

using std::string;

class ArvoreBinaria {
  public:
    ArvoreBinaria();

    ~ArvoreBinaria();
    
    bool estaVazio();

    void inserir(string c);

    void caminhar();

  private:
    struct NodeArvoreBin {
      NodeArvoreBin* esquerdo;
      NodeArvoreBin* direito;  
      string token;
    };

    NodeArvoreBin* raiz;
};



#endif
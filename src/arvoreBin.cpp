#include "arvoreBin.hpp"

ArvoreBinaria::ArvoreBinaria() {
  this->raiz = nullptr;
}


bool ArvoreBinaria::estaVazio() {
  if (this->raiz == nullptr) {
    return true;
  } else {
    return false;
  }
}

ArvoreBinaria ArvoreBinaria::construirPosfixo(Fila posfixo) {
  // caso base
  if (posfixo.sizeOf() == 0) {
    return ArvoreBinaria();
  }
  
}

void ArvoreBinaria::inserir(string c) {

}

void ArvoreBinaria::caminhar() {
  
}
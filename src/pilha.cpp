#include "pilha.hpp"

Pilha::Pilha() {
  this->topo = nullptr;
}

bool Pilha::estaVazia() {
  if (this->topo == nullptr) {
    return true;
  } else {
    return false;
  }
}

void Pilha::empilhar(string token) {
  NodePilha* nova = new NodePilha;

  nova->token = token;
  nova->proximo = topo;
  topo = nova;
}

string Pilha::desempilhar() {
  if (this->estaVazia()) {
    return ""; // alterar para throw?
  }
  string temp = this->topo->token;
  NodePilha* p = this->topo;
  this->topo = this->topo->proximo;
  delete p;
  
  return temp;
}

void Pilha::limpar() {
  while(!this->estaVazia()) {
    this->desempilhar();
  }
}
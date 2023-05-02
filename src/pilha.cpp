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
  NodePilha* nova;

  nova->token = token;
  nova->proximo = topo;
  topo = nova;
}

void Pilha::desempilhar() {
  if (this->estaVazia()) {
    return;
  }
  this->topo = this->topo->proximo;
}

void Pilha::limpar() {
  while(this->topo != nullptr) {
    this->desempilhar();
  }
}
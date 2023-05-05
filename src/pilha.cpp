#include "pilha.hpp"

template<>
Pilha<string>::Pilha() {
  this->topo = nullptr;
  this->tamanho = 0;
}

template<>
string Pilha<string>::getTopo() {
  if ((tamanho != 0)) {
    return this->topo->token;
  } else {
    return "";
  }
}

template<>
int Pilha<string>::sizeOf() {
  return this->tamanho;
}

template<>
bool Pilha<string>::estaVazia() {
  return (this->topo == nullptr);
}

template<>
void Pilha<string>::empilhar(string token) {
  NodePilha<string>* nova = new NodePilha<string>;

  nova->token = token;
  nova->proximo = topo;
  topo = nova;
  tamanho++;
}

template<>
string Pilha<string>::desempilhar() {
  if (this->estaVazia()) {
    return ""; // alterar para throw?
  }
  string temp = this->topo->token;
  NodePilha<string>* p = this->topo;
  this->topo = this->topo->proximo;
  delete p;
  tamanho--;
  
  return temp;
}

template<>
void Pilha<string>::limpar() {
  while(!this->estaVazia()) {
    this->desempilhar();
  }
}
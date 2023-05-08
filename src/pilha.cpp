#include "pilha.hpp"

template<>
Pilha<string>::Pilha() {
  this->topo = nullptr;
  this->tamanho = 0;
}

template<>
Pilha<NodeArvoreBin*>::Pilha() {
  this->topo = nullptr;
  this->tamanho = 0;
}

template<>
Pilha<long double>::Pilha() {
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
NodeArvoreBin* Pilha<NodeArvoreBin*>::getTopo() {
  if ((tamanho != 0)) {
    return this->topo->token;
  } else {
    return nullptr;
  }
}

template<>
long double Pilha<long double>::getTopo() {
  if ((tamanho != 0)) {
    return this->topo->token;
  } else {
    return 0;
  }
}

template<>
int Pilha<string>::sizeOf() {
  return this->tamanho;
}

template<>
int Pilha<NodeArvoreBin*>::sizeOf() {
  return this->tamanho;
}

template<>
int Pilha<long double>::sizeOf() {
  return this->tamanho;
}

template<>
bool Pilha<string>::estaVazia() {
  return (this->topo == nullptr);
}

template<>
bool Pilha<NodeArvoreBin*>::estaVazia() {
  return (this->topo == nullptr);
}

template<>
bool Pilha<long double>::estaVazia() {
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
void Pilha<NodeArvoreBin*>::empilhar(NodeArvoreBin* token) {
  NodePilha<NodeArvoreBin*>* nova = new NodePilha<NodeArvoreBin*>;

  nova->token = token;
  nova->proximo = topo;
  topo = nova;
  tamanho++;
}

template<>
void Pilha<long double>::empilhar(long double token) {
  NodePilha<long double>* nova = new NodePilha<long double>;

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
NodeArvoreBin* Pilha<NodeArvoreBin*>::desempilhar() {
  if (this->estaVazia()) {
    return nullptr; // alterar para throw?
  }
  NodeArvoreBin* temp = this->topo->token;
  NodePilha<NodeArvoreBin*>* p = this->topo;
  this->topo = this->topo->proximo;
  delete p;
  tamanho--;
  
  return temp;
}

template<>
long double Pilha<long double>::desempilhar() {
  if (this->estaVazia()) {
    return 0; // alterar para throw?
  }
  long double temp = this->topo->token;
  NodePilha<long double>* p = this->topo;
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

template<>
void Pilha<NodeArvoreBin*>::limpar() {
  while(!this->estaVazia()) {
    this->desempilhar();
  }
}

template<>
void Pilha<long double>::limpar() {
  while(!this->estaVazia()) {
    this->desempilhar();
  }
}
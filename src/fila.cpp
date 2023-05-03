#include "fila.hpp"

Fila::Fila() {
  this->frente = new NodeFila;
  this->tras = frente;
  this->tamanho = 0;
}

bool Fila::estaVazia() {
  if (tamanho == 0) {
    return true;
  } else {
    return false;
  }
}

void Fila::enfileirar(string token) {
  NodeFila* nova = new NodeFila;
  nova->proximo = nullptr;
  nova->token = token;
  this->tras->proximo = nova;
  tras = nova;
  tamanho++;
}

string Fila::desenfileirar() {
  if (this->estaVazia()) {
    return ""; // alterar para throw?
  }
  string temp = this->frente->proximo->token;
  NodeFila* p = this->frente;
  this->frente = this->frente->proximo;
  delete p;
  tamanho--;
  return temp;
}

void Fila::limpar() {
  while (tamanho > 0) {
    this->desenfileirar();
  }
}
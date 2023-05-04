#include "shuntingYard.hpp"

int main (int argc, char* argv[]) {
  string exp = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
  string identificados;
  Fila teste = tokenIdentifier(exp);
  int tamanho = teste.sizeOf();
  for (int i = 0; i < tamanho; i++) {
    identificados += teste.desenfileirar();
  }
  std::cout << identificados << std::endl;

  teste = tokenIdentifier(exp);
  identificados = "";
  teste = shuntingYard(teste);
  for (int i = 0; i < tamanho; i++) {
    identificados += teste.desenfileirar();
  }
  std::cout << identificados << std::endl;
}
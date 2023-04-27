#include "parser.hpp"
#include "expressao.hpp"

using std::cout;
using std::endl;

int main (int argc, char* argv[]) {
  string correto = "( ( ( ( 2.071122 ) + ( ( ( 1.036112 ) / ( 9.212616 ) ) * ( ( 7.151603 ) * ( 2.203524 ) ) ) ) / ( ( ( 9.007030 ) + ( 2.889450 ) ) - ( 1.554032 ) ) ) * ( ( 3.186413 ) / ( 7.180392 ) ) )";
  string incorreto = "LER  ( ( ( ( 2.071122 ) + ( (  1.036112 )  ( 9.212616 ) ) * ( ( 7.151603 ) * ( 2.203524 ) ) ) ) / ( ( ( 9.007030 ) + ( 2.889450 ) ) - ( 1.554032 ) ) ) * ( ( 3.186413 ) / ( 7.180392 ) ) )";
  cout << "correto: " << verificaInfixo(correto) << endl;
  cout << "incorreto: " << verificaInfixo(incorreto) << endl;
  cout << "true = " << true << endl;
  cout << "false = " << false << endl;
}
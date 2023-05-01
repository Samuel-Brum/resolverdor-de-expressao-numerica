#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "parser.hpp"
#include <string>

using std::string;

string casosBase[32];
string s1n5 = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
string s2n5 = "9.874522  7.929620  *  8.681109  +  5.303303  /  3.118387  7.559106  +  7.215866  /  + ";
string s3n5 = "( ( ( ( 2.337697 ) - ( 6.086307 ) ) - ( 0.125789 ) ) / ( ( 9.071004 ) * ( 4.981880 ) ) )";
string s4n5 = "7.325484  2.298093  2.321958  /  4.759999  *  * ";
string s5n5 = "( ( ( ( 4.771053 ) / ( 8.509878 ) ) + ( ( 2.799444 ) - ( 6.606407 ) ) ) - ( ( 3.703479 ) / ( 6.146766 ) ) )";
string s6n5 = "4.721663  6.714296  +  0.838888  +  4.205877  4.278166  +  *  4.863587  2.466270  *  / ";
string s7n5 = "( ( ( ( 7.204409 ) - ( 0.933449 ) ) + ( ( 8.878333 ) / ( 4.141810 ) ) ) * ( 0.613876 ) )";
string s8n5 = "5.946317  1.106634  6.917778  *  7.021876  5.427541  /  -  8.515828  0.091471  /  *  - ";
string s11n10 = "( ( ( ( 2.071122 ) + ( ( ( 1.036112 ) / ( 9.212616 ) ) * ( ( 7.151603 ) * ( 2.203524 ) ) ) ) / ( ( ( 9.007030 ) + ( 2.889450 ) ) - ( 1.554032 ) ) ) * ( ( 3.186413 ) / ( 7.180392 ) ) )";
string s12n10 = "1.992376  9.891310  /  2.980318  3.212984  5.820309  /  3.313860  9.279071  *  -  /  -  9.480833  -  2.620958  3.147509  *  + ";
string s13n10 = "( ( ( ( 4.504478 ) * ( ( 2.087479 ) / ( ( ( 9.061872 ) * ( 8.300978 ) ) * ( 4.222443 ) ) ) ) / ( ( 9.154475 ) / ( 7.620691 ) ) ) / ( ( ( 6.252952 ) * ( 2.055502 ) ) * ( 9.114626 ) ) )";
string s14n10 = "4.415947  4.283648  +  0.515721  5.469871  *  /  9.472549  2.967076  *  1.927521  /  -  5.097319  1.490047  *  5.081742  +  * ";
string s15n10 = "( ( ( ( 6.937834 ) + ( 0.627732 ) ) / ( 6.479817 ) ) - ( ( ( ( 9.450352 ) + ( ( 1.298669 ) * ( 6.779677 ) ) ) - ( 6.234352 ) ) - ( 8.447937 ) ) )";


// cout << "Infixo '1 1': " << verificaInfixo("1 1") << endl; // TODO: bug - verificaInfixo não lida com casos assim
// cout << "Posfixo '1 1': " << verificaPosfixo("1 1") << endl;

TEST_CASE("Verificador Infixo faz asserções corretas para os casos base") {
  REQUIRE(verificaInfixo(s1n5) == true);
  REQUIRE(verificaInfixo(s3n5) == true);
  REQUIRE(verificaInfixo(s5n5) == true);
  REQUIRE(verificaInfixo(s7n5) == true);
  REQUIRE(verificaInfixo(s11n10) == true);
  REQUIRE(verificaInfixo(s13n10) == true);
  REQUIRE(verificaInfixo(s15n10) == true);
}

TEST_CASE("Verificador Posfixo faz asserções corretas para os casos base") {
  REQUIRE(verificaPosfixo(s2n5) == true);
  REQUIRE(verificaPosfixo(s4n5) == true);
  REQUIRE(verificaPosfixo(s6n5) == true);
  REQUIRE(verificaPosfixo(s8n5) == true);
  REQUIRE(verificaPosfixo(s12n10) == true);
  REQUIRE(verificaPosfixo(s14n10) == true);
}

TEST_CASE("Verificador Infixo retorna falso para o caso vazio") {
  REQUIRE(verificaInfixo("") == false);
}

TEST_CASE("Verificador Posfixo retorna falso para o caso vazio") {
  REQUIRE(verificaPosfixo("") == false);
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <string>
#include "expVerifier.hpp"
#include "pilha.hpp"
#include "fila.hpp"
#include "shuntingYard.hpp"

using std::string;

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
string s16n10 = "1.233336  8.051124  /  8.285869  *  0.025039  -  7.250822  +  0.592278  0.541182  -  -  4.837558  + ";
string s17n10 = "( ( ( ( 9.371190 ) - ( ( ( 9.272781 ) + ( ( 4.693868 ) + ( 0.599727 ) ) ) - ( 8.260282 ) ) ) / ( ( ( 4.848012 ) - ( 1.227180 ) ) - ( 9.114836 ) ) ) * ( ( ( 2.983092 ) / ( ( 4.864214 ) * ( 2.028334 ) ) ) + ( 6.218101 ) ) )";
string s18n10 = "5.586527  1.101867  *  1.174414  -  9.269741  /  8.217480  9.154843  *  *  7.616802  *  9.228226  8.950209  +  1.105139  3.757115  +  *  +  5.310802  7.184243  7.323986  /  *  -";
string s21n25 = "( ( ( ( ( ( ( 1.430560 ) / ( 6.889632 ) ) / ( ( ( ( 2.255391 ) + ( 9.655282 ) ) - ( 2.075334 ) ) + ( ( 0.822038 ) * ( 7.007894 ) ) ) ) - ( ( ( ( 9.827914 ) - ( ( 3.516262 ) / ( 6.577532 ) ) ) * ( 2.560684 ) ) / ( 9.362095 ) ) ) - ( ( ( 5.562911 ) + ( 7.878364 ) ) + ( 9.584948 ) ) ) * ( 4.856426 ) ) * ( ( ( ( ( 0.766523 ) / ( 6.980499 ) ) + ( ( 8.642408 ) - ( 3.041649 ) ) ) * ( ( 0.327483 ) - ( 7.814537 ) ) ) / ( ( 9.022130 ) - ( ( ( 0.797961 ) * ( 6.797215 ) ) + ( 0.093923 ) ) ) ) )";
string s22n25 = "6.733864  3.307580  3.467883  6.382165  -  -  +  5.852262  6.966405  /  2.818675  -  /  9.777471  +  6.068840  -  0.197555  7.996080  9.901208  *  *  2.204812  -  4.142752  +  +  9.740306  *  4.983539  3.912696  *  2.068473  +  +  4.860581  3.747983  +  -";
string s23n25 = "( ( ( ( ( 0.322015 ) * ( ( ( 4.425035 ) / ( ( ( 4.317040 ) - ( 5.907631 ) ) - ( ( 0.688995 ) * ( ( 6.675639 ) / ( ( 6.400950 ) - ( 8.785792 ) ) ) ) ) ) - ( 4.697022 ) ) ) / ( 2.309765 ) ) * ( ( 2.165343 ) + ( ( ( ( ( 8.675153 ) * ( 8.846712 ) ) - ( ( 9.895663 ) + ( 5.832503 ) ) ) / ( 2.102247 ) ) * ( 2.504343 ) ) ) ) / ( ( ( 0.290983 ) * ( 2.740664 ) ) * ( ( 0.936924 ) - ( ( 8.729100 ) * ( 2.775289 ) ) ) ) )";
string s24n25 = "6.245338  5.326499  7.733752  -  1.093085  /  4.995825  /  5.954532  *  *  4.752909  9.616572  *  8.550690  -  7.844262  5.471297  +  3.332128  7.449099  +  -  -  -  6.671527  0.051021  *  /  0.025147  9.360934  /  0.479166  +  +  7.084182  8.068251  -  8.999193  4.021101  +  +  6.038406  +  *";
string s25n25 = "( ( ( ( ( ( 8.441507 ) - ( ( ( 5.957862 ) + ( ( ( 9.559872 ) * ( ( 9.302656 ) - ( 2.344154 ) ) ) * ( 2.529240 ) ) ) - ( 2.385365 ) ) ) / ( ( 0.720025 ) * ( 4.536122 ) ) ) + ( ( ( ( ( 3.108168 ) / ( 8.932564 ) ) + ( 1.000151 ) ) * ( 6.223044 ) ) - ( 2.130512 ) ) ) * ( ( 0.206379 ) - ( ( ( 7.545952 ) - ( 2.085053 ) ) * ( ( 9.815442 ) - ( 8.500830 ) ) ) ) ) - ( 2.007364 ) )";
string s26n25 = "1.627783  2.365861  5.771913  *  +  8.718286  3.609486  +  8.733775  *  /  1.229733  6.687142  9.455672  -  +  *  0.138964  8.688749  /  8.668175  4.996990  *  8.772412  +  +  -  9.200303  /  5.066756  8.889858  9.577672  -  +  1.427157  9.378698  *  +  8.158811  4.938767  +  5.053923  *  7.014099  7.524377  +  1.256127  /  +  +  +";
string s27n25 = "( ( ( ( 1.537971 ) * ( ( ( ( ( ( 6.346600 ) / ( ( 3.212112 ) / ( 2.530887 ) ) ) / ( 7.916317 ) ) / ( ( ( 0.074101 ) / ( ( 2.654259 ) - ( 4.375222 ) ) ) * ( ( 9.316141 ) * ( 9.463504 ) ) ) ) - ( 9.110992 ) ) * ( 8.381909 ) ) ) - ( ( ( 3.770935 ) * ( ( 5.464691 ) * ( 0.517094 ) ) ) - ( ( ( 2.587561 ) / ( 7.533290 ) ) / ( ( 9.339901 ) - ( 4.260996 ) ) ) ) ) / ( ( ( 3.094853 ) * ( 7.949372 ) ) + ( ( 0.227666 ) / ( ( ( 5.227210 ) + ( 7.646366 ) ) / ( ( 3.669809 ) + ( 5.488568 ) ) ) ) ) )";
string s28n25 = "6.921287  9.364338  *  5.038233  -  2.223147  1.513019  *  /  8.621375  3.514391  1.044921  /  -  8.788044  /  6.018780  1.110416  /  *  *  4.004222  +  2.544881  /  0.672451  3.272697  +  0.108365  0.257409  -  +  /  7.300551  /  2.141078  4.770387  3.894807  2.296521  +  +  3.839127  +  /  -";
string s31n50 = "( ( ( ( ( 0.016298 ) * ( ( ( ( ( ( ( ( ( ( ( ( 5.451572 ) + ( ( 6.522725 ) + ( 4.053423 ) ) ) + ( 2.237167 ) ) * ( ( 6.761665 ) * ( ( 8.929393 ) + ( 3.288268 ) ) ) ) / ( 7.008292 ) ) + ( 8.866717 ) ) + ( ( ( ( 9.736813 ) + ( ( 2.670779 ) - ( 8.429765 ) ) ) + ( 9.916589 ) ) + ( 8.388820 ) ) ) / ( 5.781327 ) ) - ( ( 0.114987 ) / ( 9.796989 ) ) ) - ( ( 2.566517 ) * ( ( 7.189669 ) / ( 1.085716 ) ) ) ) + ( ( ( 3.230236 ) - ( ( ( 9.262806 ) + ( 4.472587 ) ) / ( 1.116756 ) ) ) - ( 4.147509 ) ) ) + ( 9.299896 ) ) ) - ( 6.391134 ) ) - ( ( ( ( ( 4.968851 ) / ( 5.251583 ) ) / ( 4.725458 ) ) * ( ( ( 2.956025 ) / ( 3.680148 ) ) * ( 2.821245 ) ) ) * ( ( 5.935397 ) + ( 2.565921 ) ) ) ) * ( ( 0.599650 ) * ( ( ( ( ( ( 7.011593 ) + ( 6.290626 ) ) - ( 3.518166 ) ) / ( 0.333738 ) ) + ( 8.825464 ) ) * ( 4.059770 ) ) ) )";
string s32n50 = "2.342714  1.593891  -  7.071505  4.295940  1.311853  /  /  /  8.478092  6.086205  1.222209  /  /  6.566263  +  +  0.680886  /  6.786631  9.872627  1.153884  4.121935  +  *  3.661410  7.945919  /  +  /  6.262245  /  1.472523  -  /  9.474712  -  8.790420  *  0.571940  -  1.206539  6.650772  5.021442  -  9.154527  4.583462  3.528287  1.337121  -  +  +  /  +  9.375970  4.801788  -  /  9.342030  +  *  5.569139  1.604180  0.433202  -  +  2.449991  7.813962  *  +  9.370613  -  7.560587  2.334843  /  +  /  2.951177  7.168814  4.356445  +  *  8.196940  0.316765  +  3.733626  -  0.271837  3.930631  /  -  8.246025  *  -  -";
string s33n50 = "( ( ( ( ( ( ( ( ( ( ( ( ( ( ( 3.461127 ) - ( 5.943645 ) ) * ( 3.140308 ) ) - ( 0.746398 ) ) - ( 8.456958 ) ) / ( ( 4.719017 ) - ( ( ( 1.644452 ) * ( ( 8.073503 ) - ( 2.344339 ) ) ) / ( 6.414608 ) ) ) ) * ( ( 3.051019 ) * ( ( 0.712890 ) + ( 6.291558 ) ) ) ) + ( ( 3.878003 ) / ( ( 7.913279 ) / ( 1.541493 ) ) ) ) / ( 7.365712 ) ) * ( ( ( ( 5.014324 ) + ( 2.640795 ) ) - ( ( 5.498433 ) * ( 9.519991 ) ) ) + ( ( ( ( 0.883213 ) + ( 0.780079 ) ) - ( 6.783750 ) ) / ( 7.192298 ) ) ) ) + ( ( 9.867027 ) * ( ( ( 7.628478 ) + ( 7.135689 ) ) + ( 8.805795 ) ) ) ) / ( ( ( 7.229676 ) - ( ( 5.435725 ) / ( 8.793706 ) ) ) - ( 7.458130 ) ) ) / ( ( ( 4.931007 ) + ( 8.159893 ) ) - ( 9.401758 ) ) ) + ( 5.028275 ) ) + ( ( 4.884630 ) + ( ( ( ( 5.784756 ) * ( 9.611727 ) ) / ( 7.639314 ) ) * ( ( 9.887426 ) - ( ( 5.562744 ) + ( ( 4.503729 ) * ( 9.833541 ) ) ) ) ) ) )";
string s34n50 = "5.421096  5.994954  +  9.850749  3.870445  /  0.180943  4.424075  +  /  -  0.959942  4.735286  0.012363  5.188554  *  1.604597  6.200929  /  2.710489  +  +  6.602122  2.532628  *  +  +  /  *  6.785506  8.556760  /  4.823591  /  *  4.084848  /  1.238227  /  4.709649  *  2.704791  6.902121  +  +  4.630609  *  6.821499  9.240256  *  3.919835  -  8.235619  4.467664  +  *  7.522925  -  6.712547  9.347121  /  4.098836  *  2.033259  -  *  6.353524  2.242587  +  1.197837  6.357018  *  /  *  7.071411  5.171337  *  *  4.699888  8.610830  8.674263  -  8.782070  *  1.470142  +  *  /  *";
string s35n50 = "( ( ( ( ( ( ( ( ( ( ( 6.430555 ) + ( ( 3.031694 ) / ( ( 6.240371 ) + ( ( ( 9.615488 ) + ( 0.391192 ) ) + ( 3.731624 ) ) ) ) ) + ( ( 3.146386 ) * ( 4.059826 ) ) ) / ( ( 9.476876 ) + ( ( ( 3.962499 ) / ( ( 5.579795 ) / ( 1.759955 ) ) ) - ( 1.688967 ) ) ) ) - ( 9.129420 ) ) + ( ( 9.326241 ) - ( ( 7.437738 ) * ( ( ( 4.704018 ) * ( 6.499125 ) ) * ( 6.389916 ) ) ) ) ) - ( 7.462131 ) ) + ( ( ( 9.911150 ) - ( 4.284252 ) ) * ( ( 4.203145 ) + ( ( ( 2.297352 ) / ( 9.094913 ) ) - ( 3.267839 ) ) ) ) ) - ( ( ( ( 7.096241 ) - ( 0.211192 ) ) + ( 4.551526 ) ) + ( 7.665444 ) ) ) + ( ( ( ( ( 1.765473 ) + ( 4.631388 ) ) / ( 1.236112 ) ) + ( ( 2.247799 ) - ( 3.926616 ) ) ) - ( ( ( 9.456899 ) - ( ( 7.511044 ) / ( ( 4.742804 ) * ( 8.997228 ) ) ) ) - ( 4.557919 ) ) ) ) - ( ( ( 7.674042 ) + ( ( 6.871605 ) + ( ( 1.445841 ) + ( 3.060410 ) ) ) ) - ( ( ( 6.362677 ) - ( ( 3.665044 ) / ( 6.127738 ) ) ) - ( 2.722264 ) ) ) )";
string s36n50 = "2.599367  9.647195  9.673411  9.050032  /  6.358308  -  8.651174  *  4.875167  2.911182  5.348410  2.736445  +  5.191413  *  -  -  *  *  1.915312  5.548351  2.050359  0.943320  +  *  +  +  5.181741  5.625093  *  *  8.694984  3.686034  /  9.440571  7.117509  /  +  -  9.446373  8.978700  /  3.580536  +  +  +  5.250495  1.305610  /  *  0.441742  6.502549  7.095268  4.133539  /  -  *  4.930346  2.550228  /  3.125103  *  4.950563  *  *  *  6.550852  6.671211  1.809183  +  /  3.824251  +  *  0.923045  4.509118  6.480367  /  0.074564  /  4.707001  -  +  4.743344  3.905694  2.327981  *  *  1.462779  -  *  + ";
string s37n50 = "( ( ( ( 3.704752 ) / ( ( ( ( ( ( 2.093473 ) - ( ( ( 0.656896 ) + ( ( ( 7.650847 ) / ( 8.517779 ) ) + ( 8.484577 ) ) ) / ( ( 3.570724 ) + ( ( 6.603947 ) / ( 2.708906 ) ) ) ) ) * ( ( ( ( 3.016434 ) / ( ( ( ( 2.070670 ) / ( 2.665045 ) ) + ( 1.967283 ) ) + ( 7.795605 ) ) ) - ( 4.774478 ) ) - ( ( 6.962198 ) * ( 3.061824 ) ) ) ) + ( ( ( 9.850194 ) * ( 1.000052 ) ) * ( 9.909937 ) ) ) - ( 0.916214 ) ) * ( ( ( ( 4.766712 ) / ( ( 5.124133 ) - ( ( 3.814624 ) / ( 1.406076 ) ) ) ) - ( ( 3.346784 ) / ( 1.001288 ) ) ) - ( 7.251864 ) ) ) ) + ( ( ( 1.967363 ) - ( ( 3.966477 ) * ( 9.794267 ) ) ) - ( ( ( ( 0.469069 ) / ( 5.014094 ) ) * ( 5.376427 ) ) + ( ( ( ( ( 3.885523 ) * ( 4.918825 ) ) / ( 0.137457 ) ) - ( 4.551664 ) ) - ( ( 2.848862 ) / ( 3.331082 ) ) ) ) ) ) / ( ( 5.881610 ) * ( ( 2.011348 ) + ( ( ( 6.988997 ) / ( 1.617092 ) ) - ( 6.379946 ) ) ) ) )";
string s38n50 = "2.668160  3.299435  5.577647  7.362147  *  7.919122  *  8.490275  8.332728  2.033447  *  /  -  /  /  2.387488  0.684457  4.372958  2.226028  /  8.153083  +  *  -  +  8.386214  /  9.354012  6.724427  *  1.525728  6.133841  2.985069  -  -  8.340931  -  1.530226  +  *  *  1.269565  2.045418  /  9.573261  +  7.561658  *  -  7.381152  /  6.284854  4.061986  /  /  5.954917  1.260094  8.387910  +  6.903085  /  5.802291  -  2.891419  -  *  2.144825  4.160590  *  /  6.450664  3.949879  /  7.150766  +  +  *  2.942184  8.179270  -  0.803171  9.760576  *  5.895433  /  -  8.016547  -  *";

string parentesisExtra = "( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
string parentesisFaltando = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986  + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
string pontoDecimalExtra = "( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.16.5881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
string operadorExtra = "( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) / ) ) )";
string numeroExtra = "( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) (4.253098 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";

// cout << "Infixo '1 1': " << verificaInfixo("1 1") << endl; // TODO: bug - verificaInfixo não lida com casos assim
// cout << "Posfixo '1 1': " << verificaPosfixo("1 1") << endl;

TEST_CASE("Verificador Infixo faz asserções corretas") {
  SUBCASE("Casos base") {
    CHECK(verificaInfixo(s1n5) == true);
    CHECK(verificaInfixo(s3n5) == true);
    CHECK(verificaInfixo(s5n5) == true);
    CHECK(verificaInfixo(s7n5) == true);
    CHECK(verificaInfixo(s11n10) == true);
    CHECK(verificaInfixo(s13n10) == true);
    CHECK(verificaInfixo(s15n10) == true);
    CHECK(verificaInfixo(s17n10) == true);
    CHECK(verificaInfixo(s21n25) == true);
    CHECK(verificaInfixo(s23n25) == true);
    CHECK(verificaInfixo(s25n25) == true);
    CHECK(verificaInfixo(s27n25) == true);
    CHECK(verificaInfixo(s31n50) == true);
    CHECK(verificaInfixo(s33n50) == true);
    CHECK(verificaInfixo(s35n50) == true);
    CHECK(verificaInfixo(s37n50) == true);    
  }
    
  SUBCASE("Casos incorretos") {
    CHECK(verificaInfixo(parentesisExtra) == false);
    CHECK(verificaInfixo(parentesisFaltando) == false);
    CHECK(verificaInfixo(pontoDecimalExtra) == false);
    CHECK(verificaInfixo(operadorExtra) == false);
    CHECK(verificaInfixo(numeroExtra) == false);
  }

  SUBCASE("Casos borda") {
    CHECK(verificaInfixo("") == false);
    CHECK(verificaInfixo("caracteres inválidos") == false);
    WARN(verificaInfixo("1 1") == false); // sem pontos decimais!!
  }
}

TEST_CASE("Verificador Posfixo faz asserções corretas") {
  SUBCASE("Casos base") {
    CHECK(verificaPosfixo(s2n5) == true);
    CHECK(verificaPosfixo(s4n5) == true);
    CHECK(verificaPosfixo(s6n5) == true);
    CHECK(verificaPosfixo(s8n5) == true);
    CHECK(verificaPosfixo(s12n10) == true);
    CHECK(verificaPosfixo(s14n10) == true);
    CHECK(verificaPosfixo(s16n10) == true);
    CHECK(verificaPosfixo(s18n10) == true);
    CHECK(verificaPosfixo(s22n25) == true);
    CHECK(verificaPosfixo(s24n25) == true);
    CHECK(verificaPosfixo(s26n25) == true);
    CHECK(verificaPosfixo(s28n25) == true);
    CHECK(verificaPosfixo(s32n50) == true);
    CHECK(verificaPosfixo(s34n50) == true);
    CHECK(verificaPosfixo(s36n50) == true);
    CHECK(verificaPosfixo(s38n50) == true);
  }

  SUBCASE("Casos borda") {
    CHECK(verificaPosfixo("") == false);
    CHECK(verificaPosfixo("caracteres inválidos") == false);
    CHECK(verificaPosfixo("1 1") == false); // sem pontos decimais!!
  }

  SUBCASE("Casos incorretos") {
    CHECK(verificaPosfixo(parentesisExtra) == false);
    CHECK(verificaPosfixo(parentesisFaltando) == false);
    CHECK(verificaPosfixo(pontoDecimalExtra) == false);
    CHECK(verificaPosfixo(operadorExtra) == false);
    CHECK(verificaPosfixo(numeroExtra) == false);
  }
}

TEST_CASE("Classe Pilha funciona como esperado") {
  Pilha pilha;
  REQUIRE(pilha.estaVazia() == true); // pilha inicializa vazia

  SUBCASE("Método empilhar adiciona elementos à pilha corretamente") {
    pilha.empilhar("(");
    pilha.empilhar("3.1253");
    pilha.empilhar("4.86529");
    pilha.empilhar("+");
    pilha.empilhar("2.72912");
    pilha.empilhar("*");
    pilha.empilhar(")");

    CHECK(pilha.desempilhar() == ")");
    CHECK(pilha.desempilhar() == "*");
    CHECK(pilha.desempilhar() == "2.72912");
    CHECK(pilha.desempilhar() == "+");
    CHECK(pilha.desempilhar() == "4.86529");
    CHECK(pilha.desempilhar() == "3.1253");
    CHECK(pilha.desempilhar() == "("); // desempilha na ordem esperada
  }

  SUBCASE("Método limpar remove todos os elementos da pilha") {
    pilha.empilhar("(");
    pilha.empilhar("3.1253");
    pilha.empilhar("4.86529");
    pilha.empilhar("+");
    pilha.empilhar("2.72912");
    pilha.empilhar("*");
    pilha.empilhar(")");

    pilha.limpar();
    CHECK(pilha.estaVazia() == true);
  }
}

TEST_CASE("Classe Fila funciona como esperado") {
  Fila fila;
  REQUIRE(fila.estaVazia() == true); // fila inicializa vazia

  SUBCASE("Método enfileirar adiciona elementos à fila corretamente") {
    fila.enfileirar("(");
    fila.enfileirar("3.1253");
    fila.enfileirar("4.86529");
    fila.enfileirar("+");
    fila.enfileirar("2.72912");
    fila.enfileirar("*");
    fila.enfileirar(")");

    CHECK(fila.desenfileirar() == "(");
    CHECK(fila.desenfileirar() == "3.1253");
    CHECK(fila.desenfileirar() == "4.86529");
    CHECK(fila.desenfileirar() == "+");
    CHECK(fila.desenfileirar() == "2.72912");
    CHECK(fila.desenfileirar() == "*");
    CHECK(fila.desenfileirar() == ")"); // desefileira na ordem esperada
  }

  SUBCASE("Método limpar remove todos os elementos da fila") {
    fila.enfileirar("(");
    fila.enfileirar("3.1253");
    fila.enfileirar("4.86529");
    fila.enfileirar("+");
    fila.enfileirar("2.72912");
    fila.enfileirar("*");
    fila.enfileirar(")");

    fila.limpar();
    CHECK(fila.estaVazia() == true);
  }
}


TEST_CASE("TokenIdentifier separa termos de uma expressão numérica") {
  SUBCASE("(3.2 + 6.5) * (2.1 - 4.7) + 7.9") {
    string expressao = "(3.2 + 6.5) * (2.1 - 4.7) + 7.9";
    Fila testCase = tokenIdentifier(expressao);
    string outputCorreto = "(3.2+6.5)*(2.1-4.7)+7.9";
    string outputTeste = "";
    int tamanho = testCase.sizeOf();

    for (int i = 0; i < tamanho; i++) {
      outputTeste += testCase.desenfileirar();
    }

    CHECK(outputCorreto == outputTeste);
  }

   SUBCASE("s1n5") {
    Fila testCase = tokenIdentifier(s1n5);
    string outputCorreto = "((((9.904341)+((5.733451)-(0.641665)))-((2.165881)+(1.404730)))-((5.732986)+((5.938726)-(8.993233))))";
    string outputTeste = "";
    int tamanho = testCase.sizeOf();

    for (int i = 0; i < tamanho; i++) {
      outputTeste += testCase.desenfileirar();
    }

    CHECK(outputCorreto == outputTeste);
  }
} 

TEST_CASE("shuntingYard funciona corretamente") {
  SUBCASE("(3 + 6) * (2 - 4) + 7") {
    string expressao = "(3 + 6) * (2 - 4) + 7";
    Fila testCase = tokenIdentifier(expressao);
    string outputCorreto = "3 6 + 2 4 - * 7 + ";
    Fila posfixo = shuntingYard(testCase);
    string outputTeste = "";
    int tamanho = posfixo.sizeOf();
    
    for (int i = 0; i < tamanho; i++) {
      outputTeste += posfixo.desenfileirar();
      outputTeste += " ";
    }
    CHECK(outputTeste == outputCorreto);
  }

  SUBCASE("s1n5") {
    Fila testCase = tokenIdentifier(s1n5);
    string outputCorreto = "9.904341 5.733451 0.641665 - + 2.165881 1.404730 + - 5.732986 5.938726 8.993233 - + - ";
    Fila posfixo = shuntingYard(testCase);
    string outputTeste = "";
    int tamanho = posfixo.sizeOf();
    
    for (int i = 0; i < tamanho; i++) {
      outputTeste += posfixo.desenfileirar();
      outputTeste += " ";
    }
    CHECK(outputTeste == outputCorreto);
  }
}
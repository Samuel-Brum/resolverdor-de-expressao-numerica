#ifndef EXPRESSAO_HPP
#define EXPRESSAO_HPP

#include <iostream>
#include <string>

#include "fila.hpp"
#include "pilha.hpp"
#include "shuntingYard.hpp"

using std::string;

class Parser {
public:

  /// @brief Construtor da classe, inicializa elementos vazios
  Parser();

  /// @brief O programa deve armazenar essa expressão utilizando uma estrutura
  /// de dados apropriada, cuja definição faz parte do trabalho. Ao se ler uma
  /// nova expressão a expressão anterior deve ser apagada. O programa deve
  /// verificar se a expressão é válida antes de armazenar a mesma e só deve
  /// armazenar a expressão se esta for válida (seja em notação infixa ou posfixa).
  /// @param exp Uma string com no máximo 1000 caracteres, onde os números
  /// e operadores estão separados por espaço.
  /// @param print Opcional, default = true. Faz com que a expressão imprima mensagens
  /// no terminal.
  /// @return 'EXPRESSAO OK : <EXP>' - caso a expressão seja lida e armazenada com sucesso;
  /// 'ERRO : EXP NAO VALIDA' - caso a expressão não veja válida e não armazenada.
  void ler(string exp, bool print = true);

  /// @brief Operação de converter a expressão armazenada no programa para
  /// notação infixa (notação usual). Esta operação deve acrescentar os
  /// parênteses necessários.
  /// @return 'INFIXA : <EXP>' - caso a conversão seja realizada com sucesso;
  /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
  void infixa();

  /// @brief Operação de converter a expressão armazenada no programa
  /// para notação posfixa (notação polonesa).
  /// @return 'POSFIXA : <EXP>' - caso a conversão seja realizada com sucesso;
  /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
  void posfixa();

  /// @brief Operação de resolver a expressão armazenada no programa.
  /// Esta operação deve computar o valor representado pela expressão
  /// armazenada no programa.
  /// @return 'VAL : <EXP>' - caso a conversão seja realizada com sucesso;
  /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
  void resolve();

private:

  Fila expInterna;
  string expInfixa;
  string expPosfixa;
};

#endif
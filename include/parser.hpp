#ifndef EXPRESSAO_HPP
#define EXPRESSAO_HPP

#include <iostream>
#include <string>

using std::string;

class Parser {
  public:

    // TVZ DESNECESSARIO mater apenas ler
    /// @brief cria a arvore binária a partir de uma string
    /// @param exp 
    Parser(string exp);
  
    /// @brief O programa deve armazenar essa expressão utilizando uma estrutura
    /// de dados apropriada, cuja definição faz parte do trabalho. Ao se ler uma
    /// nova expressão a expressão anterior deve ser apagada. O programa deve
    /// verificar se a expressão é válida antes de armazenar a mesma e só deve
    /// armazenar a expressão se esta for válida (seja em notação infixa ou posfixa).
    /// @param exp Uma string com no máximo 1000 caracteres, onde os números
    /// e operadores estão separados por espaço.
    /// @return 'EXPRESSAO OK : <EXP>' - caso a expressão seja lida e armazenada com sucesso;
    /// 'ERRO : EXP NAO VALIDA' - caso a expressão não veja válida e não armazenada.
    int ler(string exp);

    /// @brief Operação de converter a expressão armazenada no programa para
    /// notação infixa (notação usual). Esta operação deve acrescentar os
    /// parênteses necessários.
    /// @return 'INFIXA : <EXP>' - caso a conversão seja realizada com sucesso;
    /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
    int infixa();
    
    /// @brief Operação de converter a expressão armazenada no programa
    /// para notação posfixa (notação polonesa).
    /// @return 'POSFIXA : <EXP>' - caso a conversão seja realizada com sucesso;
    /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
    int posfixa();
    
    /// @brief Operação de resolver a expressão armazenada no programa.
    /// Esta operação deve computar o valor representado pela expressão
    /// armazenada no programa.

    /// @return 'POSFIXA : <VAL>' - caso a conversão seja realizada com sucesso;
    /// 'ERRO : EXP NAO EXISTE' - caso não haja expressão armazenada.
    float resolve();

  private:
    string exp;
    // <structQualquer> arvore
};

#endif
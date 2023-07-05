# Resolvedor de Expressões Numéricas
Análise sintática é um procedimento em que uma string de símbolos é transformada em
uma estrutura de dados que retenha e reflita, de alguma forma, o significado da expressão
original. 

Há várias formas de escrever uma mesma expressão numérica. O mais comumente
utilizado por pessoas é a notação infixa, na qual os números, ou operandos, são separados
por um operador binário que atua sobre eles, gerando um novo operando. Já na notação
polonesa reversa, ou notação pósfixa, os operadores atuam sobre os dois operandos que o
antecede. Essa última convenção é bastante utilizada para a representação de expressões
em máquinas, por motivos que ficarão claros até o final deste relatório.

Aqui foram implementadas classes simples de pilhas e filas para implementar o algoritmo 
Shunting-yard para a conversão de notação infixa para pósfixa.

# Utilização do makefile
* `make all`: compila tanto testes quanto o programa
* `make run`: compila e executa apenas o programa
* `make test`: compila e executa apenas os testes
* `make clean`: remove binarios e arquivos objeto

# Execução do programa

Executar bin/expressaoNumerica irá entrar em um loop infinito no qual o usuário
pode inserir comandos. Seguindo a especificação mais recente até a data de entrega eles
são:

* `LER INFIXA <EXP> INFIXA`
* `LER POSFIXA <EXP> POSFIXA`
* `RESOLVE`

Os dois primeiros comandos são mapeados à mesma função dentro do main, pois a
especificação original previa apenas a função LER. Sendo assim, foi implementado um
verificador de função que também serve para identificar qual é o caso da expressão, infixa
ou pósfixa.
Essencialmente, a entrada de cada linha é mapeada a um dos comandos especificados,
caso eles estejam de acordo, e então um método da classe Parser é chamada para atender
o comando específico utilizado. Os métodos da classe Parser chamam outras subrotinas
de diversas classes auxiliares, localizadas em outros arquivos.

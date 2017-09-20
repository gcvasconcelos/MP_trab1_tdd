# Trabalho de Métodos de Programação

O objetivo deste trabalho é utilizar o desenvolvimento orientado a testes (TDD) para fazer uma calculadora que utiliza uma string como entrada para fazer a soma dos termos separados por um delimitador. 
O framework de testes escolhido foi o [Catch](https://github.com/philsquared/Catch/blob/master/docs/tutorial.md).

## Especificação

A função deverá ter o formato:

	int soma_string(char * string_entrada )

A string poderá conter qualquer quantidade de números. Em cada linha se pode ter 0, 1, 2 ou 3 números. Os números são separados por exatamente um delimitador que no caso é a vírgula. Qualquer separador diferente é considerado erro a menos que tenha sido
adicionado como delimitador. 
Números negativos são proibidos. Se houver um número negativo retorna -1
Os números maiores que 1000 são ignorados. Ex. ‘3,2000\n’ dá resultado 3. 
Você pode especificar um novo delimitador na primeira linha com
“//[delimitador]\n[numeros…]” ex. “//[;]\n2;3\n” faz com que o ‘;’ passe a ser um separador válido assim, dá resultado 5.
Um delimitador pode ter qualquer tamanho
Ex:

	“//[***]\n2***3***4\n” retorna 9
	“//[***]2***3***4\n” é invalido pois falta ‘\n’ retorna -1

A linha que especifica os separadores é opcional mas se existir ela tem de estar no formato correto. 
Pode haver qualquer número de delimitadores especificados e de qualquer tamanho.
Ex:
	
	“//[delimitador1][delimitador2]\n” for example “//[**][%%%]\n2**1%%%3\n” retorna 6 

## Testes

A descrição dos testes e o que passar nestes testes significa está presente no corpo do código do arquivo onde os testes aconteceram.
O motivo da separação dos arquivos testa_config.cpp e testa_string_soma.cpp está explicado no corpo do arquivo testa_config.cpp.
A documentação do resto do código está no documento html gerado pelo Doxygen e está na pasta dowygen_hmtl/

## Makefile

O makefile possui uma condicional que separa o módulo de testes (make TESTE=1) e o módulo de produção (make). Existe também uma regra 'make gcov' que gera os arquivos do gcov.

## Gcov

De acordo com o arquivo gerado pelo gcov (./coverage.hmtl), os testes cobrem 100% do código da função presente no arquivo string_soma.cpp. Ja as Branches, são cobertas em 92%. Os outros arquivos mostram porcentagens menores pois são os arquivos do framework de teste usado, o Catch
/** @file */ 
/**
 * Configuração do ambiente de testes utilizando o framework de testes automatizados Catch para C++.
 * O arquivo está separado dos testes, pois a main() provida pelo Catch só precisa ser compilada um vez. Aqui, todo conjunto de headers do Catch é compilado, sendo um processo custoso e demorado. Separando a main() dos testes, o tempo de compilação é diminuido consideravelmente, já que dessa forma, apenas os testes são recompilados.
 * O ambiente de testes é compilado por meio do comando no terminal "make TESTE=1".
 */

#define CATCH_CONFIG_MAIN  /**< Pede para o Catch prover uma main() preparada para rodar os testes. */
#include "headers/catch.hpp"

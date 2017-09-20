#include "headers/catch.hpp"
#include "headers/string_soma.hpp"
/** @file */ 
/**
 * Para o desenvolvimento dá função soma_string(), foi praticada a seguinte metodologia: escrever testes em que a função espera um valor de falha; refatorar a função para passar no teste; passar nos testes; escrever novos testes.
 * Desta forma, foi escolha do autor do código, primeiramente garantir que argumento de entrada da função fosse válido e somente depois, fazer a soma dos números efetivamente. Por esse motivo, os casos positivos (que a função retorna algo diferente de -1) estão no final dos testes.
 */
TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	/**
	 * Testa a presença do \\n no final de toda entrada.
	 */
  SECTION("\\n no final"){
    REQUIRE(soma_string("") == -1);
		REQUIRE(soma_string("1") == -1);
    REQUIRE(soma_string("\n1") == -1);
	}
  /**
   * Testa se existem mais de 3 numeros por linha.
   */
	SECTION("Tem de 0 a 3 numeros por linha") {
    REQUIRE(soma_string("1,1,1,1\n") == -1);
		REQUIRE(soma_string("1,1,1,1,1\n") == -1);
    REQUIRE(soma_string("\n1,1,1,1\n") == -1);
	}
  /**
   * Testa a validade do delimitador, ou seja, se está sempre acompanhado de um número antes e outro depois.
   */
	SECTION("Numero antes e depois de todo delimitador") {
		REQUIRE(soma_string("1,\n") == -1);
		REQUIRE(soma_string(",1\n") == -1);
		REQUIRE(soma_string("1,,1\n") == -1);
		REQUIRE(soma_string(",\n") == -1);
	}
  /**
   * Testa se o número é positivo. Teste passa se delimitador eh '-'.
   */
	SECTION("Numero eh positivo") {
		REQUIRE(soma_string("-1\n") == -1);
		REQUIRE(soma_string("1,-1\n") == -1);
	}
  /**
   * Testa se numeros maiores que 1000 são ignorados
   */
  SECTION("Numero maiores que 1000 sao ignorados") {
    REQUIRE(soma_string("1001\n") == 0);
    REQUIRE(soma_string("1,1001\n") == 1);
    REQUIRE(soma_string("1,\n1001\n") == 1);
    REQUIRE(soma_string("1001,\n1001\n") == 0);
  }
  /**
   * Testa que delimitador pode variar do padrão (',') se for inserido corretamente, ou seja, se segue o modelo '//[...]\n...\n'
   */
  SECTION("Delimitador variavel") {
    REQUIRE(soma_string("1 1\n") == -1);
    REQUIRE(soma_string("1@1\n") == -1);
    REQUIRE(soma_string("[@]1@1\n") == -1);
    REQUIRE(soma_string("[@]\n1@1\n") == -1);
    REQUIRE(soma_string("/[@]\n1@1\n") == -1);
    REQUIRE(soma_string("//[@]1@1\n") == -1);
  }
  /**
   * Testa casos positivos, ou seja, que seguem a especificação, dos testes anteriores
   */
  SECTION("Operação de soma") { 
  	REQUIRE(soma_string("\n") == 0);
		REQUIRE(soma_string("1\n") == 1);
		REQUIRE(soma_string("1,1,1\n") == 3);
		REQUIRE(soma_string("\n1,1\n") == 2);
		REQUIRE(soma_string("\n\n1,1\n") == 2);
		REQUIRE(soma_string("1\n,1,1\n") == 3);
		REQUIRE(soma_string("1,\n1,1\n,1,1,1\n") == 6);
		REQUIRE(soma_string("1\n\n\n,1\n") == 2);
		REQUIRE(soma_string("1\n\n\n,\n\n\n1\n") == 2);
    REQUIRE(soma_string("11\n") == 11);
    REQUIRE(soma_string("111\n") == 111);
    REQUIRE(soma_string("1000\n") == 1000); 
    REQUIRE(soma_string("//[@]\n1@1\n") == 2);
    REQUIRE(soma_string("//[#]\n1#1\n") == 2);
    REQUIRE(soma_string("//[-]\n1-1\n") == 2);
    REQUIRE(soma_string("//[@@]\n1@@1\n") == 2);
    REQUIRE(soma_string("//[@@@]\n1@@@1\n") == 2);
    REQUIRE(soma_string("//[#$%]\n1#$%1\n") == 2);
  }
}
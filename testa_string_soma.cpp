#include "headers/catch.hpp"
#include "headers/string_soma.hpp"
/** @file */ 
/**
 * Para o desenvolvimento dá função soma_string(), foi praticada a seguinte metodologia: escrever testes em que a função espera um valor de falha; refatorar a função para passar no teste; passar nos testes; escrever novos testes.
 * Desta forma, foi escolha do autor do código, primeiramente garantir que argumento de entrada da função fosse válido e somente depois, fazer a soma dos números efetivamente. Por esse motivo, os casos positivos (que a função retorna algo diferente de -1) estão no final dos testes.
 */
TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	/**
	 * Testa o \n no final de toda entrada.
	 */
  SECTION("\\n no final"){
    CHECK(soma_string("") == -1);
		CHECK(soma_string("1") == -1);
    CHECK(soma_string("\n1") == -1);
	}
  /**
   * Testa a quantidade de números por linha, sendo de 0 a 3.
   */
	SECTION("Tem de 0 a 3 numeros por linha") {
    CHECK(soma_string("1,1,1,1\n") == -1);
		CHECK(soma_string("1,1,1,1,1\n") == -1);
    CHECK(soma_string("\n1,1,1,1\n") == -1);
	}
  /**
   * Testa a validade do delimitador, ou seja, se está sempre acompanhado de um número antes e outro depois.
   */
	SECTION("Numero antes e depois de todo delimitador") {
		REQUIRE(soma_string("1,\n") == -1);
		CHECK(soma_string(",1\n") == -1);
		CHECK(soma_string("1,,1\n") == -1);
		CHECK(soma_string(",\n") == -1);
	}
  /**
   * Testa se o número é positivo.
   */
	SECTION("Numero eh positivo") {
		CHECK(soma_string("-1\n") == -1);
		CHECK(soma_string("1,-1\n") == -1);
	}
  /**
   * Testa se numeros maiores que 1000 são ignorados
   */
  SECTION("Numero maiores que 1000 sao ignorados") {
    CHECK(soma_string("1001\n") == 0);
    CHECK(soma_string("1,1001\n") == 1);
    CHECK(soma_string("1,\n1001\n") == 1);
    CHECK(soma_string("1001,\n1001\n") == 0);
  }
  /**
   * Testa que delimitador pode variar do padrão (',') se for inserido corretamente.
   */
  SECTION("Delimitador variavel") {
    CHECK(soma_string("1 1\n") == -1);
    CHECK(soma_string("1@1\n") == -1);
    CHECK(soma_string("[@]1@1\n") == -1);
    CHECK(soma_string("[@]\n1@1\n") == -1);
    CHECK(soma_string("/[@]\n1@1\n") == -1);
    CHECK(soma_string("//[@]1@1\n") == -1);
  }
  /**
   * Testa casos positivos dos testes anteriores
   */
  SECTION("Operação de soma") { 
  	SECTION("Casos positivos para os testes anteriores") {	
	  	CHECK(soma_string("\n") == 0);
  		CHECK(soma_string("1\n") == 1);
  		CHECK(soma_string("1,1,1\n") == 3);
  		CHECK(soma_string("\n1,1\n") == 2);
  		CHECK(soma_string("\n\n1,1\n") == 2);
  		CHECK(soma_string("1\n,1,1\n") == 3);
  		CHECK(soma_string("1,\n1,1\n,1,1,1\n") == 6);
  		CHECK(soma_string("1\n\n\n,1\n") == 2);
  		CHECK(soma_string("1\n\n\n,\n\n\n1\n") == 2);
	    CHECK(soma_string("11\n") == 11);
	    CHECK(soma_string("111\n") == 111);
	    CHECK(soma_string("1000\n") == 1000); 
	    CHECK(soma_string("//[@]\n1@1\n") == 2);
	    CHECK(soma_string("//[#]\n1#1\n") == 2);
	    CHECK(soma_string("//[-]\n1-1\n") == 2);
	    CHECK(soma_string("//[@@]\n1@@1\n") == 2);
	    CHECK(soma_string("//[@@@]\n1@@@1\n") == 2);
	    CHECK(soma_string("//[#$%]\n1#$%1\n") == 2);
  	}
  }
}
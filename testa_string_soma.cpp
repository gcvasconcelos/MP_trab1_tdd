#include "headers/catch.hpp"
#include "headers/string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	SECTION("Formatacao da entrada") {
		SECTION("\\n no final"){
			CHECK(soma_string("") == -1);
			CHECK(soma_string("\n") != -1);
		}
		SECTION("Tem de 0 a 3 numeros por linha") {
			CHECK(soma_string("1,1,1,1\n") == -1);
			CHECK(soma_string("1,\n1,1,1,1\n") == -1);
			CHECK(soma_string("1\n") != -1);
			CHECK(soma_string("1,1,1\n") != -1);
			CHECK(soma_string("\n1,1\n") != -1);
      		CHECK(soma_string("\n\n1,1\n") != -1);
      		CHECK(soma_string("1\n,1,1\n") != -1);
			CHECK(soma_string("1,\n1,1\n,1,1,1\n") != -1);
		}
		SECTION("Numero antes e depois de todo delimitador") {
			CHECK(soma_string("1,\n") == -1);
			CHECK(soma_string(",1\n") == -1);
			CHECK(soma_string("1,,1\n") == -1);
			CHECK(soma_string(",\n") == -1);
			SECTION("\\n sao ignorados na contagem") {
				CHECK(soma_string("1\n\n\n,1\n") != -1);
				CHECK(soma_string("1\n\n\n,\n\n\n1\n") != -1);
			}
		}
		SECTION("Numero eh positivo") {
			CHECK(soma_string("-1\n") == -1);
			CHECK(soma_string("1,-1\n") == -1);
		}
    SECTION("Numero pode ter mais de um algarismo"){
      CHECK(soma_string("11\n") != -1);
      CHECK(soma_string("111\n") != -1);
      CHECK(soma_string("1000\n") != -1); 
    }
		SECTION("Numero eh menor ou igual a 1000"){
			CHECK(soma_string("1001\n") == -1);
			CHECK(soma_string("10000\n") == -1);
			CHECK(soma_string("1000\n") != -1);
		}
	}
  // SECTION("Delimitador variavel") {
  //   CHECK(soma_string("1@1\n") == -1);
  //   CHECK(soma_string("[@]1@1\n") == -1);
  //   CHECK(soma_string("[@]\n1@1\n") == -1);
  //   CHECK(soma_string("/[@]\n1@1\n") == -1);
  //   CHECK(soma_string("//[@]\n1@1\n") != -1);
  //   CHECK(soma_string("//[@@@]\n1@@@1\n") != -1);
  //   CHECK(soma_string("//[-]\n1-1\n") != -1);
  // }
}
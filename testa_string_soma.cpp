#include "catch.hpp"
#include "string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	SECTION("Formatacao da entrada") {
		SECTION("\\n no final"){
			REQUIRE(soma_string("") == -1);
			REQUIRE(soma_string("\n") != -1);
		}
		SECTION("Delimitador eh a ','") {
			REQUIRE(soma_string("1 1\n") == -1);
			REQUIRE(soma_string("1@1\n") == -1);
			REQUIRE(soma_string("1,1\n") != -1);
		}
		SECTION("Tem de 0 a 3 numeros por linha") {
			REQUIRE(soma_string("1,1,1,1\n") == -1);
			REQUIRE(soma_string("1,1,1,1,1\n") == -1);
			REQUIRE(soma_string("\n1,1,1,1\n") == -1);
			REQUIRE(soma_string("1\n") != -1);
			REQUIRE(soma_string("1,1,1\n") != -1);
			REQUIRE(soma_string("\n1,1\n") != -1);
			REQUIRE(soma_string("\n\n1,1\n") != -1);
		}
		SECTION("Numero antes e depois de todo delimitador") {
			REQUIRE(soma_string("1,\n") == -1);
			REQUIRE(soma_string(",1\n") == -1);
			REQUIRE(soma_string("1,,1\n") == -1);
			REQUIRE(soma_string(",\n") == -1);
			SECTION("\\n sao ignorados na contagem") {
				REQUIRE(soma_string("1\n\n\n,1\n") != -1);
				REQUIRE(soma_string("1\n\n\n,\n\n\n1\n") != -1);
			}
		}
		SECTION("Numero eh positivo") {
			REQUIRE(soma_string("-1\n") == -1);
			REQUIRE(soma_string("1,-1\n") == -1);
		}
	}
}
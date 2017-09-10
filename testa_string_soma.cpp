#include "catch.hpp"
#include "string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	SECTION("Formatacao da entrada") {
		SECTION("\\n no final"){
			REQUIRE(soma_string("") == -1);
			REQUIRE(soma_string("\n") != -1);
		}
		SECTION("Delimitador é a ','"){
			REQUIRE(soma_string("1 1\n") == -1);
			REQUIRE(soma_string("1,1\n") != -1);
		}
	}
	SECTION("Calculo da soma"){
	}
}
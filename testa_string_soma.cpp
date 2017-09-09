#include "catch.hpp"
#include "string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	SECTION("Formatacao da entrada") {
		SECTION("\n no final"){
			CHECK(soma_string("") == -1);
			CHECK(soma_string("\n") != -1);
		}
	}
}
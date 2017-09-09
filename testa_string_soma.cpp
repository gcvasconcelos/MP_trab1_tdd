#include "catch.hpp"
#include "string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[soma]") {
	REQUIRE( soma_string(0) == 0 );
}
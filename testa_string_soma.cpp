#include "headers/catch.hpp"
#include "headers/string_soma.hpp"

TEST_CASE("Calculadora simples de soma", "[calculadora][soma]") {
	SECTION("Formatacao da entrada") {
		SECTION("\\n no final"){
			CHECK(soma_string("") == -1);
		}
		SECTION("Tem de 0 a 3 numeros por linha") {
			CHECK(soma_string("1,1,1,1\n") == -1);
			CHECK(soma_string("1,\n1,1,1,1\n") == -1);
		}
		SECTION("Numero antes e depois de todo delimitador") {
			REQUIRE(soma_string("1,\n") == -1);
			CHECK(soma_string(",1\n") == -1);
			CHECK(soma_string("1,,1\n") == -1);
			CHECK(soma_string(",\n") == -1);
		}
		SECTION("Numero eh positivo") {
			CHECK(soma_string("-1\n") == -1);
			CHECK(soma_string("1,-1\n") == -1);
		}
	}
  SECTION("Delimitador variavel") {
    CHECK(soma_string("1@1\n") == -1);
    CHECK(soma_string("[@]1@1\n") == -1);
    CHECK(soma_string("[@]\n1@1\n") == -1);
    CHECK(soma_string("/[@]\n1@1\n") == -1);
    CHECK(soma_string("//[@]1@1\n") == -1);
  }
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
  	}
    SECTION("Numero maiores que 1000 sao ignorados") {
      CHECK(soma_string("1001\n") == 0);
      CHECK(soma_string("1,1001\n") == 1);
      CHECK(soma_string("1,\n1001\n") == 1);
      CHECK(soma_string("1001,\n1001\n") == 0);
    }
  }
}
CC = g++
LIBS = -lm
# para o módulo de testes: 'make TESTE=1' 
ifeq ($(TESTE), 1)
TARGET := test
OBJECTS = obj/testa_config.o obj/string_soma.o obj/testa_string_soma.o
HEADERS = headers/catch.hpp headers/string_soma.hpp
FLAGS = -g -Wall -Wextra -Weffc++ -ftest-coverage -fprofile-arcs
# para o módulo normal: 'make'
else
TARGET = testa_soma_string_stdin
OBJECTS = obj/string_soma.o obj/testa_soma_string_stdin.o
HEADERS = 
FLAGS = -g -Wall -Wextra -Weffc++
endif

obj/%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) $(LIBS) -o $@

.PHONY: clean gcov
clean:
	-rm -f obj/*.o
	-rm -f obj/*.gcno
	-rm -f obj/*.gcda
	-rm test
	-rm testa_soma_string_stdin
# para gerar os arquivos html do gcov
gcov:
	gcovr -r . --html -o coverage.html --html-details
CC = g++
LIBS = -lm

ifeq ($(TESTE), 1)
TARGET = test
OBJECTS = obj/testa_config.o obj/string_soma.o obj/testa_string_soma.o
HEADERS = headers/catch.hpp headers/string_soma.hpp
FLAGS = -g -Wall -Wextra -Weffc++ -ftest-coverage -fprofile-arcs
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

.PHONY: clean
clean:
	-rm -f obj/*.o
	-rm -f obj/*.gcno
	-rm -f obj/*.gcda
	-rm -f $(TARGET)
gcov:
	gcovr -r . --html -o coverage.html --html-details
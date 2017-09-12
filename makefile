TARGET = prog
CC = g++
LIBS = -lm

ifeq ($(TESTE), 1)
OBJECTS = obj/testa_config.o obj/string_soma.o obj/testa_string_soma.o
HEADERS = headers/catch.hpp headers/string_soma.hpp
FLAGS = -g -Wall -Wextra -Weffc++ 
else
OBJECTS = obj/string_soma.o obj/testa_soma_string_stdin.o
HEADERS = 
FLAGS = -g -Wall -Wextra -Weffc++ -ftest-coverage -fprofile-arcs
endif

obj/%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) $(LIBS) -o $@

.PHONY: clean
clean:
	-rm -f obj/*.o
	-rm -f obj/*.gcno
	-rm -f $(TARGET)
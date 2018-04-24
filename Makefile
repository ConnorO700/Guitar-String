all: GuitarHeroLite.o RingBuffer.o GuitarString.o
	g++ GuitarHeroLite.o RingBuffer.o GuitarString.o -o GuitarHero -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

test: test.o RingBuffer.o GuitarString.o
	g++ test.o RingBuffer.o GuitarString.o -o GuitarHero -lboost_unit_test_framework -lsfml-window -lsfml-graphics -lsfml-system

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	g++ -c RingBuffer.cpp -Wall -Werror -ansi -pedantic

GuitarString.o: GuitarString.cpp GuitarString.hpp
	g++ -c GuitarString.cpp -Wall -Werror -ansi -pedantic

GuitarHeroLite.o: GuitarHeroLite.cpp
	g++ -c GuitarHeroLite.cpp -Wall -Werror -ansi -pedantic


test.o: test.cpp
	g++ -c test.cpp -Wall -Werror -ansi -pedantic 

clean: 
	rm *.o GuitarHero


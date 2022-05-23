CXXFLAGS=-g -Iinc -Wall -pedantic #-std=c++0x

__start__: projekt_2
	./projekt_2

# WAŻNE! 
# > W górnej linijce poniższego wywołania kompilacji całego programu
#	dodajemy wszystkie pliki .o, które wcześniej skompilowaliśmy
#
# > W dolnej linijce NIE DODAJEMY plików .o których pliki .cpp nie
#	zawierały żadnego kopu poza #include "plik.hh", bo inaczej
# 	kompilacja się wysypie.
projekt_2: main.o testy.o filtracja.o algorytmy.o film.o
	g++ -Wall -pedantic main.o testy.o filtracja.o algorytmy.o film.o -o projekt_2

main.o: main.cpp
	g++ -c ${CXXFLAGS} main.cpp

testy.o: testy.cpp
	g++ -c ${CXXFLAGS} testy.cpp

filtracja.o: filtracja.cpp
	g++ -c ${CXXFLAGS} filtracja.cpp

algorytmy.o: algorytmy.cpp
	g++ -c ${CXXFLAGS} algorytmy.cpp

film.o: film.cpp
	g++ -c ${CXXFLAGS} film.cpp

clean:
	rm *.o projekt_2.exe
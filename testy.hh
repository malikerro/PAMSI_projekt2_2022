#ifndef TESTY_HH
#define TESTY_HH

#include <ctime>
#include <chrono>
#include <conio.h>
#include <algorithm>
#include "filtracja.hh"

#define R10k 10000
#define R100k 100000
#define R500k 500000
#define R1M 1000000


// funkcja obliczająca średnią danych w wektorze
float oblicz_srednia(const vector<Film>& wektor_filmow);

// funkcja obliczająca medianę danych w uporządkowanym wektorze
float oblicz_mediane(const vector<Film>& wektor_filmow);

// funkcja przygotowująca wektor do przeprowadzenia testów o zadanym 
// rozmiarze, będący częścią wektora ze wszystkimi danymi
bool przygotuj_wektor(vector<Film> &wektor_wzor, vector<Film> &wektor_wynik, int rozmiar);

// funkcja sprawdzająca poprawność posortowania zbioru
bool sprawdz_posortowaie(vector<Film>& wektor_filmow);

// funkcja do wyświetlania wyników sprawdzenia (żeby mniej miejsca zajmowało w main)
void wyswietl_sprawdzenie(vector<Film>& wektor_filmow, ofstream &wyniki);


#endif
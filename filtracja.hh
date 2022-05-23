#ifndef FILTRCJA_HH
#define FILTRCJA_HH

#include <fstream>
#include "algorytmy.hh"

using namespace std;

/**********************************************************************
 *   Funkcja przetwarzająca plik z danymi
 *   Rozpoznaje i wczytuje parametry filmów do struktury a następnie 
 *   tworzy wektor struktur Film, który zwraca na wyjściu, Zapisuje
 *   również przefiltrowane informacje do pliku
 **********************************************************************/
vector<Film> odczyt_i_filtracja(string &plik_wej, string &plik_wyj);

#endif
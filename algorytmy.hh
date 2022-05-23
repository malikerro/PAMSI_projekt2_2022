#ifndef ALGORYTMY_HH
#define ALGORYTMY_HH

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "film.hh"

using namespace std;

/***************************************************************
*   klasa zawierająca algorytmy sortowania i wymaganą 
*   dynamicznego zaalokowania (ze względu na duży rozmiar)
*   strukturę pomocniczą, wykorzystywaną w algorytmie merge sort
****************************************************************/
class Algorytm
{

    vector<Film> Pomocnicza; // struktura pomocnicza dla algorytmu merge sort
    int Rozmiar_tab;         // ilość elementów sortowanej struktury

    public:

    // konstruktor klasy Algorytm alokujący pamięć na strukturę
    // Pomocnicza
    Algorytm(int rozmiar){
        for (int i = 0; i < rozmiar; i++)
        {
            Pomocnicza.push_back({"", 0});
        }
        
        Rozmiar_tab = rozmiar;
    }

    // destruktor klasy algorytm kasujący strukturę Pomocnicza
    ~Algorytm(){
        Pomocnicza.clear();
    }

    //------------------------------------------------------------/
    // funkcje używane w algorytmie merge sort:
    //------------------------------------------------------------/

    // funkcja "merge" scalająca posortowane podtablice
    void merge (vector<Film> &Tab_wej, int LewyInd, int SrodInd, int PrawyInd);    

    // funkcja dokonująca podziału tablicy na podtablice
    // i właściwego sortowania przez scalanie
    // wywoływana rekurencyjnie
    void m_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd);

    // ostateczna funkcja wywołująca i ustalająca parametry
    // funkcji m_sort, tak żeby można ją było łatwo wywołać w mainie
    void merge_sort (vector<Film> &Tab_wej);

    //------------------------------------------------------------/


    //------------------------------------------------------------/
    // funkcje używane w algorytmie quick sort:
    //------------------------------------------------------------/

    // właściwa funkcja sortująca q_sort wywoływana rekurencyjnie
    int q_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd);

    // wywoływana rekurencyjnie funkcja dzieląca strukturę oraz 
    // kontrolująca głębokość wywołań
    void podzial (vector<Film> &Tab_wej, int LewyInd, int PrawyInd, int Glebokosc);

    // ostateczna funkcja wywołująca i ustalająca parametry
    // funkcji q_sort, tak żeby można ją było łatwo wywołać w mainie
    void quick_sort (vector<Film> &Tab_wej);

    //------------------------------------------------------------/


    //------------------------------------------------------------/
    // funkcje używane w algorytmie intro sort:
    //------------------------------------------------------------/

    // sortowanie przez wstawianie wykorzystywane w głównym algorytmie
    // sortowania introspektywnego
    void insert_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd);

    // podfunkcja sortowania przez kopcowanie porządkująca kopiec w taki sposób,
    // aby był kopcem maksymalnym
    void KopiecMax (vector<Film> &Tab_wej, int Rozmiar, int RodzicInd);

    // sortowanie przez kopcowanie wykorzystywane w głównym algorytmie
    // sortowania introspektywnego 
    void heap_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd);

    // przekształcone sortowanie szybkie z wyeliminowanym wywoływaniem rekurencyjnym
    // zwracające indeks pivota 
    int q_sort_dla_i_sorta (vector<Film> &Tab_wej, int LewyInd, int PrawyInd);

    // trzon algorytmu sortowania introspektywnego
    void i_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd, int Glebokosc);

    // główna funkcja organizująca dla sortowania introspektywnego
    void intro_sort (vector<Film> &Tab_wej);
    //------------------------------------------------------------/
};

#endif
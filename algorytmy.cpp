#include "algorytmy.hh"


void Algorytm::merge (vector<Film> &Tab_wej, int LewyInd, int SrodInd, int PrawyInd)
{
    // przypisanie wartości tablicy wejściowej do tablicy pomocniczej
    for (int i = LewyInd; i <= PrawyInd; i++) {
        Pomocnicza[i] = Tab_wej[i];
    }

     // LewyElem i PrawyElem - indeksy porównywanych wyrazów
    int LewyElem = LewyInd, PrawyElem = SrodInd + 1;

    for (int biezacy = LewyInd; biezacy <= PrawyInd; biezacy++)
    {
        if(LewyElem <= SrodInd) // i = LewyElem, j = PrawyElem, k = biezacy
        {
            if(PrawyElem <= PrawyInd)
            {
                if(Pomocnicza[PrawyElem] < Pomocnicza[LewyElem])
                {
                    Tab_wej[biezacy] = Pomocnicza[PrawyElem++];
                } else {
                    Tab_wej[biezacy] = Pomocnicza[LewyElem++];
                }
            } else {
                Tab_wej[biezacy] = Pomocnicza[LewyElem++];
            }
        } else {
            Tab_wej[biezacy] = Pomocnicza[PrawyElem++];
        }
    }
}

void Algorytm::m_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd)
{    
    if(PrawyInd <= LewyInd) return; // sytuacja gdy został już tylko jeden element 
    int SrodInd = (PrawyInd + LewyInd)/2;  // indeks elementu środkowego, zostanie zaokrąglony w dół
    //  podział tablicy na dwie części
    m_sort(Tab_wej, LewyInd, SrodInd); 
    m_sort(Tab_wej, SrodInd + 1, PrawyInd);
    //  scalanie posortowanych tablic
    merge(Tab_wej, LewyInd, SrodInd, PrawyInd);
}

void Algorytm::merge_sort (vector<Film> &Tab_wej) {
    // wywołanie funkcji m_sort przy użyciu parametrów podanych funkcji merge_sort
    // potrzebne do wyznaczenia parametrów: "LewyInd" i "PrawyInd" w pierwszym
    // wywołaniu funkcji
    m_sort(Tab_wej, 0, Rozmiar_tab - 1);
}
//------------------------------------------------------------/


//------------------------------------------------------------/
// funkcje używane w algorytmie quick sort:
//------------------------------------------------------------/

int Algorytm::q_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd)
{
    int lewy, prawy, PivotInd;
    Film pivot;
    int n = PrawyInd - LewyInd + 1;
    if(LewyInd < PrawyInd)
    {
            // indeks pivota jest losowany z zakresu od LewyInd do n + LewyInd,
            // czyli od pierwszego, do ostatniego indeksu sortowanej tablicy
            PivotInd = rand() % n + LewyInd;
            pivot = Tab_wej[PivotInd];
            // zamieniamy pivot z pierwszym elementem
            Tab_wej[PivotInd] = Tab_wej[LewyInd];
            Tab_wej[LewyInd] = pivot;
            lewy = LewyInd;
            prawy = PrawyInd;
            while(lewy < prawy) {
                while(Tab_wej[lewy] <= pivot && lewy < PrawyInd) {
                    lewy++;
                }
                while(Tab_wej[prawy] > pivot && prawy > LewyInd) {
                    prawy--;
                }
                if(lewy < prawy) {
                    // ustawiamy wszystkie elementy mniejsze i większe od pivota
                    // po dwóch stronach - zamieniamy jeśli są po złej stronie
                    fswap(Tab_wej[lewy], Tab_wej[prawy]);
                }
            }
    
            // ustawienie pivota na prawidłowej pozycji
            fswap(Tab_wej[LewyInd], Tab_wej[prawy]);
            // zwracamy indeks pivota
            return prawy;     
    } else {   
        // zwracamy indeks pojedynczego elementu, bo nie dokonane zostały
        // żadne podziały i nie został wylosowany pivot
        return LewyInd;
    }
}

void Algorytm::podzial (vector<Film> &Tab_wej, int LewyInd, int PrawyInd, int Glebokosc)
{
    int PivotInd;
    if (Glebokosc <= 0)
    {
        q_sort(Tab_wej, LewyInd, PrawyInd);
        return;
    }
    PivotInd = q_sort(Tab_wej, LewyInd, PrawyInd);
    if (PivotInd > LewyInd) {
        podzial(Tab_wej, LewyInd, PivotInd - 1, Glebokosc - 1);
    }
    if (PrawyInd > PivotInd) {
        podzial(Tab_wej, PivotInd + 1, PrawyInd, Glebokosc - 1);
    }
}

void Algorytm::quick_sort (vector<Film> &Tab_wej)
{
    //  wywołanie funkcji q_sort przy użyciu parametrów podanych funkcji quick_sort,
    //  dla ułatwienia rekurencyjności, analogicznie jak w merge_sort
    int Glebokosc = (2*log(Rozmiar_tab))/(log(2));
    podzial(Tab_wej, 0, Rozmiar_tab - 1, Glebokosc);
}
//------------------------------------------------------------/


//------------------------------------------------------------/
// funkcje używane w algorytmie intro sort:
//------------------------------------------------------------/

void Algorytm::insert_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd)
{
    int j;
    Film pomocnicza;
    int n = PrawyInd - LewyInd + 1;
    for (int i = LewyInd + 1; i < LewyInd + n; ++i)
    {    
        if (Tab_wej[i] < Tab_wej[i - 1])
        {
            j = i;
            pomocnicza = Tab_wej[i];
            while (pomocnicza < Tab_wej[j - 1] && j > LewyInd)
            {
                Tab_wej[j] = Tab_wej[j - 1];
                --j;
            }
            Tab_wej[j] = pomocnicza;
        }
    }
}

void Algorytm::KopiecMax (vector<Film> &Tab_wej, int Rozmiar, int RodzicInd)
{
    int maxInd = RodzicInd;
    int leweDzieckoInd = RodzicInd*2 + 1;
    int praweDzieckoInd = RodzicInd*2 + 2;

    if(leweDzieckoInd < Rozmiar && Tab_wej[leweDzieckoInd] > Tab_wej[maxInd]){
        maxInd = leweDzieckoInd;
    }
     if(praweDzieckoInd < Rozmiar && Tab_wej[praweDzieckoInd] > Tab_wej[maxInd]) {
        maxInd = praweDzieckoInd;
    }
     if(maxInd != RodzicInd)
    {
        fswap(Tab_wej[maxInd], Tab_wej[RodzicInd]);
        KopiecMax(Tab_wej, Rozmiar, maxInd);
    }
}


void Algorytm::heap_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd)
{
    int n = PrawyInd - LewyInd + 1;
    for (int i = LewyInd + (n/2) - 1; i >= LewyInd; i--) {
        KopiecMax(Tab_wej, n, i);
    }
    
    for (int i = LewyInd + n - 1; i > LewyInd; i--)
    {
        fswap(Tab_wej[LewyInd], Tab_wej[i]);
        --n;
        KopiecMax(Tab_wej, n, LewyInd);
    }
}

int Algorytm::q_sort_dla_i_sorta (vector<Film> &Tab_wej, int LewyInd, int PrawyInd)
{
    int lewy, prawy, PivotInd;
    Film pivot;
    int n = PrawyInd - LewyInd + 1;
    if(LewyInd < PrawyInd)
    {
            // indeks pivota jest losowany z zakresu od LewyInd do n + LewyInd,
            // czyli od pierwszego, do ostatniego indeksu sortowanej tablicy
            PivotInd = rand() % n + LewyInd;
            pivot = Tab_wej[PivotInd];
            // zamieniamy pivot z pierwszym elementem
            Tab_wej[PivotInd] = Tab_wej[LewyInd];
            Tab_wej[LewyInd] = pivot;
            lewy = LewyInd;
            prawy = PrawyInd;
            while(lewy < prawy) {
                while(Tab_wej[lewy] <= pivot && lewy < PrawyInd) {
                    lewy++;
                }
                while(Tab_wej[prawy] > pivot && prawy > LewyInd) {
                    prawy--;
                }
                if(lewy < prawy) {
                    // ustawiamy wszystkie elementy mniejsze i większe od pivota
                    // po dwóch stronach - zamieniamy jeśli są po złej stronie
                    fswap(Tab_wej[lewy], Tab_wej[prawy]);
                }
            }
    
            // ustawienie pivota na prawidłowej pozycji
            fswap(Tab_wej[LewyInd], Tab_wej[prawy]);
            // zwracamy indeks pivota
            return prawy;     
    } else {   
        // zwracamy indeks pojedynczego elementu, bo nie dokonane zostały
        // żadne podziały i nie został wylosowany pivot
        return LewyInd;
    } 
}

void Algorytm::i_sort (vector<Film> &Tab_wej, int LewyInd, int PrawyInd, int Glebokosc)
{
    int PivotInd;
    // poniżej wcześniej obliczonej głębokości rekurencji wykonywane jest sortowanie
    // przez kopcowanie - optymalne dla małych rozmiarów tablic
    if (Glebokosc <= 0)
    {
        heap_sort(Tab_wej, LewyInd, PrawyInd);
        return;
    }
    PivotInd = q_sort_dla_i_sorta(Tab_wej, LewyInd, PrawyInd);

    // tablica jest sortowana tylko wstępnie, aby sortowanie końcowe mogło zostać
    // wykonane przez algorytm insert sort
    if (PivotInd > (LewyInd + 9)) {
        i_sort(Tab_wej, LewyInd, PivotInd - 1, Glebokosc - 1);
    }
    if ((PrawyInd - PivotInd) > 9) {
        i_sort(Tab_wej, PivotInd + 1, PrawyInd, Glebokosc - 1);
    }
}

void Algorytm::intro_sort (vector<Film> &Tab_wej)
{
    // obliczenie głębokości na podstawie wzoru z wikipedii
    int Glebokosc = (2*log(Rozmiar_tab))/(log(2));
    i_sort(Tab_wej, 0, Rozmiar_tab - 1, Glebokosc);
    insert_sort(Tab_wej, 0, Rozmiar_tab - 1);
}

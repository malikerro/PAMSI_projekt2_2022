#include "testy.hh"


float oblicz_srednia(const vector<Film>& wektor_filmow)
{
    int rozmiar = wektor_filmow.size();
    float srednia = 0.0f;
    for (int i = 0; i < rozmiar; i++)
    {
        srednia += wektor_filmow[i].ranking;
    }
    return srednia/(float)(rozmiar);
}

float oblicz_mediane(const vector<Film>& wektor_filmow)
{
    int rozmiar = wektor_filmow.size();
    if (rozmiar%2 == 0)
    {
        float mediana = (wektor_filmow[rozmiar/2].ranking + wektor_filmow[rozmiar/2 - 1].ranking)/2;
        return (mediana); 
    }
    else return (wektor_filmow[rozmiar/2].ranking);
}

bool przygotuj_wektor(vector<Film> &wektor_wzor, vector<Film> &wektor_wynik, int rozmiar)
{
    wektor_wynik.clear();
    for (int i = 0; i < rozmiar; i++)
    {
        wektor_wynik.push_back(wektor_wzor[i]);
    }
    return true;
}

bool sprawdz_posortowaie(vector<Film>& wektor_filmow)
{
    int rozmiar = wektor_filmow.size();
    for (int i = 0; i < (rozmiar - 1); i++)
    {
        if (wektor_filmow[i] > wektor_filmow[i + 1]) return false;
    }
    return true;
}

void wyswietl_sprawdzenie(vector<Film>& wektor_filmow, ofstream &wyniki)
{
    if (sprawdz_posortowaie(wektor_filmow))
    {
        cout << "\nPosortowano pomyslnie";
        wyniki << "\nPosortowano pomyslnie";
    }
    else
    {
        cout << "\nSortowanie niepoprawne";
        wyniki << "\nSortowanie niepoprawne";
    }
}

#include "filtracja.hh"


vector<Film> odczyt_i_filtracja(string &plik_wej, string &plik_wyj)
{    
    vector<Film> baza_filmow;
    string tytul_tmp;
    string ranking_str;
    string tekst;
    float ranking_tmp;
    unsigned int i;
    ifstream dane(plik_wej);   // strumień pliku wejściowego
    ofstream zapis(plik_wyj);  // strumień pliku wyjściowego
    
    if (!dane.good())
    {
        cout << "Niepoprawny plik wejsciowy. Podaj poprawna nazwe, lub N aby wyjsc: ";
        plik_wej.clear();
        cin >> plik_wej;
        if (plik_wej == "N") exit(1);
        baza_filmow = odczyt_i_filtracja(plik_wej, plik_wyj);
        return baza_filmow;
    }

    if (!zapis.good())
    {
        cout << "Niepoprawny plik wyjsciowy. Podaj poprawna nazwe, lub N aby wyjsc: ";
        plik_wyj.clear();
        cin >> plik_wyj;
        if (plik_wyj == "N") exit(1);
        baza_filmow = odczyt_i_filtracja(plik_wej, plik_wyj);
        return baza_filmow;
    }

    // wczytywanie tekstu poprzedzającego dane
    getline(dane, tekst);

    while (!dane.eof())
    {
        getline(dane, tekst);
        if(tekst.size() < 1) continue; // inaczej program się wysypie na pustej linijce

        i = 0;
        while (tekst[i] != ',') i++; // wczytanie znaków przed tytułem
        
        // wczytanie tytułu
        i++; // pominięcie przecinka
        if (tekst[i] == '\"')
        {
            i++;
            while (tekst[i] != '\"')
            {
                tytul_tmp.push_back(tekst[i]);
                i++;
            }
            i++;
        }
        else
        {
            while (tekst[i] != ',')
            {
                tytul_tmp.push_back(tekst[i]);
                i++;
            }
        }
        // wczytanie rankingu
        if (i == (tekst.size() - 1))
        {
            tytul_tmp.clear();
        }
        else
        {
            i++; // pominięcie przecinka
            ranking_str = tekst.string::substr(i, tekst.size() - 1);

            if (isdigit(ranking_str[0]))
            {
                ranking_tmp = (float) atof(ranking_str.c_str());
                baza_filmow.push_back({tytul_tmp, ranking_tmp});
                tytul_tmp.clear();
            }
            else tytul_tmp.clear();
        }
    }

    for (unsigned int i = 0; i < baza_filmow.size(); i++)
    {
        zapis << baza_filmow[i].tytul << " " << to_string(baza_filmow[i].ranking) << endl;
    }

    dane.close();
    zapis.close();

    return baza_filmow;
}
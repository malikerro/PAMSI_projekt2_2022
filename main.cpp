#include "testy.hh"


using namespace std;


int main ()
{

/*****************************************************************
*   Funkcja główna obsługuje pełną procedurę testów algorytmów 
*   sortowania, przygotowuje odpowiednie struktury danych,  
*   przeprowadza filtrację oraz testy mierząc czas wykonywanych 
*   zadań, a wyniki wyświetla na bierząco oraz zapisuje do pliku
*   out_wyniki.txt
******************************************************************/

    float srednia = 0;
    float mediana = 0;
    string plik_in = "projekt2_dane.csv";
    string plik_out = "out_dane.csv";
    string plik_wyniki = "out_wyniki.txt";
    vector<Film> wektor_filmow_10k;
    vector<Film> wektor_filmow_100k;
    vector<Film> wektor_filmow_500k;
    vector<Film> wektor_filmow_1M;
    vector<Film> wektor_filmow_max;
    ofstream wyniki;    // strumień pliku wejściowego

    wyniki.open(plik_wyniki);
    while (!wyniki.good())
    {
        cout << "Niepoprawny plik wynikowy. Podaj poprawna nazwe, lub N aby wyjsc: ";
        plik_wyniki.clear();
        cin >> plik_wyniki;
        if (plik_wyniki == "N") exit(1);
        wyniki.open(plik_wyniki);
    }

    //====================================================================
    //--------------------   FILTRACJA BAZY FILMÓW   -------------------//
    //====================================================================
    auto start = chrono::system_clock::now(); // czas rozpoczęcia filtracji
    wektor_filmow_max = odczyt_i_filtracja(plik_in, plik_out);
    auto end = std::chrono::system_clock::now(); // koniec czasu filtracji
    chrono::duration<double> duration = end - start;

    cout << "\nCzas trwania filtracji: " << to_string(duration.count()) << " s\n";
    wyniki << "\nCzas trwania filtracji: " << to_string(duration.count()) << " s\n";

    const int Rozmiar_max = wektor_filmow_max.size();



    //====================================================================
    //-------------------   TESTY DLA ROZMIARU 10k   -------------------//
    //====================================================================
    int Aktualny_rozm = R10k;
    Algorytm algorytm_10k(Aktualny_rozm);
    przygotuj_wektor(wektor_filmow_max, wektor_filmow_10k, Aktualny_rozm);
    cout << "\n__________________________________________________________________TESTY 10k";
    wyniki << "\n__________________________________________________________________TESTY 10k";

    //____________________________________________________________________
    //____________________   testy merge sort 10k   ____________________//
    vector<Film> kopia_10k = wektor_filmow_10k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_10k.merge_sort(kopia_10k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_10k, wyniki);

    cout << "\nCzas sortowania merge sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania merge sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy quick sort 10k   ____________________//
    kopia_10k = wektor_filmow_10k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_10k.quick_sort(kopia_10k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_10k, wyniki);

    cout << "\nCzas sortowania quick sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania quick sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy intro sort 10k   ____________________//
    kopia_10k = wektor_filmow_10k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_10k.intro_sort(kopia_10k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_10k, wyniki);

    cout << "\nCzas sortowania intro sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania intro sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //________________   obliczenie średniej i mediany   ________________//
    srednia = oblicz_srednia(kopia_10k);
    mediana = oblicz_mediane(kopia_10k);

    cout << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    cout << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    wyniki << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    wyniki << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    
    wektor_filmow_10k.clear();
    kopia_10k.clear();
    


    //====================================================================
    //-------------------   TESTY DLA ROZMIARU 100k   ------------------//
    //====================================================================
    Aktualny_rozm = R100k;
    Algorytm algorytm_100k(Aktualny_rozm);
    przygotuj_wektor(wektor_filmow_max, wektor_filmow_100k, Aktualny_rozm);
    cout << "\n\n__________________________________________________________________TESTY 100k";
    wyniki << "\n\n__________________________________________________________________TESTY 100k";

    //____________________________________________________________________
    //____________________   testy merge sort 100k   ___________________//
    vector<Film> kopia_100k = wektor_filmow_100k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_100k.merge_sort(kopia_100k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_100k, wyniki);

    cout << "\nCzas sortowania merge sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania merge sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy quick sort 100k   ___________________//
    kopia_100k = wektor_filmow_100k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_100k.quick_sort(kopia_100k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_100k, wyniki);

    cout << "\nCzas sortowania quick sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania quick sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy intro sort 100k   ___________________//
    kopia_100k = wektor_filmow_100k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_100k.intro_sort(kopia_100k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_100k, wyniki);

    cout << "\nCzas sortowania intro sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania intro sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //________________   obliczenie średniej i mediany   ________________//
    srednia = oblicz_srednia(kopia_100k);
    mediana = oblicz_mediane(kopia_100k);
    
    cout << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    cout << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    wyniki << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    wyniki << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    
    wektor_filmow_100k.clear();
    kopia_100k.clear();



    //====================================================================
    //-------------------   TESTY DLA ROZMIARU 500k   ------------------//
    //====================================================================
    Aktualny_rozm = R500k;
    Algorytm algorytm_500k(Aktualny_rozm);
    przygotuj_wektor(wektor_filmow_max, wektor_filmow_500k, Aktualny_rozm);
    cout << "\n\n__________________________________________________________________TESTY 500k";
    wyniki << "\n\n__________________________________________________________________TESTY 500k";

    //____________________________________________________________________
    //____________________   testy merge sort 500k   ___________________//
    vector<Film> kopia_500k = wektor_filmow_500k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_500k.merge_sort(kopia_500k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_500k, wyniki);

    cout << "\nCzas sortowania merge sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania merge sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy quick sort 500k   ___________________//
    kopia_500k = wektor_filmow_500k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_500k.quick_sort(kopia_500k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_500k, wyniki);

    cout << "\nCzas sortowania quick sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania quick sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy intro sort 500k   ___________________//
    kopia_500k = wektor_filmow_500k;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_500k.intro_sort(kopia_500k);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_500k, wyniki);

    cout << "\nCzas sortowania intro sort dla rozmiaru ";
    cout << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania intro sort dla rozmiaru ";
    wyniki << to_string(Aktualny_rozm) << " elem.: " << to_string(duration.count()) << " s";

    //________________   obliczenie średniej i mediany   ________________//
    srednia = oblicz_srednia(kopia_500k);
    mediana = oblicz_mediane(kopia_500k);
    
    cout << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    cout << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    wyniki << "\n\nSrednia wartosc rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(srednia);
    wyniki << "\nMediana rankingu dla rozmiaru " << to_string(Aktualny_rozm) << " elem. wyniosla: " << to_string(mediana);
    
    wektor_filmow_500k.clear();
    kopia_500k.clear();



    //====================================================================
    //-------------------   TESTY DLA ROZMIARU MAX   -------------------//
    //====================================================================
    Algorytm algorytm_max(Rozmiar_max);
    vector<Film> kopia_max = wektor_filmow_max;
    cout << "\n\n__________________________________________________________________TESTY max";
    wyniki << "\n\n__________________________________________________________________TESTY max";

    //____________________________________________________________________
    //____________________   testy merge sort MAX   ____________________//
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_max.merge_sort(kopia_max);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_max, wyniki);

    cout << "\nCzas sortowania merge sort dla pelnego rozmiaru bazy filmow (";
    cout << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania merge sort dla pelnego rozmiaru bazy filmow (";
    wyniki << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy quick sort MAX   ____________________//
    kopia_max = wektor_filmow_max;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_max.quick_sort(kopia_max);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_max, wyniki);

    cout << "\nCzas sortowania quick sort dla pelnego rozmiaru bazy filmow (";
    cout << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania quick sort dla pelnego rozmiaru bazy filmow (";
    wyniki << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";

    //____________________________________________________________________
    //____________________   testy intro sort MAX   ____________________//
    kopia_max = wektor_filmow_max;
    start = chrono::system_clock::now(); // czas rozpoczęcia sortowania
    algorytm_max.intro_sort(kopia_max);
    end = std::chrono::system_clock::now(); // koniec czasu sortowania
    duration = end - start;

    wyswietl_sprawdzenie(kopia_max, wyniki);

    cout << "\nCzas sortowania intro sort dla pelnego rozmiaru bazy filmow (";
    cout << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";
    wyniki << "\nCzas sortowania intro sort dla pelnego rozmiaru bazy filmow (";
    wyniki << to_string(Rozmiar_max) << " elem.): " << to_string(duration.count()) << " s";

    //________________   obliczenie średniej i mediany   ________________//
    srednia = oblicz_srednia(kopia_max);
    mediana = oblicz_mediane(kopia_max);

    cout << "\n\nSrednia wartosc pelnego rankingu wyniosla: " << to_string(srednia);
    cout << "\nMediana pelnego rankingu wyniosla: " << to_string(mediana);
    wyniki << "\n\nSrednia wartosc pelnego rankingu: " << to_string(srednia);
    wyniki << "\nMediana pelnego rankingu: " << to_string(mediana);





    kopia_max.clear();



    wektor_filmow_max.clear();

    wyniki.close();

    return 0;
}


// przykład wywołania sortowania z STL (w razie potrzeby porównania):
// sort(kopia_max.begin(), kopia_max.end());

// ODCZYT DANYCH do debugu
//for (int i = 0; i < Rozmiar_max; i++) cout << endl << kopia_max[i].ranking << " " << kopia_max[i].tytul;

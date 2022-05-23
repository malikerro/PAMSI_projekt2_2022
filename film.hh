#ifndef FILM_HH
#define FILM_HH

#include <string>

/***************************************************************
*   klasa przechowująca informacje dot. jednego filmu: 
*   tytuł i ranking
****************************************************************/
class Film
{
public:
  std::string tytul;
  float ranking;

  // przeciążenie operatora = kopiujące oba pola 1. obiektu do 2.
  const Film &operator=(const Film &film_kopiowany)
  {
    this->tytul = film_kopiowany.tytul;
    this->ranking = film_kopiowany.ranking;
    return *this;
  }

  // Przeciążenie operatora == dzięki któremu przy porównaniu
  // obiektów porównywane są tylko pola ranking
  bool operator ==( const Film & film_porownywany )
  {
    if(this->ranking == film_porownywany.ranking) return true;
    else return false;
  }

  // analogicznie jak dla przeciązenia ==
  bool operator >=( const Film & film_porownywany )
  {
    if(this->ranking >= film_porownywany.ranking) return true;
    else return false;
  }

  // analogicznie jak dla przeciązenia ==
  bool operator <=( const Film & film_porownywany )
  {
    if(this->ranking <= film_porownywany.ranking) return true;
    else return false;
  }

  // analogicznie jak dla przeciązenia ==
  bool operator >( const Film & film_porownywany )
  {
    if(this->ranking > film_porownywany.ranking) return true;
    else return false;
    //return (this->ranking > film_porownywany.ranking);
  }

  // analogicznie jak dla przeciązenia ==
  bool operator <( const Film & film_porownywany )
  {
    if(this->ranking < film_porownywany.ranking) return true;
    else return false;
  }
};

// funkcja zamieniająca dane w 1. obiekcie na dane z 2. obiektu
// i na odwrót
void fswap(Film &film_1, Film &film_2);

#endif
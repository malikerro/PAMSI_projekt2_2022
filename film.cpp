#include "film.hh"

void fswap(Film &film_1, Film &film_2)
{
    Film tmp;
    tmp = film_1;
    film_1 = film_2;
    film_2 = tmp;
}
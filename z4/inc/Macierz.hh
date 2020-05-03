#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

template<typename Typ, int Rozmiar>
class Macierz {
   Wektor<Typ, Rozmiar> tab[ROZMIAR];
  public:  
  Macierz<Typ, Rozmiar>();
  Macierz<Typ, Rozmiar>(const Wektor<Typ, Rozmiar> tab[]);

  Typ wyznacznik() const;
  Macierz<Typ, Rozmiar> zmien_kolumne(int kolum, Wektor<Typ, Rozmiar> wek);
  Macierz<Typ, Rozmiar> transponuj() const;

  Macierz<Typ, Rozmiar> operator + (const Macierz<Typ, Rozmiar> & M) const;
  Macierz<Typ, Rozmiar> operator - (const Macierz<Typ, Rozmiar> & M) const;
  Macierz<Typ, Rozmiar> operator * (const Macierz<Typ, Rozmiar> & M) const;
  Wektor<Typ, Rozmiar> operator * (const Wektor<Typ, Rozmiar> & W) const;
  Macierz<Typ, Rozmiar> operator * (const double l) const;

  bool operator == (const Macierz & M) const;
  bool operator != (const Macierz & M) const;

  const Wektor<Typ, Rozmiar> & operator[] (int index) const;
  Wektor<Typ, Rozmiar> & operator[] (int index);
  
};

template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &strm, Macierz<Typ, Rozmiar> &M);
template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &strm, const Macierz<Typ, Rozmiar> &M);


#endif

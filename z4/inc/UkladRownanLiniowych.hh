#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

template<typename Typ, int Rozmiar>
class UkladRownanLiniowych {
  Macierz<Typ, Rozmiar> A;
  Wektor<Typ, Rozmiar> b;

public:
  UkladRownanLiniowych<Typ, Rozmiar>(): A(), b() {};
  UkladRownanLiniowych<Typ, Rozmiar>(Macierz<Typ, Rozmiar> AA, Wektor<Typ, Rozmiar> bb) : A(AA), b(bb) {} ;   

  const Macierz<Typ, Rozmiar> & get_A() const {return A;};
  const Wektor<Typ, Rozmiar> & get_b() const {return b;};
  
  Wektor<Typ, Rozmiar> Oblicz() const;
  Wektor<Typ, Rozmiar> w_bledu() const;
};

template<typename Typ, int Rozmiar>
istream& operator >> (istream &strm, UkladRownanLiniowych<Typ, Rozmiar> &UklRown);
template<typename Typ, int Rozmiar>
ostream& operator << (ostream &strm,const UkladRownanLiniowych<Typ, Rozmiar> &UklRown);


#endif

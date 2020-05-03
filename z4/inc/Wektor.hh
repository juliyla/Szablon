#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

using namespace std;

template<typename Typ, int Rozmiar>
class Wektor {
  Typ tab[Rozmiar];
public:
  Wektor<Typ, Rozmiar>();
  Wektor<Typ, Rozmiar>(Typ tab[]);
 
  Wektor<Typ, Rozmiar> operator + (const Wektor<Typ, Rozmiar> &W2) const;
  Wektor<Typ, Rozmiar> operator - (const Wektor<Typ, Rozmiar> &W2) const;
  Typ operator * (const Wektor<Typ, Rozmiar> &W2) const;
  Wektor<Typ, Rozmiar> operator * (double l) const;
  Wektor<Typ, Rozmiar> operator / (double l) const;

  /*double dlugosc() const; */

  bool operator == (const Wektor<Typ, Rozmiar> &W2) const;
  bool operator != (const Wektor<Typ, Rozmiar> &W2) const;
  
  const Typ & operator [] (int index) const;
  Typ & operator [] (int index);
    
};

template<typename Typ, int Rozmiar>
istream & operator >> (istream &strm, Wektor<Typ, Rozmiar> &W);
template<typename Typ, int Rozmiar>
ostream & operator << (ostream &strm, const Wektor<Typ, Rozmiar> &W);

#endif

#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

using namespace std;

class UkladRownanLiniowych {
  Macierz A;
  Wektor b;

public:
  UkladRownanLiniowych(): A(), b() {};
  UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), b(bb) {} ;   

  const Macierz & get_A() const {return A;};
  const Wektor & get_b() const {return b;};
  
  Wektor Oblicz() const;
  Wektor w_bledu() const;
  double dl_bledu() const;
};


std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << (std::ostream &strm,const UkladRownanLiniowych &UklRown);


#endif

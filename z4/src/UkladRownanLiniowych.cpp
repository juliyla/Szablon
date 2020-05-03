#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "LZespolona.hh"
#include "rozmiar.h"
#include <math.h>
#include <algorithm>

using namespace std;

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> UkladRownanLiniowych<Typ, Rozmiar>::w_bledu() const {
  Wektor<Typ, Rozmiar> wynik,wpom;
  Macierz<Typ, Rozmiar> mpom;
  wpom=b;
  mpom=A;
  mpom.transponuj();
  wynik = mpom*Oblicz()-wpom;cd ..

  return wynik;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> UkladRownanLiniowych<Typ, Rozmiar>::Oblicz() const {
  Wektor<Typ, Rozmiar> wynik;
  Macierz<Typ, Rozmiar> mpom = get_A(); 
  Typ wyznaczniki[ROZMIAR]; 
  Typ gl_wyznacznik = get_A().wyznacznik();
  Wektor<Typ, Rozmiar> wolne = get_b(); 
  for(int i = 0; i < ROZMIAR; i++) {
    mpom = mpom.zmien_kolumne(i, wolne);
    wyznaczniki[i] = mpom.wyznacznik();
    wyznaczniki[i] = wyznaczniki[i] / gl_wyznacznik; 
    mpom = get_A();
    }
  return Wektor<Typ, Rozmiar>(wyznaczniki);
}

template<typename Typ, int Rozmiar>
istream & operator >> (istream &strm, UkladRownanLiniowych<Typ, Rozmiar> & UklRown) {
  
  Macierz<Typ, Rozmiar> mpom;
  Wektor<Typ, Rozmiar> wpom;

  strm>> mpom;
  strm>> wpom;
  

  UklRown = UkladRownanLiniowych<Typ, Rozmiar>(mpom,wpom);
  return strm;
}

template<typename Typ, int Rozmiar>
ostream & operator << (ostream &strm, const UkladRownanLiniowych<Typ, Rozmiar> & UklRown) {
  cout << "Macierz: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazow wolnych b: " << endl << UklRown.get_b() << endl;
  return strm;
}

template class UkladRownanLiniowych<double, 5>;
template istream& operator >> (istream &strm, UkladRownanLiniowych<double, 5> &UklRown);
template ostream& operator << (ostream &strm, const UkladRownanLiniowych<double, 5> &UklRown);

template class UkladRownanLiniowych<LZespolona, 5>;
template istream& operator >> (istream &strm, UkladRownanLiniowych<LZespolona, 5> &UklRown);
template ostream& operator << (ostream &strm, const UkladRownanLiniowych<LZespolona, 5> &UklRown);
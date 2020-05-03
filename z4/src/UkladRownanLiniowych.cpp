#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <math.h>
#include <algorithm>

using namespace std;

template<typename Typ, int Rozmiar>
Wektor UkladRownanLiniowych<Typ, Rozmiar>::w_bledu() const {
  Wektor<Typ, Rozmiar> wynik;

  wynik = get_A() * Oblicz() - get_b();

  return wynik;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> UkladRownanLiniowych<Typ, Rozmiar>::Oblicz() const {
  Wektor<Typ, Rozmiar> wynik;
  Macierz<Typ, Rozmiar> mpom = get_A(); 
  Typ wyznaczniki[ROZMIAR]; 
  Typ gl_wyznacznik = get_A().wyznacznik();
  Wektor<Typ, Rozmiar> wolne = get_b(); 
  
  if(abs(gl_wyznacznik) > dokladnosc) {
  
  for(int i = 0; i < ROZMIAR; i++) {
    mpom = mpom.zmien_kolumne(i, wolne);
    wyznaczniki[i] = mpom.wyznacznik();
    wyznaczniki[i] = wyznaczniki[i] / gl_wyznacznik; 
    mpom = get_A();
    }
  }
  else
    {
      cerr << "Glowny wyznacznik wynosi 0. Uklad rownan nie ma rozwiazania." << endl;
      exit(0);
    }
  return Wektor(wyznaczniki);
}

template<typename Typ, int Rozmiar>
istream & operator >> (istream &strm, UkladRownanLiniowych<Typ, Rozmiar> & UklRown) {
  
  Macierz mpom;
  Wektor wpom;

  strm>> mpom;
  strm>> wpom;
  

  UklRown = UkladRownanLiniowych(mpom,wpom);
  return strm;
}

template<typename Typ, int Rozmiar>
ostream & operator << (ostream &strm, const UkladRownanLiniowych<Typ, Rozmiar> & UklRown) {
  cout << "Macierz: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazow wolnych b: " << endl << UklRown.get_b() << endl;
  return strm;
}
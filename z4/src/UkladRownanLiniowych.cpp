#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <math.h>
#include <algorithm>

using namespace std;

Wektor UkladRownanLiniowych::w_bledu() const {
  Wektor wynik;

  wynik = get_A() * Oblicz() - get_b();

  return wynik;
}


double UkladRownanLiniowych::dl_bledu() const {
  double wynik = w_bledu().dlugosc();

  return wynik;
}

Wektor UkladRownanLiniowych::Oblicz() const {
  Wektor wynik;
  Macierz mpom = get_A(); 
  double wyznaczniki[ROZMIAR]; 
  double gl_wyznacznik = get_A().wyznacznik();
  Wektor wolne = get_b(); 
  
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


istream & operator >> (istream &strm, UkladRownanLiniowych & UklRown) {
  
  Macierz mpom;
  Wektor wpom;

  strm>> mpom;
  strm>> wpom;
  

  UklRown = UkladRownanLiniowych(mpom,wpom);
  return strm;
}

ostream & operator << (ostream &strm, const UkladRownanLiniowych & UklRown) {
  cout << "Macierz: " << endl << UklRown.get_A() << endl;
  cout << "Wektor wyrazow wolnych b: " << endl << UklRown.get_b() << endl;
  cout << "Rozwiązanie x=(x1, x2, x3): " << endl << UklRown.Oblicz() << endl;
  cout << "Wektor bledu: Ax-b = " << UklRown.w_bledu() << endl;
  cout << "Dlugosc wektora bledu: |Ax-b| = " << UklRown.dl_bledu() << endl;
  return strm;
}
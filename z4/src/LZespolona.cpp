#include "LZespolona.hh"
#include <cmath>
#include "rozmiar.h"

using namespace std;

LZespolona &LZespolona::operator=(double l)
{
  this->re = l;
  this->im = 0;
  return *this;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = (Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
  Wynik.im = (Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
  return Wynik;
}


LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

 if(Skl2.re == 0 && Skl2.im == 0)         
  {
    cerr << "Nie wolno dzielic przez 0" << endl;
    exit(1);
  }
   Wynik= Skl1*sprzezenie(Skl2)/pow(modul(Skl2),2);
  
  return Wynik; 
  
}

LZespolona  operator * (LZespolona  Skl1,  double  l){
  LZespolona  Wynik;

  Wynik.re = Skl1.re * l;
  Wynik.im = Skl1.im * l;
  return Wynik;
}

LZespolona sprzezenie(LZespolona Skl)
{
  LZespolona Wynik;
   Wynik.re=Skl.re;
   Wynik.im=Skl.im*-1;
   return Wynik;
}

double modul(LZespolona Skl1)
{
  double Wynik;
  Wynik=sqrt((Skl1.re * Skl1.re) + (Skl1.im * Skl1.im));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, double liczba)
{
  LZespolona Wynik;
  if(liczba==0){
  cerr << "Nie wolno dzielic przez 0" << endl;
    exit(1);
  }
  else
  Wynik.re=Skl1.re/liczba;
  Wynik.im=Skl1.im/liczba;
  
  return Wynik;
}


bool operator == (LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    return true;
  else
    return false;

}

bool operator !=(LZespolona Skl1, LZespolona Skl2){
  if(Skl1.re!=Skl2.re || Skl1.im!=Skl2.im)
  return true;
  else
  return false;
}

/*Tworzenie liczby zespolonej */
LZespolona Utworz(double re, double im){
  
  LZespolona liczb;

  liczb.re=re;
  liczb.im=im;

  return liczb;
}


istream & operator >>(istream & strm, LZespolona & Skl){
    char znak;
    strm >> znak;
    if (znak != '(') strm.setstate(ios::failbit);
    strm >> Skl.re >> Skl.im >> znak;
    if (znak != 'i') strm.setstate(ios::failbit);
    strm >> znak;
    if (znak != ')') strm.setstate(ios::failbit);

return strm;
}

ostream & operator << (ostream & strm, LZespolona & Skl){
  strm << "(" << Skl.re << showpos << Skl.im << noshowpos << "i)";
  return strm;
}
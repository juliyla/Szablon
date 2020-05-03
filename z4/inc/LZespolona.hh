#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
#include <cmath>
#include "rozmiar.h"

using namespace std;


 struct LZespolona {
  double   re;   
  double   im;   

 LZespolona()
  {
    re = 0;
    im = 0;
  }
 LZespolona &operator = (double l);
};


LZespolona operator + (LZespolona Skl1, LZespolona Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona  Skl1,  double  l);

LZespolona sprzezenie(LZespolona Skl);
double modul(LZespolona Skl);
LZespolona operator / (LZespolona Skl, double l);

bool operator ==(LZespolona Skl1, LZespolona Skl2);
bool operator !=(LZespolona Skl1, LZespolona Skl2);

istream & operator >>(istream & strm, LZespolona & Skl);
ostream & operator <<(ostream & strm, const LZespolona & Skl); 



#endif

#include "Macierz.hh"
using namespace std;

/*Konstruktory*/

Macierz::Macierz(){
  Wektor W;
  for (int i=0; i < ROZMIAR; i++)
    tab[i] = W;  
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C){
  tab[0] = A;
  tab[1] = B;
  tab[2] = C;
}

/*Operacje matematyczne*/

Macierz Macierz::operator + (const Macierz & M) const{
  Macierz Wynik;
  for(int i=0; i<ROZMIAR; i++){ 
    Wynik[i]=tab[i]+M[i];
    }
  return Wynik;
}

Macierz Macierz::operator - (const Macierz &M) const{
  Macierz Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik [i] = tab[i]-M[i];
  return Wynik;
}

Macierz Macierz::operator *(const Macierz &M) const {
  Macierz Wynik;
  Macierz TranspM = M.transponuj();
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      Wynik[i][j] = tab[i]*TranspM[j];
  return Wynik;
}

Wektor Macierz::operator *(const Wektor &W) const {
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i]*W;
  return Wynik;
}

Macierz Macierz::operator *(const double l) const {
  Macierz Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i]*l;
  return Wynik;
}

Macierz Macierz::transponuj() const {
  Macierz Transp;
  for (int i=0; i<ROZMIAR; i++)
    for (int j=0; j<ROZMIAR; j++)
      Transp[j][i] = tab[i][j];
  return Transp;
}

Macierz Macierz::zmien_kolumne(int kolum, Wektor wek){
  Macierz mpom;
  mpom = transponuj();
  mpom[kolum] = wek;
  mpom = mpom.transponuj();
  return mpom;
}

 double Macierz::wyznacznik()const{
      Macierz M=*this;
      double wyznacznik=1;
      for(int j=0;j<ROZMIAR;j++){         
          for(int i=(j+1);i<ROZMIAR;i++){
            M[i]=M[i]-(M[j]*(M[i][j]/M[j][j]));
          }
      }
      for(int i=0;i<ROZMIAR;i++){
          int j;
          j=i;
              wyznacznik*=M[i][j];
          }
      
      return wyznacznik;
  }

/*Operatory porownania*/

bool Macierz::operator == (const Macierz &M) const {
  for (int i=0; i<ROZMIAR; i++){
    if(tab[i]!=M[i]){
      return false;
   }
  }
  return true;
}

bool Macierz::operator != (const Macierz &M) const {
  for(int i=0; i<ROZMIAR; i++){
    if(tab[i]!=M[i]){
      return true;
   }
  }
  return false;
}

/*Analog set i get*/

const Wektor& Macierz::operator[] (int index) const{
    if (index <0 || index>=ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

Wektor& Macierz::operator[] (int index){
    if (index < 0 || index >= ROZMIAR){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

/*Operatory wczytywania i wyswietlania*/

istream & operator >> (istream &strm, Macierz &M) {
  for (int i=0; i<ROZMIAR; i++)
    strm >> M[i];
  return strm;
}

ostream & operator << (ostream &strm, const Macierz &M) {
  for (int i=0; i<ROZMIAR; i++)
    strm << M[i] << endl;
  return strm;
}
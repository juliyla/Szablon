#include "Macierz.hh"
#include "LZespolona.hh"
using namespace std;

/*Konstruktory*/

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar>::Macierz(){
  for (int i=0; i <Rozmiar;i++){
    for(int j=0;j<Rozmiar;j++){
      tab[i][j]=0;  
}}
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar>::Macierz(const Wektor<Typ, Rozmiar> tab[]){
 for(int i=0; i < ROZMIAR; i++)
        this->tab[i]=tab[i];
}

/*Operacje matematyczne*/

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::operator + (const Macierz<Typ, Rozmiar> & M) const{
  Macierz<Typ, Rozmiar> Wynik;
  for(int i=0; i<ROZMIAR; i++){ 
    Wynik[i]=tab[i]+M[i];
    }
  return Wynik;
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::operator - (const Macierz<Typ, Rozmiar> &M) const{
  Macierz<Typ, Rozmiar> Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik [i] = tab[i]-M[i];
  return Wynik;
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::operator *(const Macierz<Typ, Rozmiar> &M) const {
  Macierz<Typ, Rozmiar> Wynik;
  Macierz<Typ, Rozmiar> TranspM = M.transponuj();
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      Wynik[i][j] = tab[i]*TranspM[j];
  return Wynik;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> Macierz<Typ, Rozmiar>::operator *(const Wektor<Typ, Rozmiar> &W) const {
  Wektor<Typ, Rozmiar> Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i]*W;
  return Wynik;
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::operator *(const double l) const {
  Macierz<Typ, Rozmiar> Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i]*l;
  return Wynik;
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::transponuj() const {
  Macierz<Typ, Rozmiar> Transp;
  for (int i=0; i<ROZMIAR; i++)
    for (int j=0; j<ROZMIAR; j++)
      Transp[j][i] = tab[i][j];
  return Transp;
}

template<typename Typ, int Rozmiar>
Macierz<Typ, Rozmiar> Macierz<Typ, Rozmiar>::zmien_kolumne(int kolum, Wektor<Typ, Rozmiar> wek){
  Macierz<Typ, Rozmiar> mpom;
  mpom = transponuj();
  mpom[kolum] = wek;
  mpom = mpom.transponuj();
  return mpom;
}

template<typename Typ, int Rozmiar>
 Typ Macierz<Typ, Rozmiar>::wyznacznik() const
{
  Typ wyznacznik;
  for (int i = 0; i < Rozmiar; ++i) {      
    for (int j = i+1; j < Rozmiar; ++j) {
     for(int n=i;n<Rozmiar;++n){
      tab[j][n]=tab[j][n]-tab[j][n]/(tab[i][i]*tab[i][n]);
    }
   }
  }
   for(int l=1; l<Rozmiar; l++){
    wyznacznik = wyznacznik*tab[l][l];
  }
  return wyznacznik;
}

/*Operatory porownania*/

template<typename Typ, int Rozmiar>
bool Macierz<Typ, Rozmiar>::operator == (const Macierz<Typ, Rozmiar> &M) const {
  for (int i=0; i<ROZMIAR; i++){
    if(tab[i]!=M[i]){
      return false;
   }
  }
  return true;
}

template<typename Typ, int Rozmiar>
bool Macierz<Typ, Rozmiar>::operator != (const Macierz<Typ, Rozmiar> &M) const {
  for(int i=0; i<ROZMIAR; i++){
    if(tab[i]!=M[i]){
      return true;
   }
  }
  return false;
}

/*Analog set i get*/

template<typename Typ, int Rozmiar>
const Wektor<Typ, Rozmiar> & Macierz<Typ, Rozmiar>::operator[] (int index) const{
    if (index <0 || index>=Rozmiar){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Macierz<Typ, Rozmiar>::operator[] (int index){
    if (index < 0 || index >= Rozmiar){
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    return tab[index];
  }

/*Operatory wczytywania i wyswietlania*/

template<typename Typ, int Rozmiar>
istream & operator >> (istream &strm, Macierz<Typ, Rozmiar> &M) {
  for (int i=0; i<ROZMIAR; i++)
    strm >> M[i];
  return strm;
}

template<typename Typ, int Rozmiar>
ostream & operator << (ostream &strm, const Macierz<Typ, Rozmiar> &M) {
  for (int i=0; i<ROZMIAR; i++)
    strm << M[i] << endl;
  return strm;
}

template class Macierz<double, 5>;
template istream& operator >> (istream &strm, Macierz<double, 5> &M);
template ostream& operator << (ostream &strm, const Macierz<double, 5> &M);

template class Macierz<LZespolona, 5>;
template istream& operator >> (istream &strm, Macierz<LZespolona, 5> &M);
template ostream& operator << (ostream &strm, const Macierz<LZespolona, 5> &M);
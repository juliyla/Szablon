#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include <fstream>
using namespace std;

int main()
{
   cout << "Start programu " << endl << endl;
   char typ;
   cin >> typ;
   if(typ=='r'){
   Wektor<double,ROZMIAR>  Wekbledu;
   UkladRownanLiniowych<double, ROZMIAR> UklRown;
   cin >> UklRown;     
   cout << UklRown << endl;
   cout << "Rozwiazanie x = (x1,x2,x3,x4,x5)" << endl;
   cout << UklRown.Oblicz() << endl;
   Wekbledu = Ukl.w_bledu();
   cout << "Wektor bledu: Ax-b = (" << Wekbledu << ")" << endl;

}
  else if(typ=='z'){
   Wektor<double,ROZMIAR>  Wekbledu;
   UkladRownanLiniowych<LZespolona, ROZMIAR> UklRown;
   cin >> UklRown;     
   cout << UklRown << endl;
   cout << "Rozwiazanie x = (x1,x2,x3,x4,x5)" << endl;
   cout << UklRown.Oblicz() << endl;
   Wekbledu = Ukl.w_bledu();
   cout << "Wektor bledu: Ax-b = ("<<Wekbledu<< ")" << endl;
}

else{
  cout << endl << "Nieprawidlowa opcja wywolania" << endl;
}

  
}

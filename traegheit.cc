#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper* k, double M, int N, Vektor a, Vektor u) 
{
  std::cout  << "berechne fuer " << k->name() << '\n' << std::endl;
  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = (((x-a).kreuz(u)).betrag())/u.betrag();
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
   
    J += m * r * r;
  }
  return J;
}

int main() {
  Koerper* k;
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 1.0;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));
  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));
  
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << traegheit(zm.get(),M,N,a,u) << std::endl;
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << traegheit(vz.get(),M,N,a,u) << std::endl;
  return 0;
}

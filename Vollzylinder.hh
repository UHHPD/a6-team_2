#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Vollzylinder : public Koerper {
public:
  Vollzylinder(double nr, double nl);

  Vektor punkt();
  std:: string  name() {return "Vollzylinder";}
private:
  double r_, l_;
};

#endif

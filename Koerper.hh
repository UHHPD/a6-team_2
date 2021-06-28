#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
  public:
    virtual Vektor punkt() = 0; 
    virtual std:: string  name() {return "Koerper";}
};

#endif
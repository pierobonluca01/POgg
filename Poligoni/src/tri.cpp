//============================================================================
// Name        : tri.cpp
// Project     : Poligoni
// Author      : Luca Pierobon
//============================================================================

#include "tri.h"
#include <cmath>

triangolo::triangolo(const punto v[]): poligono(3,v) {}

double triangolo::area() const{
    double p=perimetro()/2;
    double a=punto::lung(pp[0],pp[1]), b = punto::lung(pp[1],pp[2]),
    c=punto::lung(pp[0],pp[2]);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

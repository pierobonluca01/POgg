//============================================================================
// Name        : ret.cpp
// Project     : Poligoni
// Author      : Luca Pierobon
//============================================================================

#include "ret.h"
#include <cmath>

rettangolo::rettangolo(const punto v[]): poligono(4,v) {}

double rettangolo::perimetro() const {
    return (punto::lung(pp[0], pp[1]))*2 + (punto::lung(pp[1], pp[2]))*2;
}

double rettangolo::area() const{
    return (punto::lung(pp[0], pp[1]))*(punto::lung(pp[1], pp[2]));
}

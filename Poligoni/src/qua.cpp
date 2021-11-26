//============================================================================
// Name        : qua.cpp
// Project     : Poligoni
// Author      : Luca Pierobon
//============================================================================

#include "qua.h"
#include <cmath>

quadrato::quadrato(const punto v[]): rettangolo(v) {}

double quadrato::perimetro() const{
    return (punto::lung(pp[0], pp[1]))*4;
}

double quadrato::area() const{
    return pow(punto::lung(pp[0], pp[1]), 2);
}

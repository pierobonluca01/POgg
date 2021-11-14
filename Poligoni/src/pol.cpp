//============================================================================
// Name        : pol.cpp [Poligoni]
// Author      : Luca Pierobon
//============================================================================

#include <cmath>
#include "pol.h"

punto::punto(double a=0, double b=0): x(a), y(b) {}

double punto::lung(const punto& p1, const punto& p2) {
	return std::sqrt(std::pow(p2.x-p1.x, 2)+std::pow(p2.y-p1.y, 2));
}

poligono::poligono(unsigned int n, const punto v[]): nvertici(n), pp(v) {}



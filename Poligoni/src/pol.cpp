//============================================================================
// Name        : pol.cpp [Poligoni]
// Author      : Luca Pierobon
//============================================================================

#include <cmath>
#include "pol.h"

punto::punto(double a, double b): x(a), y(b) {}

punto::punto(const punto& p): x(p.x), y(p.y) {}

double punto::lung(const punto& p1, const punto& p2) {
	return std::sqrt(std::pow(p2.x-p1.x, 2)+std::pow(p2.y-p1.y, 2));
}

poligono::poligono(unsigned int n, const punto v[]): nvertici(n), pp(v) {}

poligono::poligono(const poligono& pol): nvertici(pol.nvertici), pp(poligono::copia(nvertici, pol.pp)) {}

const punto* poligono::copia(unsigned int nv, const punto* p) {
	punto* newp=new punto[nv];
	for(unsigned int i=0; i<nv; ++i)
		newp[i]=punto(p[i]);
	return newp;
}

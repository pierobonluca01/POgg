//============================================================================
// Name        : pol.cpp
// Project     : Poligoni
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include <cmath>
#include "pol.h"

punto::punto(double a, double b): x(a), y(b) {}

punto::punto(const punto& p): x(p.x), y(p.y) {}

double punto::lung(const punto& p1, const punto& p2) {
	return std::sqrt(std::pow(p2.x-p1.x, 2)+std::pow(p2.y-p1.y, 2));
}

poligono::poligono(unsigned int n, const punto v[]): nvertici(n), pp(v) {}

const punto* poligono::copia(unsigned int nv, const punto* p) {
	punto* aux=new punto[nv];
	for(unsigned int i=0; i<nv; ++i)
		aux[i]=p[i];
	return aux;
}

poligono::~poligono() {
	delete[] pp;
}

poligono& poligono::operator =(const poligono& pol) {
	nvertici=pol.nvertici;
	pp=copia(pol.nvertici, pol.pp);
	return *this;
}

double poligono::perimetro() const {
	double p=0;
	for(unsigned int i=0; i<(nvertici-1); ++i)
		p+=punto::lung(pp[i], pp[i+1]);
	p+=punto::lung(pp[nvertici-1], pp[0]);
	return p;
}

poligono::poligono(const poligono& pol): nvertici(pol.nvertici), pp(poligono::copia(nvertici, pol.pp)) {}

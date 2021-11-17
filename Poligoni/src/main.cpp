//============================================================================
// Name        : main.cpp [Poligoni]
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include "pol.h"


int main() {
	// Codice di test, rimuovere i commenti in pol.h

	punto v[4]={punto(0, 0), punto(0, 2), punto(2, 2), punto(2, 0)};
	poligono a(4, v);

	for(int i=0; i<4; ++i)
		std::cout<<std::endl<<" Punto "<<i<<": "<<a.pp[i].x<<" "<<a.pp[i].y;

	std::cout<<std::endl<<std::endl;;
	std::cout<<" Perimetro: "<<a.perimetro()<<std::endl;

	return 0;
}

//============================================================================
// Name        : telefonata.cpp
// Project     : orario
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include <string>
#include "telefonata.h"

using std::cout;
using std::cin;
using std::endl;


telefonata::telefonata() : numero(0) {} //String
telefonata::telefonata(const orario& i, const orario& f, const int& n) : inizio(i), fine(f), numero(n) {} //String
orario telefonata::Inizio() const {
	return inizio;
}
orario telefonata::Fine() const {
	return fine;
}
int telefonata::Numero() const { //String
	return numero;
}

bool telefonata::operator ==(const telefonata& t) const {
	return inizio==t.inizio && fine==t.fine && numero==t.numero;
}

std::ostream& operator <<(std::ostream& s, const telefonata& t) {
	s<<"Inizio: "<<t.Inizio()<<endl<<"Fine: "<<t.Fine()<<endl<<"Numero Chiamato: "<<t.Numero();
	return s;
}

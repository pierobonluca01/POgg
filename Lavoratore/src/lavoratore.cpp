//============================================================================
// Name        : lavoratore.cpp
// Project     : Lavoratore
// Author      : Luca Pierobon
//============================================================================

#include "lavoratore.h"

#include <iostream>
using std::cout;
using std::endl;

//	Lavoratore

Lavoratore::Lavoratore(string s): nome(s) {}

Lavoratore::~Lavoratore() {}

string Lavoratore::getNome() const {
	return nome;
}

void Lavoratore::printInfo() const {
	cout<<"\t"<<nome;
}


// Dirigente

Dirigente::Dirigente(string s, double d): Lavoratore(s), fissoMensile(d) {}

double Dirigente::stipendio() const {
	return fissoMensile;
}

void Dirigente::printInfo() const {
	cout<<"[Dirigente]\t";
	Lavoratore::printInfo();
}


//	Rappresentante

Rappresentante::Rappresentante(string s, double d, double e, int x): Lavoratore(s), baseMensile(d), commissione(e), tot(x) {}

double Rappresentante::stipendio() const {
	return baseMensile+(commissione*tot);
}

void Rappresentante::printInfo() const {
	cout<<"[Rappresentante]";
	Lavoratore::printInfo();
}


//	LavoratoreOre

LavoratoreOre::LavoratoreOre(string s, double d, double e): Lavoratore(s), pagaOraria(d), oreLavorate(e) {}

double LavoratoreOre::stipendio() const {
	if(oreLavorate<=160)
		return pagaOraria*oreLavorate;
	else
		return (160*pagaOraria)+((oreLavorate-160)*pagaOraria*2);
}

void LavoratoreOre::printInfo() const {
	cout<<"[Lavoratore a ore]";
	Lavoratore::printInfo();
}


//	Altro

void stampaStipendio(const Lavoratore& x) {
	x.printInfo();
	cout<<"\tGuadagno: Euro "<<x.stipendio()<<endl;
}


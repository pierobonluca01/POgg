//============================================================================
// Name        : dataora.cpp
// Project     : orario
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include <string>
#include "dataora.h"

using std::cout;
using std::cin;
using std::endl;

dataora::dataora(int a, int me, int g, int o, int m, int s): orario(o, m, s), anno(a) {
	if(me<1 || me>12)
		mese=1;
	else
		mese=me;
	if(g<0 || g>31 || GiorniDelMese()<g)
		giorno=1;
	else
		giorno=g;
}

int dataora::Giorno() const {
	return giorno;
}
int dataora::Mese() const {
	return mese;
}
int dataora::Anno() const {
	return anno;
}

int dataora::GiorniDelMese() const {
	if(mese==1 || mese==3 || mese==5 || mese==7 || mese==8 || mese==10 || mese==12)
		return 31;
	if(mese==4 || mese==6 || mese==9 || mese==11)
		return 30;
	if(!(anno%400))
		return 29;
	return 28;
}

void dataora::AvanzaUnGiorno() {
	if(giorno<GiorniDelMese())
		giorno++;
	else if(mese<12) {
		giorno=1;
		mese++;
	}
	else {
		giorno=1;
		mese=1;
		anno++;
	}
}

dataora dataora::operator +(const orario& o) const {
	dataora aux=*this;
	aux.sec=sec + 3600*o.Ore() + 60*o.Minuti() + o.Secondi();
	if(aux.sec>=86400) {
		aux.sec=aux.sec-86400;
		aux.AvanzaUnGiorno();
	}
	return aux;
}

giornosett dataorasett::GiornoSettimana() const {
	return giornosettimana;
}

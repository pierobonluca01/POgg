/*
 * dataora.h
 */

#ifndef DATAORA_H_
#define DATAORA_H_

#include "orario.h"

enum giornosett {lun, mar, mer, gio, ven, sab, dom};

class dataora: public orario {
private:
	int giorno;
	int mese;
	int anno;
public:
	dataora(int =2021, int =1, int =1, int =0, int =0, int =0);
	int Giorno() const;
	int Mese() const;
	int Anno() const;
	int GiorniDelMese() const;
	void AvanzaUnGiorno();

	dataora operator +(const orario&) const;
};

class dataorasett: public dataora {
public:
	giornosett GiornoSettimana() const;
private:
	giornosett giornosettimana;
};



#endif /* DATAORA_H_ */

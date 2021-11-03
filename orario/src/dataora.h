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
	int Giorno();
	int Mese();
	int Anno();
};

class dataorasett: public dataora {
public:
	giornosett GiornoSettimana() const;
private:
	giornosett giornosettimana;
};



#endif /* DATAORA_H_ */

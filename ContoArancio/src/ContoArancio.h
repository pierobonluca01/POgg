/*
 * ContoArancio.h
 */

#ifndef CONTOARANCIO_H_
#define CONTOARANCIO_H_

#include "ContoRisparmio.h"

class ContoArancio: public ContoRisparmio {
private:
	ContoCorrente appoggio;
public:
	ContoArancio(ContoCorrente, double =0);
	double deposita(double);
	double preleva(double);
};


#endif /* CONTOARANCIO_H_ */

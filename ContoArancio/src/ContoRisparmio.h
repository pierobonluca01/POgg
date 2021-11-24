/*
 * ContoRisparmio.h
 */

#ifndef CONTORISPARMIO_H_
#define CONTORISPARMIO_H_

#include "ContoCorrente.h"

class ContoRisparmio: public ContoBancario {
public:
	ContoRisparmio(double =0);
	double preleva(double);
};



#endif /* CONTORISPARMIO_H_ */

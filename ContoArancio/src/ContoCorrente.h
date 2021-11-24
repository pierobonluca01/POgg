/*
 * ContoCorrente.h
 */

#ifndef CONTOCORRENTE_H_
#define CONTOCORRENTE_H_

#include "ContoBancario.h"

class ContoCorrente: public ContoBancario {
private:
	static double SpesaFissa;
public:
	ContoCorrente(double =0);
	double deposita(double);
	double preleva(double);
};


#endif /* CONTOCORRENTE_H_ */

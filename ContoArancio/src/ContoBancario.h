/*
 * ContoBancario.h
 */

#ifndef CONTOBANCARIO_H_
#define CONTOBANCARIO_H_

class ContoBancario {
private:
	double saldo;
public:
	ContoBancario(double =0);
	double deposita(double);
	double preleva(double);
	double getSaldo();
};




#endif /* CONTOBANCARIO_H_ */

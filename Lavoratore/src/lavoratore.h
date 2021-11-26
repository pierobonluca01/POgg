/*
 * lavoratore.h
 */

#ifndef LAVORATORE_H_
#define LAVORATORE_H_

#include <string>
using std::string;

class Lavoratore {
private:
	string nome;
public:
	Lavoratore(string s);
	virtual ~Lavoratore() =0;
	string getNome() const;
	virtual double stipendio() const =0;
	virtual void printInfo() const;
};

class Dirigente: public Lavoratore {
private:
	double fissoMensile;
public:
	Dirigente(string, double =0);
	/*virtual*/ double stipendio() const;
	/*virtual*/ void printInfo() const;
};

class Rappresentante: public Lavoratore {
private:
	double baseMensile;
	double commissione;
	int tot;
public:
	Rappresentante(string, double =0, double =0, int =0);
	/*virtual*/ double stipendio() const;
	/*virtual*/ void printInfo() const;
};

class LavoratoreOre: public Lavoratore {
private:
	double pagaOraria;
	double oreLavorate;
public:
	LavoratoreOre(string, double =0, double =0);
	/*virtual*/ double stipendio() const;
	/*virtual*/ void printInfo() const;
};

void stampaStipendio(const Lavoratore&);

#endif /* LAVORATORE_H_ */

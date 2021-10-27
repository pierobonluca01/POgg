/*
 * telefonata.h
 */

#ifndef TELEFONATA_H_
#define TELEFONATA_H_

#include "orario.h"


class telefonata {
private:
	orario inizio;
	orario fine;
	int numero; //String //Const
public:
	telefonata(); //String
	telefonata(const orario& =orario(), const orario& =orario(), const int& =0); //String
	orario Inizio() const;
	orario Fine() const;
	int Numero() const; //String
	bool operator ==(const telefonata&) const;
};

std::ostream& operator <<(std::ostream&, const telefonata&);


#endif /* TELEFONATA_H_ */

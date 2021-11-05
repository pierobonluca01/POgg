/*
 * orario.h
 */

#ifndef ORARIO_H_
#define ORARIO_H_

#include <iostream>

class orario {
public:
	orario(int =0, int =0, int =0);
	int Ore() const;
	int Minuti() const;
	int Secondi() const;
	operator int() { return sec; }

	orario UnOraPiuTardi() const;
	void AvanzaUnOra();

	void StampaSecondi() const;

	static orario OraDiPranzo();
	static const int Sec_di_una_Ora=3600;
	static const int Sec_di_un_Giorno=86400;

	orario operator +(const orario&) const;
	orario operator -(const orario&) const;
	bool operator >(const orario&) const;
	bool operator <(const orario&) const;
	bool operator ==(const orario&) const;

protected:
	int sec;
};

std::ostream& operator <<(std::ostream&, const orario&);


#endif /* ORARIO_H_ */

/*
 * ret.h
 */

#ifndef RET_H_
#define RET_H_

#include "pol.h"

class rettangolo: public poligono { //rettangolo e` un poligono specializzato
public:
	rettangolo(const punto*);
	double perimetro() const;
	double area() const;
};


#endif /* RET_H_ */

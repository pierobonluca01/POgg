/*
 * qua.h
 */

#ifndef QUA_H_
#define QUA_H_

#include "ret.h"

class quadrato: public rettangolo {
public:
	quadrato(const punto*);
	double perimetro() const;
	double area() const;
};


#endif /* QUA_H_ */

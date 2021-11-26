/*
 * tri.h
 */

#ifndef TRI_H_
#define TRI_H_

#include "pol.h"

class triangolo: public poligono {
public:
	triangolo(const punto*);
	double area() const;
};


#endif /* TRI_H_ */

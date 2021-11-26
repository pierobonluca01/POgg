/*
 * pol.h
 */

#ifndef POL_H_
#define POL_H_

//#define protected public
//#define private public

class punto {
protected:
	double x, y;
public:
	punto(double =0, double =0);
	punto(const punto&);
	static double lung(const punto&, const punto&);
};

class poligono {
private:
	static const punto* copia(unsigned int, const punto*);
protected:
	unsigned int nvertici;
	const punto* pp; //Array di punti
public:
	poligono(unsigned int, const punto*);
	virtual ~poligono();
	poligono(const poligono&);
	poligono& operator =(const poligono&);
	virtual double perimetro() const;
	virtual double area() const =0;
};


#endif /* POL_H_ */

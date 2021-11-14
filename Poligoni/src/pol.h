/*
 * pol.h
 */

#ifndef POL_H_
#define POL_H_

class punto {
private:
	double x, y;
public:
	punto(double =0, double =0);
	static double lung(const punto&, const punto&);
};

class poligono {
protected:
	unsigned int nvertici;
	punto* pp;
public:
	poligono(unsigned int, const punto);
	~poligono();
	poligono(const poligono&);
	poligono& operator=(const poligono&);
	double perimetro() const;
};


#endif /* POL_H_ */

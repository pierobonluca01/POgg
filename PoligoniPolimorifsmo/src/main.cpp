//============================================================================
// Name        : main.cpp
// Project     : PoligoniPolimorifsmo
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include "pol.h"
#include "ret.h"
#include "qua.h"
#include "tri.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	int i;
	punto v[4];
	double x, y;
	cout<<"Scrivi le coordinate di un triangolo"<<endl;
	for (i=0; i<3; ++i) {
		cin>>x>>y;
		v[i]=punto(x, y);
	}
	const triangolo tri(v);
	cout<<"Scrivi le coordinate di un rettangolo"<<endl;
	for (i=0; i<4; ++i) {
		cin>>x>>y;
		v[i]=punto(x, y);
	}
	rettangolo ret1(v), ret2=ret1;
	cout<<"Scrivi le coordinate di un quadrato"<<endl;
	for (i=0; i<4; ++i) {
		cin>>x>>y;
		v[i]=punto(x, y);
	}
	quadrato qua1(v), qua2=qua1;
	cout<<"Triangolo:\n"<<tri.perimetro()<<"\t"<<tri.area()<<endl;
	cout<<"Rettangolo:\n"<<ret2.perimetro()<<"\t"<<ret2.area()<<endl;
	cout<<"Quadrato:\n"<<qua2.perimetro()<<"\t"<<qua2.area()<<endl;

	return 0;
}

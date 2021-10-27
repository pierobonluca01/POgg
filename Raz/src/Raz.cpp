//============================================================================
// Name        : Raz.cpp
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Raz {
private:
	int num, den; //Invariante: den!=0

public:
	explicit Raz(int n =0, int d =0): num(n), den(d==0? 1 : d) {}
	Raz inverso() const {
		return Raz(num==0? 0 : den, num);
	}
	operator double() const {
		return static_cast<double>(num)/static_cast<double>(den);
	}
	Raz operator+(const Raz& r) const {
		return Raz(num*r.den + r.num*den, den*r.den);
	}
	Raz operator*(const Raz& r) const {
		return Raz(num*r.num, den*r.den);
	}
	bool operator==(const Raz& r) const {
		return (num*r.den==den*r.num);
	}
	Raz& operator++() {
		num+=den;
		return *this;
	}
	Raz operator++(int) {
		Raz aux(*this);
		num+=den;
		return aux;
	}
	static Raz unTerzo() {
		return Raz(1, 3);
	}
};

std::ostream& operator<<(std::ostream& os, const Raz& r) {
	os<<r.operator double();
	return os;
}

int main() {

	Raz x(2, 3), y(2), z, u(1, 8), v(3, 2), w(8, 4);

	cout<<x+y+v*u<<endl; // 2.85417
	cout<<u.inverso()<<endl; // 8
	cout<<(y==w)<<endl; // true
	cout<<y++<<" "<<++w<<endl; // 2 3
	cout<<(++y + Raz::unTerzo())<<endl; // 4.33333
	cout<<2 + Raz(1, 2)<<endl; // 2.5
	cout<<2 * Raz(1, 2)<<endl;

	return 0;
}


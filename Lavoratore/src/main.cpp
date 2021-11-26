//============================================================================
// Name        : main.cpp
// Project     : Lavoratore
// Author      : Luca Pierobon
//============================================================================

#include "lavoratore.h"

#include <iostream>
using namespace std;


int main() {
	Dirigente luca("Luca", 80000);
	Rappresentante gyarik("Gyarik", 1200, 10, 20);
	LavoratoreOre zac("Zac", 1, 730);

	stampaStipendio(luca);
	stampaStipendio(gyarik);
	stampaStipendio(zac);

	return 0;
}

//============================================================================
// Name        : main
// Project     : ContoBancario
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include "ContoBancario.h"
#include "ContoCorrente.h"
#include "ContoRisparmio.h"
#include "ContoArancio.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
	ContoCorrente cc(2000);
	ContoArancio ca(cc, 1500);
	ca.deposita(350);
	ca.preleva(400);
	cc.preleva(150);
	cout<<cc.getSaldo()<<endl; // stampa: 1897
	cout<<ca.getSaldo()<<endl; // stampa: 1450}
}


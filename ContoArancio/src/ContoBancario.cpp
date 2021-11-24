//============================================================================
// Name        : ContoBancario
// Project     : ContoBancario
// Author      : Luca Pierobon
//============================================================================

#include "ContoBancario.h"

ContoBancario::ContoBancario(double s): saldo(s) {}

double ContoBancario::deposita(double d) {
	return d>0 ? saldo+=d : saldo;
}

double ContoBancario::preleva(double p) {
	return p>0? saldo-=p : saldo;
}

double ContoBancario::getSaldo() {
	return saldo;
}

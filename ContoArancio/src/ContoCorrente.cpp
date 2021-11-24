//============================================================================
// Name        : ContoCorrente
// Project     : ContoBancario
// Author      : Luca Pierobon
//============================================================================

#include "ContoCorrente.h"

double ContoCorrente::SpesaFissa=1.0;

ContoCorrente::ContoCorrente(double s): ContoBancario(s) {}

double ContoCorrente::deposita(double d) {
	return d>SpesaFissa ? ContoBancario::deposita(d-SpesaFissa) : ContoBancario::getSaldo();
}

double ContoCorrente::preleva(double d) {
	return d>SpesaFissa ? ContoBancario::preleva(d+SpesaFissa) : ContoBancario::getSaldo();
}


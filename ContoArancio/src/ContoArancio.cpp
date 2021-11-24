//============================================================================
// Name        : ContoArancio
// Project     : ContoBancario
// Author      : Luca Pierobon
//============================================================================

#include "ContoArancio.h"

ContoArancio::ContoArancio(ContoCorrente cc, double s): ContoRisparmio(s), appoggio(cc) {}

double ContoArancio::deposita(double d) {
	if(d>=0) {
		appoggio.preleva(d);
		return ContoRisparmio::deposita(d);
	}
	return getSaldo();
}

double ContoArancio::preleva(double d) {
	if(d<=getSaldo() && 0<=d) {
		appoggio.deposita(d);
		return ContoRisparmio::preleva(d);
	}
	return getSaldo();
}

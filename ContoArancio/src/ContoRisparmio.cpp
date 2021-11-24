//============================================================================
// Name        : ContoRisparmio
// Project     : ContoBancario
// Author      : Luca Pierobon
//============================================================================

#include "ContoRisparmio.h"

ContoRisparmio::ContoRisparmio(double s): ContoBancario(s) {}

double ContoRisparmio::preleva(double d) {
	return d<getSaldo() ? ContoBancario::preleva(d) : getSaldo();
}

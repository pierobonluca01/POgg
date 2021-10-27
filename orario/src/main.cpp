//============================================================================
// Name        : main.cpp
// Project     : orario
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include <iomanip>
#include "templates.h"
#include "orario.h"
#include "telefonata.h"
#include "bolletta.h"
template orario min(orario, orario);

using std::cout;
using std::cin;
using std::endl;

int main() {
//	orario Mezzanotte;
//	orario Adesso(16, 23, 30);
//	cout<<Adesso.Ore()<<":"<<Adesso.Minuti()<<":"<<Adesso.Secondi();
//	int x=Adesso;
//	cout<<endl<<x<<" Secondi";
//
//	cout<<endl<<endl;
//	Adesso.StampaSecondi();
//
//	cout<<endl<<endl<<"Ora di pranzo: "<<orario::OraDiPranzo().Ore()<<":"<<orario::OraDiPranzo().Minuti();
//
//	orario Ora(22, 45);
//	orario OraF(23, 45);
//	orario DUE_ORE_E_UN_QUARTO(2, 15);
//	Ora=Ora+DUE_ORE_E_UN_QUARTO;
//	cout<<endl<<endl<<Ora;
//	Ora=Ora-DUE_ORE_E_UN_QUARTO;
//	cout<<endl<<Ora;
//	cout<<endl<<(Ora>DUE_ORE_E_UN_QUARTO);
//	cout<<endl<<(Ora<DUE_ORE_E_UN_QUARTO);


	cout<<endl<<endl<<"ZONA TELEFONATA";

	telefonata TIMALuca(orario(12, 30), orario(12, 45), 1); //String
	telefonata FastwebALuca(orario(13, 30), orario(13, 38), 2); //String
	telefonata EoloALuca(orario(15, 45), orario(16, 10), 3); //String
	cout<<endl<<endl<<TIMALuca<<endl<<endl<<FastwebALuca<<endl<<endl<<EoloALuca;
	//cout<<endl<<(TIMALuca==FastwebALuca);

	bolletta Pierobon;
	Pierobon.Aggiungi_Telefonata(TIMALuca);
	Pierobon.Aggiungi_Telefonata(FastwebALuca);
	Pierobon.Aggiungi_Telefonata(EoloALuca);

	cout<<endl<<endl<<"Somma: "<<Somma_Durate(Pierobon);

	int a=5, b=10;
	orario ao(15, 00), bo(16, 00);
	cout<<endl<<endl<<min<int>(a, b);
	cout<<endl<<endl<<min<orario>(ao, bo);

	return 0;
}

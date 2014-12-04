/*
 * Fuel.cpp
 *
 *  Created on: 15/gen/2014
 *      Author: Yamuna
 */

#include "Fuel.h"
#include <iostream>

using namespace std;

Fuel::Fuel() {  //constructor stub
	setLitri();
	setPrezzoLitro();
	setCosto(litri*prezzoLitro);
}

Fuel::~Fuel() {}//destructor stub

void Fuel::setLitri(){ //definisce la capienza media di serbatoio
	cout<<"Che macchina hai?\n";
	cout<<"1_Utilitaria\n2_Suv\n3_Mezzo Pesante\n";
	cin.clear();
	char t=cin.get();
	cin.get();
	switch(t){
    	case '1':
    		cout<< "Hai un'utilitaria, quindi il tuo serbatoio è di circa 45 litri" << endl;
        	litri=45;
        	break;

        case '2':
        	cout<< "Hai un suv, quindi il tuo serbatoio è di circa 65 litri" << endl;
        	litri=65;
        	break;

        case '3':
        	cout<< "Hai un mezzo pesante, quindi il tuo serbatoio è di circa 90 litri" << endl;
        	litri=90;
        	break;

        default:
        	cout<< "Come scusa?" << endl;
        	setLitri();
        	break;

	}
}

void Fuel::setPrezzoLitro(){//definisce il costo medio del carburante oggi (16Gen2014)
	cout<<"Diesel, benzina o GPL?\n";
		cout<<"1_Diesel\n2_Benzina\n3_GPL\n";
		cin.clear();
		char t=cin.get();
		cin.get();
		switch(t){
			case '1':
				cout<< "Il prezzo del Diesel oggi è di 1,690€/L" << endl;
				prezzoLitro=1.690;
				break;

			case '2':
				cout<< "Il prezzo della Benzina oggi è di 1,783€/L" << endl;
				prezzoLitro=1.783;
				break;

			case '3':
				cout<< "Il prezzo del GPL oggi è di 0,852€/L" << endl;
				prezzoLitro=0.852;
				break;

			default:
				cout<< "Come scusa?" << endl;
				setPrezzoLitro();
				break;

		}
}





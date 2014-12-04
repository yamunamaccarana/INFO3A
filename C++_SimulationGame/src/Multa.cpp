/*
 * Multa.cpp
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#include <iostream>
#include "Multa.h"

using namespace std;

Multa::Multa(Livello g) { //constructor stub
	gravita=g;
	if(g==LIEVE) setCosto(50);
	if(g==MEDIO) setCosto(300);
	if(g==GRAVE) setCosto(700);
}

Multa::~Multa() { //destructor stub
}


/*
 * Incidente.cpp
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#include <iostream>
#include "Incidente.h"

using namespace std;

Incidente::Incidente(Livello g) { //constructor stub
	gravita=g;
	if(g==LIEVE) setCosto(200);
	if(g==MEDIO) setCosto(800);
	if(g==GRAVE) setCosto(2000);
}

Incidente::~Incidente() { //destructor stub
}


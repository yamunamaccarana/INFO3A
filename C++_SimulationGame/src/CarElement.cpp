/*
 * CarElement.cpp
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#include "CarElement.h"
#include <iostream>

using namespace std;

CarElement::~CarElement() {} //destructor stub

void CarElement::setFunzione(Funct f){
	funzione=f;
}

Funct CarElement::getFunzione(){
	return this->funzione;
}

void CarElement::setElemento(string el){
	elemento=el;
}

string CarElement::getElemento(){
	return this->elemento;
}



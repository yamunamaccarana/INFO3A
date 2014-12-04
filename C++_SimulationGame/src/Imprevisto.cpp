/*
 * Imprevisto.cpp
 *
 *  Created on: 15/gen/2014
 *      Author: Yamuna
 */

#include "Imprevisto.h"
#include <iostream>

using namespace std;

Imprevisto::~Imprevisto() {} //destructor stub

void Imprevisto::setCosto(double c){
	costo=c;
}

double Imprevisto::getCosto(){
	return this->costo;
}


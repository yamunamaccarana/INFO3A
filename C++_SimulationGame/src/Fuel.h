/*
 * Fuel.h
 *
 *  Created on: 15/gen/2014
 *      Author: Yamuna
 */

#ifndef FUEL_H_
#define FUEL_H_
#include <iostream>
#include "Imprevisto.h"

using namespace std;

class Fuel: public Imprevisto {
public:
	Fuel();
	virtual ~Fuel();

	void setLitri();
	void setPrezzoLitro();

private:
    int litri;
    double prezzoLitro;

};

#endif /* FUEL_H_ */

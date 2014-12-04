/*
 * Multa.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef Multa_H_
#define Multa_H_
#include <iostream>
#include "Imprevisto.h"

using namespace std;

class Multa: public Imprevisto {
public:
	Multa(Livello g);
	virtual ~Multa();

private:
	Livello gravita;

};

#endif /* Multa_H_ */

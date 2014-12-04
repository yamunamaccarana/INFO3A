/*
 * Incidente.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef INCIDENTE_H_
#define INCIDENTE_H_
#include <iostream>
#include "Imprevisto.h"

using namespace std;

class Incidente: public Imprevisto {
public:
	Incidente(Livello g);
	virtual ~Incidente();

private:
	Livello gravita;

};

#endif /* INCIDENTE_H_ */

/*
 * Cambio.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef Cambio_H_
#define Cambio_H_
#include <iostream>
#include "Attuatore.h"

using namespace std;

class Cambio: public Attuatore {
public:
	Cambio();
	virtual ~Cambio();
};

#endif /* Cambio_H_ */

/*
 * Analogico.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef Analogico_H_
#define Analogico_H_
#include <iostream>
#include "Sensore.h"

using namespace std;


class Analogico: public Sensore {
public:
	Analogico();
	virtual ~Analogico();
};

#endif /* Analogico_H_ */

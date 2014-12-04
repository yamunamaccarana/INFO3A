/*
 * Digitale.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef Digitale_H_
#define Digitale_H_
#include <iostream>
#include "Sensore.h"

using namespace std;


class Digitale: public Sensore {
public:
	Digitale();
	virtual ~Digitale();
};

#endif /* Digitale_H_ */

/*
 * Sterzo.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef Sterzo_H_
#define Sterzo_H_
#include <iostream>
#include "Attuatore.h"

using namespace std;

class Sterzo: public Attuatore {
public:
	Sterzo();
	virtual ~Sterzo();
};

#endif /* Sterzo_H_ */

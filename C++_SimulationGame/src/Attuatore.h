/*
 * Attuatore.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef ATTUATORE_H_
#define ATTUATORE_H_
#include <iostream>
#include "CarElement.h"

using namespace std;

class Attuatore: public CarElement{
public:
	Attuatore();
	virtual ~Attuatore();
};

#endif /* ATTUATORE_H_ */

/*
 * ABS.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef ABS_H_
#define ABS_H_
#include <iostream>
#include "Attuatore.h"

using namespace std;

class ABS: public Attuatore {
public:
	ABS();
	virtual ~ABS();
};

#endif /* ABS_H_ */

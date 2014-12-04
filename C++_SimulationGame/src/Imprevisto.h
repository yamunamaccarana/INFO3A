/*
 * Imprevisto.h
 *
 *  Created on: 15/gen/2014
 *      Author: Yamuna
 */

#ifndef IMPREVISTO_H_
#define IMPREVISTO_H_
#include <iostream>

using namespace std;

enum Livello { LIEVE, MEDIO, GRAVE };

class Imprevisto {
public:
	virtual ~Imprevisto();

	virtual void setCosto(double c);
	virtual double getCosto();

private:
	double costo;
};

#endif /* IMPREVISTO_H_ */

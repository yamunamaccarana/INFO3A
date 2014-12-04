/*
 * CarElement.h
 *
 *  Created on: 16/gen/2014
 *      Author: Yamuna
 */

#ifndef CARELEMENT_H_
#define CARELEMENT_H_
#include <iostream>
#include "Imprevisto.h"

using namespace std;

enum Funct { NECESSARIO, UTILE, PREFERIBILE };

class CarElement : public Imprevisto  {
public:

	virtual ~CarElement();

	virtual void setFunzione(Funct f);
	virtual Funct getFunzione();
	virtual void setElemento(string el);
	virtual string getElemento();

protected:
	Funct funzione;
	string elemento;
};


#endif /* CARELEMENT_H_ */

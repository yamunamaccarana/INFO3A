//============================================================================
// Name        : C++.cpp
// Author      : Yamuna Maccarana
// Version     :
// Copyright   : Unibg
// Description : InfoProject in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>
#include <time.h>
#include "Imprevisto.h"
#include "CarElement.h"
#include "Sensore.h"
#include "Digitale.h"
#include "Incidente.h"
#include "ABS.h"
#include "Cambio.h"
#include "Sterzo.h"
#include "Luci.h"
#include "Retromarcia.h"
#include "Velocita.h"
#include "Serbatoio.h"
#include "Fuel.h"
#include "Multa.h"


using namespace std;

//Struttura che associa ad ogni elemento un boolean che indichi se è rotto
struct Rott{
    CarElement c;
    bool b;
} Sabs, Scambio, Ssterzo, Sluci, Sretro, Svel, Sserb;

//Variabili globali
bool giocancora; //variabile booleana che stabilisce la volontà di giocare ancora
double costoTot; //variabile accumulativa del costo di danni e manutenzione
double tempo; //variabile ausiliaria per tener traccia del tempo impiegato
vector<Rott> Rotture; //vettore contenente tutte le rotture
vector<Incidente> Incidenti; //vettore che conterra' eventuali incidenti
vector<Multa> Multe; //vettore che conterra' eventuali multe

void init(){
	srand (time(NULL)); //Random veramente random
	costoTot=0;
	tempo=0;
	giocancora=false;
	//Inizializzo il vettore delle possibili rotture, false=non rotto
	ABS abs; Sabs.c=abs; Sabs.b=false;
	Cambio cambio; Scambio.c=cambio; Scambio.b=false;
	Sterzo sterzo; Ssterzo.c=sterzo; Ssterzo.b=false;
	Luci luci; Sluci.c=luci; Sluci.b=false;
	Retromarcia retro; Sretro.c=retro; Sretro.b=false;
	Velocita vel; Svel.c=vel; Svel.b=false;
	Serbatoio serb; Sserb.c=serb; Sserb.b=false;
	Rotture.push_back(Sabs);
	Rotture.push_back(Scambio);
	Rotture.push_back(Ssterzo);
	Rotture.push_back(Sluci);
	Rotture.push_back(Sretro);
	Rotture.push_back(Svel);
	Rotture.push_back(Sserb);
}

//Possibili imprevisti //////////////////////////////////////////////////////

//Incienti:
void IncidenteLieve(){
	cout<< "Oh no! Che sfortuna! Hai causato un piccolo incidente" << endl;
	Incidente inc(LIEVE);
	costoTot+=inc.getCosto();
	Incidenti.push_back(inc);
	tempo+=2;
	cout<< "Fortunatamente puoi continuare la tua corsa senza grandi danni" << endl;
}

void IncidenteMedio(){
	cout<< "Oh no! Che sfortuna! Hai causato un incidente moderato" << endl;
	Incidente inc(MEDIO);
	costoTot+=inc.getCosto();
	Incidenti.push_back(inc);
	tempo+=3;
	cout<< "Fortunatamente puoi continuare la tua corsa con qualche danno" << endl;
}

void IncidenteGrave(){
	cout<< "Oh no! Che sfortuna! Hai causato un grave incidente!" << endl;
	Incidente inc(GRAVE);
	costoTot+=inc.getCosto();
	Incidenti.push_back(inc);
	cout<< "Se sei ancora vivo, non sei di certo in grado di raggiungere la tua ragazza!" << endl;
	cout<< "Sei SINGLE!" << endl;
	cout<< "GAME OVER" << endl;
	exit(0);
}

//Multe:
void MultaLieve(){
	cout<< "Oh no! Che sfortuna! Hai visto un flash, ma non sai quanto sara' grave la multa!" << endl;
	Multa mul(LIEVE);
	costoTot+=mul.getCosto();
	Multe.push_back(mul);
}

void MultaMedia(){
	cout<< "Oh no! Che sfortuna! Hai visto un flash, ma non sai quanto sara' grave la multa!" << endl;
	Multa mul(MEDIO);
	costoTot+=mul.getCosto();
	Multe.push_back(mul);
}

void MultaGrave(){
	cout<< "Oh no! Che sfortuna! Hai visto un flash, ma non sai quanto sara' grave la multa!" << endl;
	Multa mul(GRAVE);
	costoTot+=mul.getCosto();
	Multe.push_back(mul);
}

//Rotture:
void RotturaLuci(){
	bool t = false;
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //controllo che l'elemento non sia già rotto
		if ((it->c.getElemento())=="Luci" && it->b==false){ //equivalente di istanceOf di java
			it->b=true; //se non è rotto lo imposto come rotto
			t = true;
			cout<< "Oh no! Che sfortuna! Si e' rotto un elemento della macchina" << endl;
			cout<< "Hai dei danni all'impianto luci!" << endl;
			costoTot+=it->c.getCosto();
			cout<< "Fortunatamente puoi continuare la tua corsa" << endl;
		} //altrimenti significa che è già rotto
	}
	if(!t) cout<< "Nessun ulteriore imprevisto, continua cosi'!" << endl;
}

void RotturaRetro(){
	bool t = false;
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //controllo che l'elemento non sia già rotto
		if ((it->c.getElemento())=="Retromarcia" && it->b==false){ //equivalente di istanceOf di java
			it->b=true; //se non è rotto lo imposto come rotto
			t = true;
			cout<< "Oh no! Che sfortuna! Si e' rotto un elemento della macchina" << endl;
			cout<< "Il sensore di retromarcia sembra danneggiato!" << endl;
			costoTot+=it->c.getCosto();
		} //altrimenti significa che è già rotto
	}
	if(!t) cout<< "Nessun ulteriore imprevisto, continua cosi'!" << endl;
}

void RotturaVel(){
	bool t = false;
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //controllo che l'elemento non sia già rotto
	if ((it->c.getElemento())=="Velocita" && it->b==false){ //equivalente di istanceOf di java
		it->b=true; //se non è rotto lo imposto come rotto
		t = true;
		cout<< "Oh no! Che sfortuna! Si e' rotto un elemento della macchina" << endl;
		cout<< "Il sensore di velocita' e' danneggiato!!" << endl;
		costoTot+=it->c.getCosto();
	} //altrimenti significa che è già rotto
	}
	if(!t) cout<< "Nessun ulteriore imprevisto, continua cosi'!" << endl;
}

void RotturaSerb(){
	bool t = false;
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //controllo che l'elemento non sia già rotto
		if ((it->c.getElemento())=="Serbatoio" && it->b==false){ //equivalente di istanceOf di java
			it->b=true; //se non è rotto lo imposto come rotto
			t = true;
			cout<< "Oh no! Che sfortuna! Si e' rotto un elemento della macchina" << endl;
			cout<< "Il sensore della benzina non funziona correttamente!" << endl;
			costoTot+=it->c.getCosto();
		} //altrimenti significa che è già rotto
	}
	if(!t) cout<< "Nessun ulteriore imprevisto, continua cosi'!" << endl;
}

void RotturaABS(){ //se si rompe è GAMEOVER
	cout<< "Oh no! Che sfortuna! Ti si è rotto l'ABS! La tua centralina e' bloccata!" << endl;
	ABS abs;
	costoTot+=abs.getCosto();
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //trovo l'elemento abs
			if ((it->c.getElemento())=="ABS"){ //equivalente di istanceOf di java
				it->b=true;
			}
	}
	cout<< "Sei SINGLE!" << endl;
	cout<< "GAME OVER" << endl;
	exit(0);
}

void RotturaSterzo(){ //se si rompe è GAME OVER
	cout<< "Oh no! Che sfortuna! Eri troppo veloce e hai preso una buca! Ti si è rotto lo sterzo!" << endl;
	Sterzo strz;
	costoTot+=strz.getCosto();
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //trovo l'elemento sterzo
			if ((it->c.getElemento())=="Sterzo"){ //equivalente di istanceOf di java
				it->b=true;
			}
	}
	cout<< "Sei SINGLE!" << endl;
	cout<< "GAME OVER" << endl;
	exit(0);
}

void RotturaCambio(){ //se si rompe è GAME OVER
	cout<< "Oh no! Che sfortuna! Hai esagerato e hai rotto il cambio!" << endl;
	Cambio camb;
	costoTot+=camb.getCosto();
	vector<Rott>::iterator it=Rotture.begin(); //iteratore
	for (it=Rotture.begin(); it!=Rotture.end(); ++it){ //trovo l'elemento cambio
			if ((it->c.getElemento())=="Cambio"){ //equivalente di istanceOf di java
				it->b=true;
			}
	}
	cout<< "Sei SINGLE!" << endl;
	cout<< "GAME OVER" << endl;
	exit(0);
}

//Random dei rischi////////////////////////////////////////////////////////
void random(int i){ //funzione che simula eventuali imprevisti
	int c = 0;
	int d = 0;
	switch(i){
	case 10: //c'è 1/10 di possibilita' di commettere un piccolo incidente
		c=(rand()) % 10;
		if(c==0) IncidenteLieve(); //vero in un caso su 10
		else cout<< "Nessun imprevisto per questo tratto, continua cosi'!" << endl;
		break;
	case 6: //c'è 1/6 di possibilità di commettere piccoli o medi incidenti (2/4) o rotture di elementi preferibili (2/4)
		c=(rand()) % 6;
		if(c==0){ //vero in un caso su 6
			d=(rand()) % 4; //vero in un caso su 4
			if(d==0) IncidenteLieve();
			if(d==1) IncidenteMedio();
			if(d==2) RotturaLuci();
			if(d==3) RotturaRetro();
		}
		else cout<< "Nessun imprevisto per questo tratto, continua cosi'!" << endl;
		break;
	case 4: //c'è 1/4 di possibilità di commettere piccoli o medi incidenti (2/6) o rotture di elementi utili o preferibili (4/6)
		c=(rand()) % 4;
		if(c==0){ //vero in un caso su 4
			d=(rand()) % 6;  //vero in un caso su 6
			if(d==0) IncidenteLieve();
			if(d==1) IncidenteMedio();
			if(d==2) RotturaLuci();
			if(d==3) RotturaRetro();
			if(d==4) RotturaVel();
			if(d==5) RotturaSerb();
		}
		else cout<< "Nessun imprevisto per questo tratto, continua cosi'!" << endl;
		break;
	case 3: //c'è 1/3 di possibilità di commettere incidenti (3/7) o rotture di elementi utili o preferibili (4/7)
		c=(rand()) % 3;
		if(c==0){  //vero in un caso su 3
			d=(rand()) % 7; //vero in un caso su 7
			if(d==0) IncidenteLieve();
			if(d==1) IncidenteMedio();
			if(d==2) IncidenteGrave();
			if(d==3) RotturaLuci();
			if(d==4) RotturaRetro();
			if(d==5) RotturaVel();
			if(d==6) RotturaSerb();
		}
		else cout<< "Nessun imprevisto per questo tratto, continua cosi'!" << endl;
		break;
	case 2: //c'è 1/2 di possibilità di commettere incidenti (3/10) o rotture di elementi (7/10)
		c=(rand()) % 2;
		if(c==0){  //vero in un caso su 2
			d=(rand()) % 10; //vero in un caso su 10
			if(d==0) IncidenteLieve();
			if(d==1) IncidenteMedio();
			if(d==2) IncidenteGrave();
			if(d==3) RotturaLuci();
			if(d==4) RotturaRetro();
			if(d==5) RotturaVel();
			if(d==6) RotturaSerb();
			if(d==7) RotturaABS();
			if(d==8) RotturaSterzo();
			if(d==9) RotturaCambio();
		}
		else cout<< "Nessun imprevisto per questo tratto, continua cosi'!" << endl;
		break;
	}
	return;
}

//Rischi
void risk(int r){
	switch(r){
	case 0:
		cout<< "Sei sicuro?!? Stai perdendo tempo!!!" << endl;
		cout<< "Per lo meno non ti prendi nessun rischio..." << endl;
		break;
	case 1:
		cout<< "Cosi' piano rischi di arrivare in ritardo!" << endl;
		random(10); //basso random
		break;
	case 2:
		cout<< "Sicuro che sia la scelta giusta?" << endl;
		random(6); //medio-basso random
		break;
	case 3:
		cout<< "Sei un amante del rischio!" << endl;
		random(4); //medio random
		break;
	case 4:
		cout<< "Ami l'adrenalina!" << endl;
		random(3); //medio-alto random
		break;
	case 5:
		cout<< "FOLLE!!!" << endl;
		random(2); //alto random
		break;
	}
	return;
}

void rischioMulta(int r){
	int c = 0;
	switch(r){
		case 0:
			c=(rand()) % 10; //un decimo
			if(c==0) MultaLieve();
			break;
		case 1:
			c=(rand()) % 6; //un terzo
			if(c==0) MultaLieve();
			if(c==1) MultaMedia();
			break;
		case 2:
			c=(rand()) % 6; //un mezzo
			if(c==0) MultaLieve();
			if(c==1) MultaMedia();
			if(c==2) MultaGrave();
			break;
	}
}

//Sei in riserva: fai benzina?
void Benzina(){
	cout<< "Saggia decisione." << endl;
	Fuel f;
	cout<< "Il pieno ti è costato:\n" << endl;
	costoTot+=f.getCosto();
	cout<< f.getCosto() << endl;
}

void Riserva(){ //Riserva
	int c;
	c=(rand()) % 2; //un mezzo di possibilità
	if(c==0){
		cout << "Oh no! Sei in riserva! Vuoi fermarti a fare rifornimento (rischi di restare a secco!)? y/n" << endl;
		cin.clear();
		char cmd;
		cmd=cin.get();
		cin.get();  //non va avanti finchè non inserisci un valore
		while(cmd!='y' && cmd!='n'){
			cout<< "Devi decidere se fermarti a fare benzina!" << endl;
			cout<< "y_se vuoi fermarti\nn_altrimenti" << endl;
			cin.clear();
			cmd=cin.get();
			cin.get();
		}
		switch(cmd){
		case 'y':
			Benzina();
			break;
		case 'n':
			c=(rand()) % 3; //un terzo di possibilità di restare a piedi
			if(c==0){
				cout<< "Oh no! Sei rimasto a piedi! Non arriverai mai dalla tua ragazza!" << endl;
				cout<< "Sei SINGLE!" << endl;
				cout<< "GAME OVER" << endl;
				exit(0);
			}
			else cout<< "Rischi di rimanere a piedi!" << endl;
		}
	}
	else cout<< "Hai abbastanza benzina per qualsiasi cosa!" << endl;
}

//Scegli la velocità nei vari tratti////////////////////////////////////////
void ScegliVel1(){
	cout<< "Scegli la tua velocità:" << endl;
	cout<< "1_A passo d'uomo\n2_Piano\n3_Moderata\n4_Molto Veloce\n5_Esagerata" << endl;
    cin.clear();
	char cmd;
	cin >> cmd;
	cin.get();  //non va avanti finchè non inserisci un valore
	switch(cmd){
        case '1':
        	tempo+=5;
        	risk(0); //nessun rischio
        	break;
        case '2':
        	tempo+=4.5;
        	risk(1); //basso rischio
        	break;
        case '3':
        	tempo+=4;
        	risk(2); //medio-basso rischio
        	rischioMulta(0);
        	break;
        case '4':
        	tempo+=3.5;
        	risk(4); //rischio medio-alto
        	rischioMulta(1);
        	break;
        case '5':
        	tempo+=3;
        	risk(5); //rischio alto
        	rischioMulta(2);
        	break;
        default:
        	cout<< "Cosa non hai capito?" << endl;
        	cin.sync(); //Pulisce cin
        	ScegliVel1();
        	//break;
	}
}

void ScegliVel2(){
	cout<< "Scegli la tua velocità:" << endl;
	cout<< "1_A passo d'uomo\n2_Piano\n3_Moderata\n4_Molto Veloce\n5_Esagerata" << endl;
	cin.clear();
	char cmd = 0;
	cin >> cmd;
	cin.get(); //non va avanti finchè non inserisci un valore
	switch(cmd){
        case '1':
        	tempo+=5;
        	risk(0); //nessun rischio
        	break;
        case '2':
        	tempo+=4;
        	risk(0); //nessun rischio
        	break;
        case '3':
        	tempo+=3;
        	risk(2); //medio-basso rischio
        	break;
        case '4':
        	tempo+=2;
        	risk(4); //rischio medio-alto
        	rischioMulta(1);
        	break;
        case '5':
        	tempo+=1;
        	risk(5); //rischio alto
        	rischioMulta(2);
        	break;
        default:
        	cout<< "Cosa non hai capito?" << endl;
        	cin.sync(); //Pulisce cin
        	ScegliVel2();
        	break;
	}
}

void ScegliVel3(){
	cout<< "Scegli la tua velocità:" << endl;
	cout<< "1_A passo d'uomo\n2_Piano\n3_Moderata\n4_Molto Veloce\n5_Esagerata" << endl;
	cin.clear();
	char cmd;
	cin >> cmd;
	cin.get(); //non va avanti finchè non inserisci un valore
	switch(cmd){
        case '1':
        	tempo+=10;
        	risk(0); //nessun rischio
        	break;
        case '2':
        	tempo+=7;
        	risk(0); //nessun rischio
        	break;
        case '3':
        	tempo+=5;
        	risk(1); //basso rischio
        	break;
        case '4':
        	tempo+=3;
        	risk(3); //rischio medio
        	Riserva();
        	rischioMulta(0);
        	break;
        case '5':
        	tempo+=1;
        	risk(4); //rischio medio-alto
        	Riserva();
        	rischioMulta(2);
        	break;
        default:
        	cout<< "Cosa non hai capito?" << endl;
        	cin.sync(); //Pulisce cin
        	ScegliVel3();
        	break;
	}
}

void ScegliVel4(){
	cout<< "Scegli la tua velocità:" << endl;
	cout<< "1_A passo d'uomo\n2_Piano\n3_Moderata\n4_Molto Veloce\n5_Esagerata" << endl;
	cin.clear();
	char cmd;
	cin >> cmd;
	cin.get(); //non va avanti finchè non inserisci un valore
	switch(cmd){
        case '1':
        	tempo+=5;
        	risk(1); //basso rischio
        	break;
        case '2':
        	tempo+=4.5;
        	risk(2); //medio-basso rischio
        	break;
        case '3':
        	tempo+=4;
        	risk(3); //rischio medio
        	rischioMulta(0);
        	break;
        case '4':
        	tempo+=3.5;
        	risk(4); //rischio medio-alto
        	rischioMulta(1);
        	break;
        case '5':
        	tempo+=3;
        	risk(5); //rischio alto
        	rischioMulta(2);
        	break;
        default:
        	cout<< "Cosa non hai capito?" << endl;
        	cin.sync(); //Pulisce cin
        	ScegliVel4();
        	break;
	}
}

//Tratti////////////////////////////////////////////////////////////////////
void benvenuto(){
	cout<< "Benvenuto nel sistema di simulazione di viaggio!" << endl;
	cout<< "Devi raggiungere la tua ragazza in macchina e hai solo 10 minuti!" << endl;
	cout<< "Scegli bene la tua strategia:" << endl;
	cout<< "se andrai troppo piano arriverai in ritardo" << endl;
	cout<< "ma se andrai troppo veloce o non ascolterai gli avvertimenti rischierai brutte sorprese!" << endl;
	cout << "Premere Invio per continuare..." << endl;
    cin.clear();
	while(cin.get()!='\n');
}

void tratto1(){
	cout<< "\nINIZIA LA CORSA!!!" << endl;
	cout<< "Esci di casa, la strada è mal asfaltata e ci sono molti incroci." << endl;
	cout<< "2km ti separano dalla tangenziale." << endl;
	ScegliVel1();
    cin.clear();
    cout << "Premere Invio per continuare..." << endl;
    while(cin.get()!='\n');
}

void tratto2(){
	cout<< "Sei arrivato in tangenziale!!!" << endl;
	cout<< "la strada è piena di buche ma non ci sono incroci." << endl;
	cout<< "2km ti separano dall'autostrada." << endl;
	ScegliVel2();
    cin.clear();
    cout << "Premere Invio per continuare..." << endl;
    while(cin.get()!='\n');
}

void tratto3(){
	cout<< "Sei arrivato in autostrada!!!" << endl;
	cout<< "La strada è ben asfaltata e non ci sono incroci." << endl;
	cout<< "Devi percorrere 4km di autostrada." << endl;
	ScegliVel3();
    cin.clear();
    cout << "Premere Invio per continuare..." << endl;
    while(cin.get()!='\n');
}

void tratto4(){
	cout<< "Sei arrivato in citta'! Ci sei quasi!" << endl;
	cout<< "La strada è ben asfaltata ma piena di incroci." << endl;
	cout<< "Ti mancano 2km alla destinazione." << endl;
	ScegliVel4();
    cin.clear();
    cout << "Premere Invio per continuare..." << endl;
    while(cin.get()!='\n');
}

void conclusione(){
	cout<< "Ce l'hai fatta! Sei arrivato dalla tua ragazza!" << endl;
	//tempo
	cout<< endl << "Hai impiegato ben: " << endl;
	cout<< tempo;
	cout<< " minuti." << endl;
	if (tempo>10 && tempo<=15){
		cout<< "Sei arrivato in ritardo di: " << endl;
		cout<< tempo-10;
		cout<< " minuti." << endl;
		cout<< "La tua ragazza non ci ha fatto caso, bella guida!" << endl;
	}
	if (tempo>15){
		cout<< "Sei arrivato in ritardo di: " << endl;
		cout<< tempo-10;
		cout<< " minuti." << endl;
		cout<< "La tua ragazza e' molto arrabbiata perche' l'hai fatta aspettare!!!" << endl;
		int c=rand() %2;
		if(c==0){
			cout<< "Oh no! La tua ragazza ti ha lasciato! Chissa' se riuscirai a farti perdonare..." << endl;
		}
		else cout<< "Fortunatamente anche lei era in ritardo, per stavolta ti perdonera'." << endl;
	}
	if(tempo<10) cout<< "Bella guida! Complimenti!" << endl;
	//costo
	cout<< endl << "Tra danni, incidenti ed eventuale pieno di benzina hai speso: " << endl;
	cout<< costoTot;
	cout<< " €." << endl;
	//di cui incidenti:
	cout<< endl << "Hai commesso un totale di: " << endl;
	cout<< Incidenti.size();
	cout<< " incidente/i" <<endl;
	vector<Incidente>::iterator itc;
	double costoInc=0;
	if(Incidenti.size()>0){
		for (itc=Incidenti.begin(); itc!=Incidenti.end(); ++itc){ //incidenti
			costoInc+=itc->getCosto();
		}
		cout<< "per un totale di: ";
		cout<< costoInc;
		cout<< " €." << endl;
	}
	//di cui rotture:
	int aus;
	aus=0;
	vector<Rott>::iterator itr=Rotture.begin();
	for (itr=Rotture.begin(); itr!=Rotture.end(); ++itr){ //controllo che l'elemento sia rotto
			if (itr->b==true){ //equivalente di istanceOf di java
				aus=1;
			}
	}
	if(aus==1){
		cout<< "Hai rotto i seguenti pezzi: " << endl;
		for (itr=Rotture.begin(); itr!=Rotture.end(); ++itr){ //controllo che l'elemento sia rotto
			if (itr->b==true){ //equivalente di istanceOf di java
				cout<< itr->c.getElemento() <<endl;
			}
		}
	}
	else cout<< endl << "La tua macchina non ha subito danni funzionali." << endl;
	//di cui multe:
	cout<< endl << "Hai preso un totale di: " << endl;
	cout<< Multe.size();
	cout<< " multa/e";
	double costoM=0;
	vector<Multa>::iterator itm;
	if(Multe.size()>0){
		for (itm=Multe.begin(); itm!=Multe.end(); ++itm){ //incidenti
			costoM+=itm->getCosto();
		}
		cout<< ", per un totale di: " << endl;
		cout<< costoM;
		cout<< " €." << endl;
	}
	cout<< endl << "Vuoi giocare ancora? y/n" << endl;
	cin.clear();
	char cmd;
	cmd=cin.get();
	cin.get();  //non va avanti finchè non inserisci un valore
	while(cmd!='y' && cmd!='n'){
		cout<< "Vuoi giocare ancora o no?!" << endl;
		cout<< "y_se vuoi giocare ancora\nn_altrimenti" << endl;
		cin.clear();
		cmd=cin.get();
		cin.get();
	}
	switch(cmd){
	case 'y':
		giocancora=true;
		break;
	case 'n':
		giocancora=false;
		break;
	}
}

//Main//////////////////////////////////////////////////////////////////////
int main(){
	do{
		init();
		benvenuto();
		tratto1();
		tratto2();
		tratto3();
		tratto4();
		conclusione();
	}while(giocancora==true);
	return 0;
}

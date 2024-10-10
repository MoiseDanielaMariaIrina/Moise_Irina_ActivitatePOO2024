#include<iostream>

using namespace std;

//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector

struct Tara {
	char* denumire; //pointer
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisareTara(Tara tara) {

}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrLocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl;
}

//operatorul ternar - are 3 operanzi; : inseamna altfel
/* if (pt->areIesireLaMare) {
	cout << "DA" << endl;
}
else {
	cout << "NU" << endl;
}*/

Tara* citirePointerLaTara() {
	Tara* p = new Tara(); //se aloca pe heap?

	cout << "Denumire:";
	char buffer[100];            //alocare statica - pe stiva
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer); //am facut toata asta cu strlen si buffer pt ca avem pointer

	cout << "Capitala:";
	cin >> p->capitala; //cin citeste pana la spatiu

	cout << "Numar locuitori:";
	cin >> p->nrLocuitori;

	cout << "Are iesire la mare? (0-NU; 1-DA)";
	cin >> p->areIesireLaMare;

	return p; //p retine adresa
}

int main() {
	Tara tara; //am declarat;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true; //->atribuim
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1]; //alocam spatiu?
	//shallow copy - copiem adresa, nu informatiile
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania"); //copiem?
	pTara->nrLocuitori = 200;

	afisarePointerLaTara(pTara); //pTara este pointer, iar noi facem afisare POINTER

	delete[]pTara->denumire;
	delete pTara;

	/* Tara* p2Tara = citirePointerLaTara();
	afisarePointerLaTara(p2Tara);*/

	Tara* vector;
	vector = new Tara[2];       //alocare dinamica?

	delete[]vector;

	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;         //vector de pointeri la tara
	pointeri = new Tara * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();
		//functia care va citi cele 2 tari
	}

	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		afisarePointerLaTara(pointeri[i]);
	}
	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		delete[]pointeri[i]->denumire;  //[] pt ca e vector?
		delete pointeri[i];

	}
	//memory leak zona de memorie care nu a fost dezalocata si nu mai avem referinta pt ea
	delete[]pointeri;

}
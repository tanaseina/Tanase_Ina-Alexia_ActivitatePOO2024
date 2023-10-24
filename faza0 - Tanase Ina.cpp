
// Tanase Ina -  Domeniul ales de mine este TurIsm(am pus cu majuscule initialele mele)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Tren {
public:
	const int idTren;
	static int nrTrenuri;
	string numeCompanie;
	int nrVagoane;
	int* locuriPerVagon;
	float pretBilet;

	Tren() :idTren(nrTrenuri++) {
		this->numeCompanie = "X";
		this->nrVagoane = 0;
		this->locuriPerVagon = NULL;
		this->pretBilet = 0;
	}

	Tren(string numeCompanie, float pretBilet) :idTren(nrTrenuri++) {
		this->numeCompanie = numeCompanie;
		this->nrVagoane = 0;
		this->locuriPerVagon = NULL;
		this->pretBilet = pretBilet;
	}

	Tren(string numeCompanie, int nrVagoane, int* locuriPerVagon, float pretBilet) :idTren(nrTrenuri++) {
		this->numeCompanie = numeCompanie;
		this->nrVagoane = nrVagoane;
		this->locuriPerVagon = new int[this->nrVagoane];
		for (int i = 0; i < this->nrVagoane; i++) {
			this->locuriPerVagon[i] = locuriPerVagon[i];
		}
		this->pretBilet = pretBilet;

	}

	void afisareTren() {
		cout << "Trenul Companiei : " << this->numeCompanie << " cu id-ul: " << this->idTren << endl;
		if (this->nrVagoane > 0) {
			cout << "Cu " << this->nrVagoane << " vagoane" << endl;
			cout << "Cu numarul de locuri per vagon: ";
			for (int i = 0; i < this->nrVagoane; i++) {
				cout << this->locuriPerVagon[i] << " , ";
			}
			cout << endl;
		}
		else {
			cout << "Trenul are doar locomotiva, nu are vagoane!" << endl;
		}


		cout << "Avand pretul biletului de " << this->pretBilet << " de lei!" << endl;
	}


	static int getNrTrenuri() {
		return nrTrenuri;
	}
};

int Tren::nrTrenuri = 1;

class Insula {
public:
	const int anDescoperire;
	static int numarInsule;
	char* numeInsula;
	float suprafata;
	bool esteLocuita;


	Insula() :anDescoperire(2000) {
		this->numeInsula = new char[strlen("Necunoscuta") + 1];
		strcpy(this->numeInsula, "Necunoscuta");
		this->suprafata = 0;
		this->esteLocuita = 0;
		numarInsule++;
	}

	Insula(const char* numeInsula) :anDescoperire(2010) {
		this->numeInsula = new char[strlen(numeInsula) + 1];
		strcpy(this->numeInsula, numeInsula);
		this->suprafata = 0;
		this->esteLocuita = 0;
		numarInsule++;

	}

	Insula(int anDescoperire, const char* numeInsula, float suprafata, bool esteLocuita) :anDescoperire(anDescoperire) {
		this->numeInsula = new char[strlen(numeInsula) + 1];
		strcpy(this->numeInsula, numeInsula);
		this->suprafata = suprafata;
		this->esteLocuita = esteLocuita;
		numarInsule++;

	}


	void afisareInsula() {
		cout << "Insula: " << this->numeInsula << ", descoperita in anul : " << this->anDescoperire << endl;
		cout << "Avand suprafata de " << this->suprafata << " kmp" << endl;
		if (this->esteLocuita == true) {
			cout << "Este populata si locuibila pe toata perioada anului!" << endl;
		}
		else {
			cout << "Este doar o destinatie turistica pe perioada de cateva luni, nu este locuibila mai mult!" << endl;
		}
	}


	static int getNumarInsule() {
		return numarInsule;
	}

};

int Insula::numarInsule = 1;




class Avion {
public:
	const string codAvion;
	char* numeAvion;
	string culoare;
	int nrDrumuriEfectuate;
	int anFabricatie;
	static int altitudineMaxima;



	Avion():codAvion("X") {
		this->numeAvion = new char[strlen("X") + 1];
		strcpy(this->numeAvion, "X");
		this->culoare = "Alb";
		this->nrDrumuriEfectuate = 0;
		this->anFabricatie = 2000;
	}

	Avion(const char* numeAvion, string culoare) :codAvion("Y") {
		this->numeAvion = new char[strlen(numeAvion) + 1];
		strcpy(this->numeAvion, numeAvion);
		this->culoare = culoare;
		this->nrDrumuriEfectuate = 0;
		this->anFabricatie = 2000;
	}

	Avion(string codAvion, const char* numeAvion, string culoare, int nrDrumuriEfectuate, int anFabricatie) : codAvion(codAvion) {
		this->numeAvion = new char[strlen(numeAvion) + 1];
		strcpy(this->numeAvion, numeAvion);
		this->culoare = culoare;
		this->nrDrumuriEfectuate = nrDrumuriEfectuate;
		this->anFabricatie = anFabricatie;
	}

	static int getAltitudineMaxima() {
		return Avion::altitudineMaxima;
	}

	void afisareAvion() {
		cout << "Avionul " << this->numeAvion << " cu codul inregistat " << this->codAvion << ", de culoarea " << this->culoare;
		cout<< ", a fost construit in anul " << this->anFabricatie << "." << endl;
		cout << "Avionul a efectuat " << this->nrDrumuriEfectuate << " curse." << endl;

	}
};

int Avion::altitudineMaxima = 25000;


int main() {

	Tren t;
	t.afisareTren();

	cout << endl;

	Tren t1("TransRo", 25);
	t1.afisareTren();

	int nrLocuri[] = { 12,14 };
	Tren t2("CFR", 2, nrLocuri, 35);
	t2.afisareTren();

	cout << endl << endl << endl;

	Insula insu;
	insu.afisareInsula();
	cout << insu.getNumarInsule() << endl<<endl;

	Insula in1("Creta");
	in1.afisareInsula();
	cout << in1.getNumarInsule() << endl << endl;

	
	Insula in2(1970,"Maldive",451,1);
	in2.afisareInsula();
	cout << in2.getNumarInsule() << endl << endl;

	cout << endl << endl << endl;

	Avion av;
	av.afisareAvion();
	cout << "Altitudinea maxima a avioanelor: " << av.getAltitudineMaxima() << " metri" << endl;
	cout << endl<<endl;



	Avion av1("Air Bang", "Rosie");
	av1.afisareAvion();
	cout << endl << endl;

	Avion av2("AF123", "Air France", "Albastru", 40, 2015);
	av2.afisareAvion();
	cout << endl << endl;
}
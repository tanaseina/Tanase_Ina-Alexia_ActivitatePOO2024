
// Tanase Ina -  Domeniul ales de mine este TurIsm(am pus cu majuscule initialele mele)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Tren {
	const int idTren;
	static int nrTrenuri;
	string numeCompanie;
	int nrVagoane;
	int* locuriPerVagon;
	float pretBilet;
public:


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

	Tren(const Tren& t) :idTren(t.idTren) {
		this->numeCompanie = t.numeCompanie;
		this->nrVagoane = t.nrVagoane;
		this->locuriPerVagon = new int[this->nrVagoane];
		for (int i = 0; i < this->nrVagoane; i++) {
			this->locuriPerVagon[i] = t.locuriPerVagon[i];
		}
		this->pretBilet = t.pretBilet;
	}

	Tren& operator=(const Tren& t) {
		if (this == &t) {
			return *this;
		}

		this->numeCompanie = t.numeCompanie;
		this->nrVagoane = t.nrVagoane;

		if (this->locuriPerVagon != nullptr) {
			delete[] this->locuriPerVagon;
		}

		this->locuriPerVagon = new int[this->nrVagoane];
		for (int i = 0; i < this->nrVagoane; i++) {
			this->locuriPerVagon[i] = t.locuriPerVagon[i];
		}

		this->pretBilet = t.pretBilet;
		return *this;
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


	~Tren() {
		if (this->locuriPerVagon != NULL) {
			delete[] this->locuriPerVagon;
		}
	}

	int getIdTren() {
		return this->idTren;
	}

	static int getNrTrenuri() {
		return Tren::nrTrenuri;
	}

	static void setNrTrenuri(int nrTrenuri) {
		Tren::nrTrenuri = nrTrenuri;
	}

	string getNumeCompanie() {
		return this->numeCompanie;
	}

	void setNumeCompanie(string numeCompanie) {
		this->numeCompanie = numeCompanie;
	}

	int getNrVagoane() {
		return this->nrVagoane;
	}

	int* getLocuriPerVagon() {
		return this->locuriPerVagon;
	}

	void setLocuriPerVagon(int nrVagoane, int* locuriPerVagon) {
		this->nrVagoane = nrVagoane;
		if (this->locuriPerVagon) {
			delete[] this->locuriPerVagon;
		}
		this->locuriPerVagon = new int[this->nrVagoane];
		for (int i = 0; i < this->nrVagoane; i++) {
			this->locuriPerVagon[i] = locuriPerVagon[i];
		}
	}

	float getPretBilet() {
		return this->pretBilet;
	}

	void setPretBilet(float pretBilet) {
		this->pretBilet = pretBilet;
	}

	friend float valoareSoldOutTren(Tren t);


	friend ostream& operator<<(ostream& os, const Tren& t) {
		os << "Trenul Companiei : " << t.numeCompanie << " cu id-ul: " << t.idTren << endl;
		if (t.nrVagoane > 0) {
			os << "Cu " << t.nrVagoane << " vagoane" << endl;
			os << "Cu numarul de locuri per vagon: ";
			for (int i = 0; i < t.nrVagoane; i++) {
				os << t.locuriPerVagon[i] << " , ";
			}
			os << endl;
		}
		else {
			os << "Trenul are doar locomotiva, nu are vagoane!" << endl;
		}
		os << "Avand pretul biletului de " << t.pretBilet << " de lei!" << endl;
		return os;
	}

	bool operator==(const Tren& t) {
		return this->idTren == t.idTren;
	}

	int operator[](int index) {
		if (index >= 0 && index < nrVagoane) {
			return locuriPerVagon[index];
		}
		return -1;
	}

	float operator()() {
		int locuriTotale = 0;
		for (int i = 0; i < this->nrVagoane; i++) {
			locuriTotale += locuriPerVagon[i];
		}
		return locuriTotale;
	}
};
float valoareSoldOutTren(Tren t) {
	float locuriTotale = 0;
	for (int i = 0; i < t.nrVagoane; i++) {
		locuriTotale = locuriTotale + t.locuriPerVagon[i];
	}
	return locuriTotale * t.pretBilet;
}
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

	Insula(const Insula& ins) :anDescoperire(ins.anDescoperire) {
		this->numeInsula = new char[strlen(ins.numeInsula) + 1];
		strcpy(this->numeInsula, ins.numeInsula);
		this->suprafata = ins.suprafata;
		this->esteLocuita = ins.esteLocuita;
		numarInsule++;
	}

	Insula& operator=(const Insula& ins) {
		if (this == &ins) {
			return *this;
		}

		if (this->numeInsula) {
			delete[] this->numeInsula;
		}

		this->numeInsula = new char[strlen(ins.numeInsula) + 1];
		strcpy(this->numeInsula, ins.numeInsula);

		this->suprafata = ins.suprafata;
		this->esteLocuita = ins.esteLocuita;
		return *this;
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

	friend ostream& operator<<(ostream& os, const Insula& ins) {
		os << "Insula: " << ins.numeInsula << ", descoperita in anul: " << ins.anDescoperire << endl;
		os << "Avand suprafata de " << ins.suprafata << " kmp" << endl;
		if (ins.esteLocuita) {
			os << "Este populata si locuibila pe toata perioada anului!" << endl;
		}
		else {
			os << "Este doar o destinatie turistica pe perioada de cateva luni, nu este locuibila mai mult!" << endl;
		}
		return os;
	}

	~Insula() {
		if (this->numeInsula) {
			delete[] this->numeInsula;
		}
	}

	const int getAnDescoperire() {
		return this->anDescoperire;
	}

	char* getNumeInsula() {
		return this->numeInsula;
	}

	void setNumeInsula(const char* numeInsula) {
		if (this->numeInsula) {
			delete[] this->numeInsula;
		}
		this->numeInsula = new char[strlen(numeInsula) + 1];
		strcpy(this->numeInsula, numeInsula);
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}

	bool getEsteLocuita() {
		return this->esteLocuita;
	}

	void setEsteLocuita(bool esteLocuita) {
		this->esteLocuita = esteLocuita;
	}

	static int getNumarInsule() {
		return Insula::numarInsule;
	}

	static void setNumarInsule(int numarInsule) {
		Insula::numarInsule = numarInsule;
	}


	friend double kmPatratiInHectare(Insula ins);

	bool operator==(const Insula& ins) {
		return this->anDescoperire == ins.anDescoperire;
	}

	Insula operator+(const Insula& ins) {
		Insula newIns = *this;
		newIns.suprafata = this->suprafata + ins.suprafata;
		newIns.esteLocuita = this->esteLocuita || ins.esteLocuita;
		return newIns;
	}

	explicit operator bool() {
		return this->esteLocuita;
	}

};

int Insula::numarInsule = 1;
double kmPatratiInHectare(Insula ins) {
	return ins.suprafata * 1000;
}



class Avion {
	const string codAvion;
	char* numeAvion;
	string culoare;
	int nrDrumuriEfectuate;
	int anFabricatie;
	static int altitudineMaxima;
public:


	Avion() :codAvion("X") {
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

	Avion(const Avion& a) :codAvion(a.codAvion) {
		this->numeAvion = new char[strlen(a.numeAvion) + 1];
		strcpy(this->numeAvion, a.numeAvion);
		this->culoare = culoare;
		this->nrDrumuriEfectuate = a.nrDrumuriEfectuate;
		this->anFabricatie = a.anFabricatie;
	}

	Avion& operator=(const Avion& a) {
		if (this == &a) {
			return *this;
		}

		if (this->numeAvion) {
			delete[] this->numeAvion;
		}

		this->numeAvion = new char[strlen(a.numeAvion) + 1];
		strcpy(this->numeAvion, a.numeAvion);

		this->culoare = a.culoare;
		this->nrDrumuriEfectuate = a.nrDrumuriEfectuate;
		this->anFabricatie = a.anFabricatie;
		return *this;
	}

	void afisareAvion() {
		cout << "Avionul " << this->numeAvion << " cu codul inregistat " << this->codAvion << ", de culoarea " << this->culoare;
		cout << ", a fost construit in anul " << this->anFabricatie << "." << endl;
		cout << "Avionul a efectuat " << this->nrDrumuriEfectuate << " curse." << endl;

	}

	~Avion() {
		delete[] this->numeAvion;
	}

	const string getCodAvion() {
		return this->codAvion;
	}

	char* getNumeAvion() {
		return this->numeAvion;
	}

	void setNumeAvion(const char* numeAvion) {
		if (this->numeAvion) {
			delete[] this->numeAvion;
		}
		this->numeAvion = new char[strlen(numeAvion) + 1];
		strcpy(this->numeAvion, numeAvion);
	}

	string getCuloare() {
		return this->culoare;
	}

	void setCuloare(const string culoare) {
		this->culoare = culoare;
	}

	int getNrDrumuriEfectuate() {
		return this->nrDrumuriEfectuate;
	}

	void setNrDrumuriEfectuate(int nrDrumuriEfectuate) {
		this->nrDrumuriEfectuate = nrDrumuriEfectuate;
	}

	int getAnFabricatie() {
		return this->anFabricatie;
	}

	void setAnFabricatie(int anFabricatie) {
		this->anFabricatie = anFabricatie;
	}

	static int getAltitudineMaxima() {
		return altitudineMaxima;
	}

	static void setAltitudineMaxima(int altitudineMaxima) {
		Avion::altitudineMaxima = altitudineMaxima;
	}

	bool operator==(const Avion& a) {
		return this->codAvion == a.codAvion;
	}

	Avion operator-(int nr) {
		Avion newAv = *this;
		newAv.nrDrumuriEfectuate -= nr;
		return newAv;
	}

	float operator()() {
		this->nrDrumuriEfectuate;
	}

	friend ostream& operator<<(ostream& os, const Avion& a) {
		os << "Avionul " << a.numeAvion << " cu codul inregistat " << a.codAvion << ", de culoarea " << a.culoare;
		os << ", a fost construit in anul " << a.anFabricatie << "." << endl;
		os << "Avionul a efectuat " << a.nrDrumuriEfectuate << " curse." << endl;
		return os;
	}
};

int Avion::altitudineMaxima = 25000;


int main() {

	Tren t;
	t.afisareTren();
	cout << endl << endl;

	cout << "Getteri:" << endl;
	cout << " Id: " << t.getIdTren() << endl;
	cout << "Nume Companie: " << t.getNumeCompanie() << endl;
	cout << " Nr. Vagoane: " << t.getNrVagoane() << endl;
	cout << "Locuri per vagon: ";
	for (int i = 0; i < t.getNrVagoane(); i++) {
		cout << t.getLocuriPerVagon()[i] << " locuri, ";
	}
	cout << endl;
	cout << "Preturi Bilete: " << t.getPretBilet() << endl;
	cout << "Numar trenuri: " << t.getNrTrenuri() << endl;


	int locuriVagon[] = { 120, 160, 110, 140 };
	t.setNumeCompanie("I.N.A Transport");
	t.setLocuriPerVagon(4, locuriVagon);
	t.setPretBilet(60.0);
	t.setNrTrenuri(45);

	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << " Id: " << t.getIdTren() << endl;
	cout << "Nume Companie: " << t.getNumeCompanie() << endl;
	cout << " Nr. Vagoane: " << t.getNrVagoane() << endl;
	cout << "Locuri per vagon: ";
	for (int i = 0; i < t.getNrVagoane(); i++) {
		cout << t.getLocuriPerVagon()[i] << " locuri, ";
	}
	cout << endl;
	cout << "Preturi Bilete: " << t.getPretBilet() << endl;
	cout << "Numar trenuri: " << t.getNrTrenuri() << endl;


	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	cout << endl << endl;

	Tren t1("TransRo", 25);
	t1.afisareTren();

	cout << endl << endl;
	int nrLocuri[] = { 12,14 };
	Tren t2("CFR", 2, nrLocuri, 35);
	t2.afisareTren();

	cout << endl << endl;
	Tren t3 = t2;
	t3.afisareTren();
	cout << endl;
	cout << "Cat castiga la o cursa sold-out: " << valoareSoldOutTren(t3) << " lei" << endl;
	cout << endl << endl << endl << endl << endl << endl;


	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Insula insu;
	insu.afisareInsula();
	cout << endl << endl;
	cout << "Getteri:" << endl;
	cout << "An Descoperire Insula: " << insu.getAnDescoperire() << endl;
	cout << "Nume Insula: " << insu.getNumeInsula() << endl;
	cout << "Suprafata: " << insu.getSuprafata() << endl;
	cout << "Este locuita: " << insu.getEsteLocuita() << endl;
	cout << "Numar de insule: " << Insula::getNumarInsule() << endl;
	cout << endl << endl;

	insu.setNumeInsula("Hawaii");
	insu.setSuprafata(6422.6);
	insu.setEsteLocuita(true);

	Insula::setNumarInsule(10);

	cout << "An Descoperire Insula: " << insu.getAnDescoperire() << endl;
	cout << "Nume Insula: " << insu.getNumeInsula() << endl;
	cout << "Suprafata: " << insu.getSuprafata() << endl;
	cout << "Este locuita: " << insu.getEsteLocuita() << endl;
	cout << "Numar de insule: " << Insula::getNumarInsule() << endl;
	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	Insula in1("Creta");
	in1.afisareInsula();
	cout << endl << endl;

	Insula in2(1970, "Maldive", 451, 1);
	in2.afisareInsula();
	cout << in2.getNumarInsule() << endl << endl;

	cout << endl << endl;

	Insula in3 = in2;
	in3.afisareInsula();
	cout << endl << endl;

	cout << "Insula are in jur de: " << kmPatratiInHectare(in3) << " hectare de pamant" << endl;

	cout << endl << endl << endl << endl << endl << endl;

	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Avion av;
	av.afisareAvion();
	cout << "Cod Avion: " << av.getCodAvion() << endl;
	cout << "Nume Avion: " << av.getNumeAvion() << endl;
	cout << "Culoare: " << av.getCuloare() << endl;
	cout << "Nr. Drumuri Efectuate: " << av.getNrDrumuriEfectuate() << endl;
	cout << "An Fabricatie: " << av.getAnFabricatie() << endl;
	cout << "Altitudine Maxima: " << Avion::getAltitudineMaxima() << endl;

	av.setNumeAvion("Airbus A320");
	av.setCuloare("Albastru");
	av.setNrDrumuriEfectuate(120);
	av.setAnFabricatie(2005);
	Avion::setAltitudineMaxima(40000);


	cout << endl << endl;

	cout << "Cod Avion: " << av.getCodAvion() << endl;
	cout << "Nume Avion: " << av.getNumeAvion() << endl;
	cout << "Culoare: " << av.getCuloare() << endl;
	cout << "Nr. Drumuri Efectuate: " << av.getNrDrumuriEfectuate() << endl;
	cout << "An Fabricatie: " << av.getAnFabricatie() << endl;
	cout << "Altitudine Maxima: " << Avion::getAltitudineMaxima() << endl;

	cout << endl << endl;

	av.afisareAvion();
	cout <<endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Avion av1("Air Bang", "Rosie");
	av1.afisareAvion();
	cout << endl << endl;

	Avion av2("AF123", "Air France", "Albastru", 40, 2015);
	av2.afisareAvion();
	cout << endl << endl;

	Avion av3 = av2;
	av3.afisareAvion();

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "Operatorul de atribuire: " << endl;
	Tren t4;
	t4 = t2;
	cout << t1 << endl;
	cout << t1 << endl;
	cout << t4 << endl;
	cout << t2 << endl;

	cout << endl;
	cout << "Operatorul de egalitate (==): ";
	cout << (t == t1) << endl;

	cout << "Operatorul de indexare ([]): ";
	cout << "Locuri in primul vagon: " << t[0] << endl;

	cout << endl;
	cout << "Operatorul functie(): ";
	cout << t() << endl;
	cout << t2() << endl;

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	Insula insu1;
	cout << insu1 << endl;

	cout << "Operatorul de atribuire: " << endl;
	Insula insu2;
	insu2 = in3;
	cout << insu2 << endl;

	cout << "Operatorul de egalitate (==): ";
	cout << (insu2 == insu1) << endl;

	cout << "Operatorul de adunare (+): " << endl;
	Insula insu3;
	insu3 = insu2 + in3;
	cout << insu3 << endl;
	cout << insu2 << endl;
	cout << in3 << endl;

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	cout << "Operatorul de atribuire: " << endl;
	Avion av4;
	av4 = av2;
	cout << av4 << endl;

	cout << "Operatorul de egalitate (==): ";
	cout << (av4 == av3) << endl;

	cout << "Operatorul de scadere (-): " << endl;
	Avion av5;
	av5 = av2 - 5;
	cout << av5 << endl;
	cout << av2 << endl;

}
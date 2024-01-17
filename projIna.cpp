// Tanase Ina -  Domeniul ales de mine este TurIsm(am pus cu majuscule initialele mele)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class AfisareObiect {
public:
	virtual void afisare() = 0;
};


class RecunoastereObiect {
public:
	virtual string exemplarClasa() = 0;
};



class Tren:public AfisareObiect, public RecunoastereObiect {
protected:
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

	void afisare() {
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
				os << t.locuriPerVagon[i] << " locuri, ";
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

	friend istream& operator>>(istream& in, Tren& tren) {
		in >> tren.numeCompanie;
		in >> tren.nrVagoane;
		tren.locuriPerVagon = new int[tren.nrVagoane];
		for (int i = 0; i < tren.nrVagoane; ++i) {
			in >> tren.locuriPerVagon[i];
		}

		in >> tren.pretBilet;

		return in;
	}

	friend ofstream& operator<<(ofstream& os, const Tren& t) {
		os << t.numeCompanie << endl;
		os << t.nrVagoane << endl;
		for (int i = 0; i < t.nrVagoane; i++) {
			os << t.locuriPerVagon[i] << endl;
		}
		os << endl;
		os << t.pretBilet << endl;
		return os;
	}

	friend ifstream& operator>>(ifstream& in, Tren& tren) {
		in >> tren.numeCompanie;
		in >> tren.nrVagoane;
		tren.locuriPerVagon = new int[tren.nrVagoane];
		for (int i = 0; i < tren.nrVagoane; ++i) {
			in >> tren.locuriPerVagon[i];
		}

		in >> tren.pretBilet;

		return in;
	}

	string exemplarClasa() {
		return "TREN!!";
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

class TrenDeMarfa : public Tren {
	float capacitateMarfa;
	bool transportInternational;
	char* destinatieCurenta;
public:
	TrenDeMarfa() :Tren() {
		this->capacitateMarfa = 0;
		this->transportInternational = 0;
		this->destinatieCurenta = new char[strlen("Y") + 1];
		strcpy(this->destinatieCurenta, "Y");
	}

	TrenDeMarfa(string numeCompanie, int nrVagoane, int* locuriPerVagon, float pretBilet) :Tren(numeCompanie, nrVagoane, locuriPerVagon, pretBilet) {
		this->capacitateMarfa = 0;
		this->transportInternational = 0;
		this->destinatieCurenta = new char[strlen("Y") + 1];
		strcpy(this->destinatieCurenta, "Y");
	}
	TrenDeMarfa(string numeCompanie, int nrVagoane, int* locuriPerVagon, float pretBilet, float capacitateMarfa, bool transportInternational, const char* destinatieCurenta) :Tren(numeCompanie, nrVagoane, locuriPerVagon, pretBilet) {
		this->capacitateMarfa = capacitateMarfa;
		this->transportInternational = transportInternational;
		this->destinatieCurenta = new char[strlen(destinatieCurenta) + 1];
		strcpy(this->destinatieCurenta, destinatieCurenta);
	}

	TrenDeMarfa(const TrenDeMarfa& m) :Tren(m) {
		this->capacitateMarfa = m.capacitateMarfa;
		this->transportInternational = m.transportInternational;
		this->destinatieCurenta = new char[strlen(m.destinatieCurenta) + 1];
		strcpy(this->destinatieCurenta, m.destinatieCurenta);
	}

	~TrenDeMarfa() {
		if (this->destinatieCurenta != NULL) {
			delete[]this->destinatieCurenta;
		}
	}


	TrenDeMarfa& operator=(const TrenDeMarfa& m) {
		if (this != &m) {
			if (this->destinatieCurenta != NULL) {
				delete[]this->destinatieCurenta;
			}
			Tren::operator=(m);
			this->capacitateMarfa = m.capacitateMarfa;
			this->transportInternational = m.transportInternational;
			this->destinatieCurenta = new char[strlen(m.destinatieCurenta) + 1];
			strcpy(this->destinatieCurenta, m.destinatieCurenta);
		}
		return *this;
	}

	void afisare() {
		Tren::afisare();
		cout << "Capacitate marfa: " << capacitateMarfa << " tone"<<endl;
		cout << "Transport international: " << (transportInternational ? "Da" : "Nu") << endl;
		cout << "Destinatie curenta: " << destinatieCurenta << endl;
	}

	friend ostream& operator<<(ostream& os, const TrenDeMarfa& t) {
		os << (Tren&)t;
		os << "Capacitate marfa: " << t.capacitateMarfa << " tone";
		os << "Transport international: " << (t.transportInternational ? "Da" : "Nu") << endl;
		os << "Destinatie curenta: " << t.destinatieCurenta << endl;
		return os;
	}

	string exemplarClasa() {
		return "Tren De Marfa!";
	}
};


class Insula: public AfisareObiect, public RecunoastereObiect {
	const int anDescoperire;
	static int numarInsule;
	char* numeInsula;
	float suprafata;
	bool esteLocuita;
public:

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

	void afisare() {
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


	friend istream& operator>>(istream& in, Insula& insula) {
		in >> insula.numeInsula;
		in >> insula.suprafata;
		in >> insula.esteLocuita;

		return in;
	}

	friend ofstream& operator<<(ofstream& os, const Insula& ins) {
		os << ins.numeInsula << endl;
		os << ins.suprafata << endl;
		if (ins.esteLocuita) {
			os << endl;
		}
		else {
			os << endl;
		}
		return os;
	}
	friend ifstream& operator>>(ifstream& in, Insula& insula) {
		in >> insula.numeInsula;
		in >> insula.suprafata;
		in >> insula.esteLocuita;

		return in;
	}

	void serializare(string fisierInsula) {
		ofstream f(fisierInsula, ios::out | ios::binary);
		int dimNumeInsula = strlen(this->numeInsula);
		f.write((char*)&dimNumeInsula, sizeof(dimNumeInsula));
		f.write(this->numeInsula, dimNumeInsula + 1);
		f.write((char*)&suprafata, sizeof(suprafata));
		f.write((char*)&esteLocuita, sizeof(esteLocuita));
		f.close();
	}

	void deserializare(string fisierInsula) {
		ifstream f(fisierInsula, ios::in | ios::binary);
		if (f.is_open())
		{
			if (this->numeInsula != NULL) {
				delete[]this->numeInsula;
			}
			int dimNumeInsula = 0;
			f.read((char*)&dimNumeInsula, sizeof(dimNumeInsula));
			this->numeInsula = new char[dimNumeInsula + 1];
			f.read(this->numeInsula, dimNumeInsula + 1);
			f.read((char*)&this->suprafata, sizeof(this->suprafata));
			f.read((char*)&this->esteLocuita, sizeof(this->esteLocuita));
			f.close();
		}
		else {
			cout << "Fisierul cautat nu exista!" << endl;
		}
	}

	string exemplarClasa() {
		return "Insula";
	}
};

int Insula::numarInsule = 1;
double kmPatratiInHectare(Insula ins) {
	return ins.suprafata * 1000;
}



class Avion {
protected:
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

	friend istream& operator>>(istream& in, Avion& avion) {
		in >> avion.numeAvion;
		in >> avion.culoare;
		in >> avion.nrDrumuriEfectuate;
		in >> avion.anFabricatie;

		return in;
	}

	void serializare(string fisierAvion) {
		ofstream f(fisierAvion, ios::out | ios::binary);
		int dimCuloare = this->culoare.size();
		f.write((char*)&dimCuloare, sizeof(dimCuloare));
		f.write(this->culoare.c_str(), dimCuloare + 1);
		int dimnumeAvion = strlen(this->numeAvion);
		f.write((char*)&dimnumeAvion, sizeof(dimnumeAvion));
		f.write(this->numeAvion, dimnumeAvion + 1);
		f.write((char*)&nrDrumuriEfectuate, sizeof(nrDrumuriEfectuate));
		f.write((char*)&anFabricatie, sizeof(anFabricatie));
		f.close();
	}

	void deserializare(string fisierAvion) {
		ifstream f(fisierAvion, ios::in | ios::binary);
		if (f.is_open())
		{
			if (this->numeAvion != NULL) {
				delete[]this->numeAvion;
			}
			int dimCuloare = 0;
			f.read((char*)&dimCuloare, sizeof(dimCuloare));
			char* aux = new char[dimCuloare + 1];
			f.read(aux, dimCuloare + 1);
			this->culoare = aux;
			delete[]aux;
			int dimnumeAvion = 0;
			f.read((char*)&dimnumeAvion, sizeof(dimnumeAvion));
			this->numeAvion = new char[dimnumeAvion + 1];
			f.read(this->numeAvion, dimnumeAvion + 1);
			f.read((char*)&this->nrDrumuriEfectuate, sizeof(this->nrDrumuriEfectuate));
			f.read((char*)&this->anFabricatie, sizeof(this->anFabricatie));
			f.close();
		}
		else {
			cout << "Fisierul cautat nu exista!" << endl;
		}
	}

};

int Avion::altitudineMaxima = 25000;

class AvionDeLupta : public Avion {
	int numarRachete;
	bool esteSupersonic;
public:
	AvionDeLupta() : Avion() {
		this->numarRachete = 0;
		this->esteSupersonic = false;
	}

	AvionDeLupta(string codAvion, const char* numeAvion, string culoare, int nrDrumuriEfectuate, int anFabricatie, int numarRachete, bool esteSupersonic)
		: Avion(codAvion, numeAvion, culoare, nrDrumuriEfectuate, anFabricatie) {
		this->numarRachete = numarRachete;
		this->esteSupersonic = esteSupersonic;
	}
	AvionDeLupta(const AvionDeLupta& av) : Avion(av) {
		this->numarRachete = av.numarRachete;
		this->esteSupersonic = av.esteSupersonic;
	}

	~AvionDeLupta() {
	}

	AvionDeLupta& operator=(const AvionDeLupta& av) {
		if (this != &av) {
			Avion::operator=(av);
			this->numarRachete = av.numarRachete;
			this->esteSupersonic = av.esteSupersonic;
		}
		return *this;
	}


	friend ostream& operator<<(ostream& os, const AvionDeLupta& av) {
		os << (Avion)av;
		os << "Numar rachete: " << av.numarRachete << endl;
		os << "Este supersonic: " << (av.esteSupersonic ? "Da" : "Nu") << endl;
		return os;
	}
};

class Gara {
	string oras;
	int nrLinii;
	float suprafata;
	int nrTrenuri;
	Tren* trenuri;

public:
	Gara() {
		this->oras = "Anonim";
		this->nrLinii = 0;
		this->suprafata = 0;
		this->nrTrenuri = 0;
		this->trenuri = NULL;
	}

	Gara(string oras, int nrLinii, float suprafata, int nrTrenuri, Tren* trenuri) {
		this->oras = oras;
		this->nrLinii = nrLinii;
		this->suprafata = suprafata;
		this->nrTrenuri = nrTrenuri;
		this->trenuri = new Tren[nrTrenuri];
		for (int i = 0; i < nrTrenuri; ++i) {
			this->trenuri[i] = trenuri[i];
		}
	}

	Gara(const Gara& g) {
		this->oras = g.oras;
		this->nrLinii = g.nrLinii;
		this->suprafata = g.suprafata;
		this->nrTrenuri = g.nrTrenuri;
		this->trenuri = new Tren[g.nrTrenuri];
		for (int i = 0; i < g.nrTrenuri; ++i) {
			this->trenuri[i] = g.trenuri[i];
		}
	}

	Gara& operator=(const Gara& g) {
		if (this != &g) {
			delete[] this->trenuri;
			this->oras = g.oras;
			this->nrLinii = g.nrLinii;
			this->suprafata = g.suprafata;
			this->nrTrenuri = g.nrTrenuri;
			this->trenuri = new Tren[g.nrTrenuri];
			for (int i = 0; i < g.nrTrenuri; ++i) {
				this->trenuri[i] = g.trenuri[i];
			}
		}
		return *this;
	}

	~Gara() {
		delete[] trenuri;
	}

	friend ostream& operator<<(ostream& out, const Gara& gara) {
		out << "Oras gara: " << gara.oras << endl;
		out << "Numar linii: " << gara.nrLinii << endl;
		out << "Suprafata: " << gara.suprafata << endl;
		out << "Numar trenuri: " << gara.nrTrenuri << endl;
		out << "Trenuri: " << endl;
		for (int i = 0; i < gara.nrTrenuri; i++) {
			out << gara.trenuri[i] << endl << endl;
		}
		return out;
	}

	string getOras() {
		return this->oras;
	}

	void setOras(string oras) {
		this->oras = oras;
	}

	int getNrLinii() {
		return this->nrLinii;
	}

	void setNrLinii(int nrLinii) {
		this->nrLinii = nrLinii;
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}

	int getNrTrenuri() {
		return this->nrTrenuri;
	}

	Tren* getTrenuri() {
		return this->trenuri;
	}

	void setTrenuri(int nrTrenuri, Tren* trenuri) {
		delete[] this->trenuri;
		this->nrTrenuri = nrTrenuri;
		this->trenuri = new Tren[nrTrenuri];
		for (int i = 0; i < nrTrenuri; ++i) {
			this->trenuri[i] = trenuri[i];
		}
	}

	bool operator!() {
		return this->nrTrenuri > 0;
	}

	Gara& operator+=(float val) {
		this->suprafata += val;
		return *this;

	}

	Gara& operator-=(int nrLiniiGara) {
		if (this->nrLinii > nrLiniiGara) {
			this->nrLinii -= nrLiniiGara;
		}
		return *this;
	}

	void serializare(string garaFisier) {
		ofstream f(garaFisier, ios::out | ios::binary);
		int dimOras = this->oras.size();
		f.write((char*)&dimOras, sizeof(dimOras));
		f.write(this->oras.c_str(), dimOras + 1);
		f.write((char*)&this->nrLinii, sizeof(this->nrLinii));
		f.write((char*)&this->suprafata, sizeof(this->suprafata));
		f.write((char*)&this->nrTrenuri, sizeof(this->nrTrenuri));
	}
	void deserializare(string garaFisier) {
		//string oras;
		//int nrLinii;
		//float suprafata;
		//int nrTrenuri;
		ifstream f(garaFisier, ios::in | ios::binary);
		if (f.is_open())
		{
			int dimOras = 0;
			f.read((char*)&dimOras, sizeof(dimOras));
			char* aux = new char[dimOras + 1];
			f.read(aux, dimOras + 1);
			this->oras = aux;
			delete[]aux;
			f.read((char*)&this->nrLinii, sizeof(this->nrLinii));
			f.read((char*)&this->suprafata, sizeof(this->suprafata));
			f.read((char*)&this->nrTrenuri, sizeof(this->nrTrenuri));
			f.close();
		}
		else {
			cout << "Fisierul cautat nu exista!" << endl;
		}
	}

};

int main() {

	Tren t;
	t.afisare();
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

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
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


	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	cout << endl << endl;

	Tren t1("TransRo", 25);
	t1.afisare();

	cout << endl << endl;
	int nrLocuri[] = { 12,14 };
	Tren t2("CFR", 2, nrLocuri, 35);
	t2.afisare();

	cout << endl << endl;
	Tren t3 = t2;
	t3.afisare();
	cout << endl;
	cout << "Cat castiga la o cursa sold-out: " << valoareSoldOutTren(t3) << " lei" << endl;
	cout << endl << endl << endl << endl << endl << endl;


	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Insula insu;
	insu.afisare();
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
	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	Insula in1("Creta");
	in1.afisare();
	cout << endl << endl;

	Insula in2(1970, "Maldive", 451, 1);
	in2.afisare();
	cout << in2.getNumarInsule() << endl << endl;

	cout << endl << endl;

	Insula in3 = in2;
	in3.afisare();
	cout << endl << endl;

	cout << "Insula are in jur de: " << kmPatratiInHectare(in3) << " hectare de pamant" << endl;

	cout << endl << endl << endl << endl << endl << endl;

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
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
	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
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

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	int nrElemente = 2;
	Avion* vAvion = new Avion[nrElemente];
	Insula* vInsula = new Insula[nrElemente];
	Tren* vTren = new Tren[nrElemente];

	/*cout << endl << endl;

	for (int i = 0; i < nrElemente; i++) {
		cin >> vAvion[i];
	}

	cout << endl << endl;
	for (int i = 0; i < nrElemente; i++) {
		cout << vAvion[i]<<endl;
	}

	cout << endl << endl;

	for (int i = 0; i < nrElemente; i++) {
		cin >> vInsula[i];
	}

	cout << endl << endl;
	for (int i = 0; i < nrElemente; i++) {
		cout << vInsula[i] << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < nrElemente; i++) {
		cin >> vTren[i];
	}

	cout << endl << endl;
	for (int i = 0; i < nrElemente; i++) {
		cout << vTren[i] << endl;
	}*/

	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << endl << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	Gara g;
	cout << g.getOras() << endl;
	cout << g.getSuprafata() << endl;
	cout << g.getNrLinii() << endl;
	cout << g.getNrTrenuri() << endl;
	for (int i = 0; i < g.getNrTrenuri(); i++) {
		cout << g.getTrenuri() << endl;

	}

	Tren vectTren[] = { t4,t3,t2,t1 };
	Gara g1("Bucuresti", 12, 450.12, 4, vectTren);
	cout << g1 << endl;
	g1.setNrLinii(15);
	g1.setOras("Pitesti");
	g1.setSuprafata(1204);
	g1.setTrenuri(2, vectTren);
	cout << g1 << endl;

	Gara g2 = g;
	cout << g2 << endl;
	cout << g << endl;

	g = g1;
	cout << g << endl;
	cout << g1 << endl;

	Gara g3;

	cout << !g3 << endl;
	cout << !g1 << endl;

	cout << endl;
	cout << g1 << endl;

	g1 += 240;
	cout << g1 << endl;

	g1 -= 4;
	g1 -= 1;
	g1 -= 20;

	cout << g1 << endl;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "Scriere in fisier text" << endl;
	cout << t2 << endl;

	ofstream f("tren.txt", ios::out);
	f << t2;
	cout << "Obiectul a fost scris in fisier" << endl;
	f.close();
	cout << endl << endl;

	cout << "Citirea din fisier text" << endl;
	Tren hFisText;
	ifstream h("tren.txt", ios::in);
	if (h.is_open()) {
		h >> hFisText;
		cout << "Obiectul a fost citit din fisier" << endl;
	}
	else {
		cout << "Fisierul cautat nu exista" << endl;
	}
	cout << hFisText << endl;
	cout << endl << endl;

	cout << "Scriere in fisier text" << endl;
	cout << insu2 << endl;
	ofstream i("insula.txt", ios::out);
	i << insu2;
	cout << "Obiectul a fost scris in fisier" << endl;
	i.close();
	cout << endl << endl;

	cout << "Citirea din fisier text" << endl;
	Insula jFisText;
	ifstream j("insula.txt", ios::in);
	if (j.is_open()) {
		j >> jFisText;
		cout << "Obiectul a fost citit din fisier" << endl;
	}
	else {
		cout << "Fisierul cautat nu exista" << endl;
	}
	cout << jFisText << endl;
	cout << endl << endl;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	av1.serializare("avionFisBin.bin");
	cout << "Obiectul a fost scris in binar" << endl;
	cout << endl << endl;
	cout << "CITIREA DIN FISIER BINAR" << endl;
	Avion aBinar;
	aBinar.deserializare("avionFisBin.bin");
	aBinar.deserializare("avionFisBin.bin");
	cout << aBinar << endl;
	cout << endl << endl;

	insu2.serializare("fisInsula.bin");
	cout << "Obiectul a fost scris in binar" << endl;
	cout << endl << endl;
	cout << "CITIREA DIN FISIER BINAR" << endl;
	Insula insBinar;
	insBinar.deserializare("fisInsula.bin");
	cout << insBinar << endl;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	TrenDeMarfa tm;
	cout << tm<<endl;

	int locuriPerVagon[] = { 50, 60, 70 };
	TrenDeMarfa tm1("Marfa Port Const", 3, locuriPerVagon, 75.0, 200.0, true, "Paris");
	cout << tm1 << endl;

	Tren trUpCasting = tm1;
	cout << trUpCasting << endl << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	AvionDeLupta avl;
	cout << avl << endl;

	AvionDeLupta avl1("AL123", "Vulturul", "Camo", 10, 2022, 8, true);
	cout << avl1 << endl;

	AvionDeLupta avl2 = avl;

	cout << avl2 << endl;

	avl2 = avl1;

	cout << avl2 << endl;


	Avion aUp = avl1;

	cout << aUp << endl<<endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	RecunoastereObiect* pRo = new Tren(t1);
	RecunoastereObiect* pRo1 = new TrenDeMarfa(tm1);
	RecunoastereObiect* pRo2 = new Insula(insu1);

	cout << pRo->exemplarClasa() << endl;
	cout << pRo1->exemplarClasa() << endl;
	cout << pRo2->exemplarClasa() << endl;
	cout << endl << endl;

	AfisareObiect* aRo = new Tren(t1);
	AfisareObiect* aRo1 = new TrenDeMarfa(tm1);
	AfisareObiect* aRo2 = new Insula(insu2);
	
	aRo->afisare();
	cout << endl << endl;
	aRo1->afisare();
	cout << endl << endl;
	aRo2->afisare();
	cout << endl << endl;

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	vector<RecunoastereObiect*> vectObj;
	vectObj.push_back(&tm1);
	vectObj.push_back(&t2);
	vectObj.push_back(&insu3);
	vectObj.push_back(&insu2);
	vectObj.push_back(&tm1);
	vectObj.push_back(&t2);
	vectObj.push_back(&insu3);
	vectObj.push_back(&insu2);
	vectObj.push_back(&t2);
	vectObj.push_back(&t3);
	

	for (int i = 0; i < vectObj.size(); i++) {
		cout << vectObj[i]->exemplarClasa()<< endl;
	}
}
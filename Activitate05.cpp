//#include<iostream>
//#include<string>
//#include<fstream>
//
//using namespace std;
//
//class Banca {
//private:
//	string denumire = "Necunoscut";
//	char* locatie = nullptr;
//	int nrAngajati = 0;
//	bool areProfit = true;
//
//public:
//	Banca() {}
//
//	Banca(string denumire, const char* locatie,
//		int nrAngajati, bool areProfit) {
//		this->areProfit = areProfit;
//		this->nrAngajati = nrAngajati;
//		this->denumire = denumire;
//
//		this->locatie = new char[strlen(locatie) + 1];
//		strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
//	}
//
//	~Banca() {
//		if (this->locatie != nullptr) {
//			delete[] this->locatie;
//		}
//	}
//
//	Banca(const Banca& copie) {
//		this->areProfit = copie.areProfit;
//		this->denumire = copie.denumire;
//		this->nrAngajati = copie.nrAngajati;
//
//		if (copie.locatie != nullptr) {
//			this->locatie = new char[strlen(copie.locatie) + 1];
//			memcpy(this->locatie, copie.locatie, strlen(copie.locatie) + 1);
//		}
//		else {
//			this->locatie = nullptr;
//		}
//	}
//
//	friend void operator<<(ostream& out, Banca b) {
//		out << endl << "Nr angajati: " << b.nrAngajati;
//		out << endl << "Denumire: " << b.denumire;
//		out << endl << (b.areProfit ? "Are profit" : "Nu are profit");
//		out << endl << (b.locatie != nullptr ? "Locatie: " + string(b.locatie) : "Locatie default");
//	}
//
//	friend void operator<<(fstream& outFile, Banca b) {
//		outFile << b.nrAngajati << endl;
//		outFile << b.denumire << endl;
//		outFile << b.areProfit << endl;
//		outFile << b.locatie << endl;
//	}
//
//	friend void operator>>(ifstream& inFile, Banca& b) {
//		inFile >> b.nrAngajati;
//		inFile >> b.denumire;
//		inFile >> b.areProfit;
//
//		if (b.locatie != nullptr) {
//			delete[] b.locatie;
//			b.locatie = nullptr;
//		}
//
//		char buffer[30];
//		inFile >> buffer;
//
//		b.locatie = new char[strlen(buffer) + 1];
//		strcpy_s(b.locatie, strlen(buffer) + 1, buffer);
//	}
//
//};
//
//int main() {
//
//	Banca bcr("BCR", "PiataRomana", 15, true);
//
//	fstream fileStream("Banca.txt", ios::out);
//	fileStream << bcr;
//	fileStream.close();
//
//	Banca bcrCopie;
//	cout << bcrCopie;
//	ifstream inputFileStream("Banca.txt", ios::in);
//	inputFileStream >> bcrCopie;
//	inputFileStream.close();
//
//	cout << bcrCopie;
//
//	return 0;
//}
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class ExceptieCustom : public exception {
//
//public:
//	ExceptieCustom(const char* mesaj) : exception(mesaj) {
//	}
//
//};
//
////Mostenire, Abstractizare, Compunere
////Clasa parinte->clasa de baza
////Clasa copil->clasa derivata
////Zona protected clasa derivata, zona private clasa de baza
////1 - Incapsulare, 2 - Polimorfism, 3 - Mostenire, 4 - Abstractizare\
////is a->mostenire
////
////Clasa parinte->de baza
//
//class Laptop {
//private:
//	int memorie;
//	string marca;
//	float pret;
//	static const float PRET_MINIM;
//
//public:
//
//	Laptop() {
//
//		this->memorie = 0;
//		this->marca = "";
//		this->pret = 0;
//
//	}
//
//	Laptop(int memorie, string marca, float pret) {
//
//		this->memorie = memorie;
//		this->marca = marca;
//		if (pret < PRET_MINIM) {
//
//			throw ExceptieCustom("Pretul este prea mic!");
//
//		}
//		else {
//
//			this->pret = pret;
//
//		}
//		this->pret = pret;
//
//	}
//
//	virtual void afisare() {
//
//		cout << "Memorie: " << this->memorie << endl;
//		cout << "Marca: " << this->marca << endl;
//		cout << "Pret: " << this->pret << endl;
//		cout << endl;
//
//
//	}
//
//	/*Metoda virtuala pura*/
//		virtual string getPlacaVideo() = 0;
//
//};
//
//class LaptopGaming : public Laptop {
//
//private:
//	string placaVideo;
//
//public:
//	LaptopGaming() : Laptop() {
//
//		this->placaVideo = "";
//
//	}
//
//	LaptopGaming(int memorie, string marca, float pret, string placaVideo) : Laptop(memorie, marca, pret) {
//
//		this->placaVideo = placaVideo;
//
//	}
//
//	void afisare() {
//
//		this->Laptop::afisare();
//		cout << "Placa video: " << this->placaVideo << endl;
//
//	}
//
//	string getPlacaVideo() {
//
//		return this->placaVideo;
//
//	}
//
//};
//
//const float Laptop::PRET_MINIM = 1;
//
//int main() {
//
//	/*Vector de pointeri la obiecte de tip Laptop*/
//		Laptop* vectorLaptopuri[3];
//	vectorLaptopuri[0] = new LaptopGaming(512, "Lenovo", 7000, "NVIDIA");
//	vectorLaptopuri[1] = new LaptopGaming(250, "ASUS", 3500, "INTEL");
//	vectorLaptopuri[2] = new LaptopGaming(1000, "SAMSUNG", 5000, "NVIDIA");
//
//	for (int i = 0; i < 3; i++) {
//
//		vectorLaptopuri[i]->afisare();
//		delete vectorLaptopuri[i];
//
//	}
//}
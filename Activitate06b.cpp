////Compunere
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//class Autocar {
//
//private:
//	float nrKm;
//
//public:
//	Autocar() {
//
//		this->nrKm = 0;
//
//	}
//
//	Autocar(float nrKm) {
//
//		this->nrKm = nrKm;
//
//	}
//
//	float getNrKm() {
//
//		return this->nrKm;
//
//	}
//};
//
//class Autobaza {
//
//private:
//	//1:1
//	//Autocar autocar;
//
//	//1:m
//	Autocar* vector;
//
//	int nrAutocare;
//	string denumire;
//
//public:
//	Autobaza(string denumire, int nrAutocare, float* vectorNrKm) {
//
//		this->denumire = denumire;
//		this->nrAutocare = nrAutocare;
//		this->vector = new Autocar[nrAutocare];
//		for (int i = 0; i < nrAutocare; i++) {
//
//			this->vector[i] = Autocar(vectorNrKm[i]);
//
//		}
//
//	}
//
//	Autobaza(const Autobaza& a) {
//
//		this->denumire = a.denumire;
//		this->nrAutocare = a.nrAutocare;
//		if (a.vector != nullptr) {
//
//			this->vector = new Autocar[a.nrAutocare];
//			for (int i = 0; i < a.nrAutocare; i++) {
//
//				this->vector[i] = a.vector[i];
//
//			}
//
//		}
//		else {
//
//			this->vector = nullptr;
//
//		}
//
//
//	}
//
//	Autocar& operator[](int i) {
//
//		if (i >= 0 && i < this->nrAutocare) {
//
//			return this->vector[i];
//
//		}
//		else {
//
//			throw "Index-ul este in afara inrervalului!";
//
//		}
//
//	}
//
//};
//
//using namespace std;
//
//int main() {
//
//	float* vectorNrkM = new float[3] {150000, 750000, 320000};
//	Autobaza a1("Pitesti", 3, vectorNrkM);
//	cout << "Nr de km pentru autocarul 3 este de " << a1[2].getNrKm() << " " << " km" << endl;
//
//	Autobaza a2 = a1;
//	cout << "Nr de km pentru autocarul 2 este de " << a2[1].getNrKm() << " " << " km" << endl;
//
//}
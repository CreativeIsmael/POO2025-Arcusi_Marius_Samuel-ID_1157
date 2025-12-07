//#include <iostream>
//#include <string>
//#include <cstring>
//#include <fstream>
//
//using namespace std;
//
//class Banca {
//
//private:
//    string denumire = "Necunoscut";
//    char* locatie = nullptr;
//    int nrAngajati = 0;
//    bool areProfit = true;
//
//public:
//
//    Banca() {}
//
//    Banca(string denumire, const char* locatie, int nrAngajati, bool areProfit) {
//        this->denumire = denumire;
//        this->nrAngajati = nrAngajati;
//        this->areProfit = areProfit;
//
//        this->locatie = new char[strlen(locatie) + 1];
//        strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
//    }
//
//    ~Banca() {
//        delete[] this->locatie;
//    }
//
//    // --- operator << pentru consola ---
//    friend ostream& operator<<(ostream& out, const Banca& b) {
//        out << "Numar angajati: " << b.nrAngajati << endl;
//        out << "Denumire: " << b.denumire << endl;
//        out << (b.areProfit ? "Are profit!" : "Nu are profit!") << endl;
//        out << (b.locatie ? b.locatie : "Fara locatie") << endl;
//
//        return out;
//    }
//
//    // --- operator << pentru fișier ---
//    friend fstream& operator<<(fstream& outfile, const Banca& b) {
//        outfile << b.nrAngajati << endl;
//        outfile << b.denumire << endl;
//        outfile << b.areProfit << endl;
//        outfile << (b.locatie ? b.locatie : "Fara locatie") << endl;
//
//        return outfile;
//    }
//
//};
//
//int main() {
//
//    Banca bcr("BCR", "Piata Romana", 15, true);
//
//    // Afișare în consolă
//    cout << bcr;
//
//    // Scriere în fișier
//    fstream filestream("Banca.txt", ios::out);
//    if (filestream.is_open()) {
//        filestream << bcr;
//        filestream.close();
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int idArc = 1;
int idSageata = 0;
int idManusi = 0;

class Arc {
public:  
    
    Arc() : id(idArc++), model(nullptr), culoare(nullptr), pret(0.0f) {}
    int getId() const { return id; }

    void descriere() {
        cout << "Aceasta este descrierea unui arc!" << endl;
    }

private:
    const int id;
    char* model;
    char* culoare;
    float pret;
};

class Sageata {
public:
    Sageata() : id(++idSageata), model(nullptr), culoare(nullptr), material("lemn"), pret(0.0f) {}

    void descriere() {
        cout << "Aceasta este descrierea unei sageti!" << endl;
    }

private:
    const int id;
    char* model;
    char* culoare;
    string material;
    float pret;
};

class Manusi {
public:
    Manusi() : id(++idManusi), model(nullptr), culoare(nullptr), pret(0.0f) {}

    void descriere() {
        cout << "Aceasta este descrierea unei perechi de manusi pentru arc!" << endl;
    }

private:
    const int id;
    char* model;
    char* culoare;
    float pret;
};



int main() {
    cout << "Hello, world!" << endl;
    Arc* arc1 = new Arc();
    arc1->descriere();
    cout << "ID-ul arcului este: " << arc1->getId() << endl;

    delete arc1; 
    return 0;
}

#include <iostream>
#include <string>
using namespace std;


class Arc {
public:  

    //Constructor

    Arc() : id(++idArc), model(nullptr), culoare(nullptr), pret(0.0f) {}
    

    //Getters

    int getId() const { return id; }

    char* getModel() {
        return model;
    }

    char* getCuloare() {

        return culoare;
    }

    float getPret() {
        return pret;
    }

    //Setters

    void setModel(const char* model) {
        if (strlen(model) > 0) {
            if (this->model != nullptr) {
                delete[]this->model;
            }
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }

    }

    void setCuloare(const char* culoare) {
        if (strlen(culoare) > 0) {
            if (this->culoare != nullptr) {
                delete[]this->culoare;
            }
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        }

    }

    void setPret(float pret) {
        if (pret > 0) {
            (*this).pret = pret;
        }
    }

    //Metode Publice

    void descriere() {
        cout << "Descriere Arc:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Pret: " << pret << endl << endl;
    }

private:

     static int idArc;

    const int id;
    char* model;
    char* culoare;
    float pret;
};

class Sageata {
public:

    //Constructor

    Sageata() : id(++idSageata), model(nullptr), culoare(nullptr), material("necunoscut"), pret(0.0f) {}

    //Getters

    int getId() {
        return id;
    }

    char* getModel() {
        return model;
    }

    char* getCuloare() {

        return culoare;
    }

    string getMaterial() {
        return material;
    }

    float getPret() {
        return pret;
    }
    
    //Setters

    void setModel(const char* model) {
        if (strlen(model) > 0) {
            if (this->model != nullptr) {
                delete[]this->model;
            }
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }

    }

    void setCuloare(const char* culoare) {
        if (strlen(culoare) > 0) {
            if (this->culoare != nullptr) {
                delete[]this->culoare;
            }
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        }

    }

    void setMaterial(string material) {
        if (material.length() > 0) {
            this->material = material;
        }
    }

    void setPret(float pret) {
        if (pret > 0) {
            (*this).pret = pret;
        }
    }

    //Metode publice

    void descriere() {
        cout << "Descriere Sageata:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Material: " << material << endl;
        cout << "Pret: " << pret << endl << endl;
    }

private:

   static int idSageata;

    const int id;
    char* model;
    char* culoare;
    string material;
    float pret;
};

class Manusi {
public:

    //Constructor

    Manusi() : id(++idManusi), model(nullptr), culoare(nullptr), pret(0.0f) {}

    //Getters

    int getId() {
        return id;
    }

    char* getModel() {
        return model;
    }

    char* getCuloare() {

        return culoare;
    }

    float getPret() {
        return pret;
    }

    //Setters

    void setModel(const char* model) {
        if (strlen(model) > 0) {
            if (this->model != nullptr) {
                delete[]this->model;
            }
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }

    }

    void setCuloare(const char* culoare) {
        if (strlen(culoare) > 0) {
            if (this->culoare != nullptr) {
                delete[]this->culoare;
            }
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        }

    }

    void setPret(float pret) {
        if (pret > 0) {
            (*this).pret = pret;
        }
    }

    //Metode publice

    void descriere() {
        cout << "Descriere Manusi:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Pret: " << pret << endl << endl;
    }

private:

   static int idManusi;

    const int id;
    char* model;
    char* culoare;
    float pret;
};

//Initializare id clase fara inline(No cpp17..)

int Arc::idArc = 0;
int Sageata::idSageata = 0;
int Manusi::idManusi = 0;


int main() {
    cout << "Hello, world!" << endl;
    Arc* arc1 = new Arc();
    arc1->descriere();
    cout << "ID-ul arcului este: " << arc1->getId() << endl;

    Arc* arc2 = new Arc();
    arc2->descriere();
    cout << "ID-ul arcului este: " << arc2->getId() << endl;

    arc2->setCuloare((char*)"negru");

    arc2->descriere();

    Sageata* sageata1 = new Sageata();
    sageata1->descriere();

    Manusi* manusa1 = new Manusi();
    manusa1->descriere();
    manusa1->setCuloare((char*)"alb");
    manusa1->descriere();

    cout << "--------------------------------- "<< endl;

    int idManusa1=  manusa1->getId();
    char* culoareManusa1 = manusa1->getCuloare();
    cout << idManusa1 << " si " << culoareManusa1 << endl;

    //Dezaloque memoir :)
    delete arc1; 
    delete arc2;
    delete sageata1;
    delete manusa1;

    return 0;
}

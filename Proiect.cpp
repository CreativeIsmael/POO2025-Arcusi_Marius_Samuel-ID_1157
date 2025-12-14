#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


class Arc {
public:  

    /*Constructor fara parametrii*/

    Arc() : id(++idArc), model(nullptr), culoare(nullptr), pret(0.0f), marime(nullptr), nrMarimi(0) {}
    
   /* Constructor cu parametrii*/

    Arc(char* model, char* culoare, float pret, int nrMarimi, int* marime)  : id(++idArc) {

        if (model != nullptr) {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);

        }
        else {
            this->model = nullptr;
        }
        
        if (culoare != nullptr) {
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        }
        else {
            this->culoare = nullptr;
        }

        this->pret = (pret > 0) ? pret : 0;
      
        this->nrMarimi = (nrMarimi > 0) ? nrMarimi : 0;

        if (marime != nullptr && nrMarimi != 0) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++)
                this->marime[i] = marime[i];
        }
        else {
            this->marime = nullptr;
            this->nrMarimi = 0;
        }
        
        
        
    }

    /*Constructor de copiere */

    Arc(const Arc& a) : id(++idArc) {
        if (a.model) {
            this->model = new char[strlen(a.model) + 1];
            strcpy_s(this->model, strlen(a.model) + 1, a.model);
        }
        else { this->model = nullptr; }

        if (a.culoare) {
            this->culoare = new char[strlen(a.culoare) + 1];
            strcpy_s(this->culoare, strlen(a.culoare) + 1, a.culoare);

        }
        else { this->culoare = nullptr; }
        this->pret = a.pret;
        this->nrMarimi = a.nrMarimi;
       
        if (a.marime) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++) {
                this ->marime[i] = a.marime[i];
            }
        }
        else { this->marime = nullptr; }
    }

   /* Destructor*/
    
    ~Arc() {

        if (model) delete[] model;
        if (culoare) delete[] culoare;
        if (marime) delete[] marime;

    }

  /*  OPERATORES

   Operator=*/

    Arc& operator=(const Arc& a) {

        if (this == &a)
            return *this; // Verifica sa nu fi acelasi obiect 

        if (this->model != nullptr) {
            delete[] this->model;
        }
        if (this->culoare) {
            delete[] this->culoare;
        }
        if (this->marime) {
            delete[] this->marime;
        }
      
        if (a.model) {
            this->model = new char[strlen(a.model) + 1];
            strcpy_s(this->model, strlen(a.model) + 1, a.model);
        }
        else this->model = nullptr;
        if (a.culoare) {
            this->culoare = new char[strlen(a.culoare) + 1];
            strcpy_s(this->culoare, strlen(a.culoare) + 1, a.culoare);
        }
        else this->culoare = nullptr;
        this->pret = a.pret;
        this->nrMarimi = a.nrMarimi;
        if (a.marime) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++) {
                this->marime[i] = a.marime[i];
            }
        }
        else this->marime = nullptr;
        return *this;
    }

    /*Operator<<*/

    friend ostream& operator<<(ostream& output, const Arc& a);

    /*Scriere fisier*/

    friend void operator<<(fstream& outFile, Arc a) {
        outFile << a.model << endl;
        outFile << a.culoare << endl;
        outFile << a.pret << endl;
        outFile << a.nrMarimi << endl;
        for (int i = 0; i < a.nrMarimi; i++) {
            outFile << a.marime[i] << " ";
       }
        outFile << endl;
        
    }

   

    /*Operator>>*/

    friend istream& operator>>(istream& input, Arc& a);

    /*Citire fisier*/

    friend void operator>>(ifstream& inFile, Arc& a) {


        char buffer[30];
        if (a.model) {
            delete[] a.model;
            a.model = nullptr;
        }

        inFile >> buffer;
        a.model = new char[strlen(buffer) + 1];
        strcpy_s(a.model, strlen(buffer) + 1, buffer);
        inFile >> buffer;

        if (a.culoare) {
            delete[] a.culoare;
            a.culoare = nullptr;
        }

        a.culoare = new char[strlen(buffer) + 1];
        strcpy_s(a.culoare, strlen(buffer) + 1, buffer);

        inFile >> a.pret;
        inFile >> a.nrMarimi;

        if (a.marime) {
            delete[] a.marime;
            a.marime = nullptr;
        }


        a.marime = new int[a.nrMarimi];
        for (int i = 0; i < a.nrMarimi; i++) {
            inFile >> a.marime[i];
        }

    }

    /*Getters*/

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

    int* getMarime() {
        return marime;
    }

    int getNrMarimi() {
        return nrMarimi;

    }


   /* Setters*/

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

    void setMarime() {
        cout << "Introdu numarul de marimi: " << endl;
        cin >> nrMarimi;

        if (nrMarimi > 0) {
            if (marime != nullptr) {
                delete[] marime;
            }

            marime = new int[nrMarimi];
            cout << "Introdu marimile (" << nrMarimi << " valori): " << endl;
            for (int i = 0; i < nrMarimi; i++) {
                cin >> marime[i];
            }
        }
    }

   

   /* Metode Publice*/

    void descriere() {
        cout << "DESCRIERE ARC:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Marimi: ";
        if (marime) {
            for (int i = 0; i < nrMarimi; i++) cout << marime[i] << " ";
        }
        else {
            cout << "Nicio marime!";
        }
        cout << endl;
        cout << "Pret: " << pret << endl << endl;
    }

    static void arcCompare(const Arc& a1, const Arc& a2) {

    
        if (a1.pret > a2.pret) {
            cout << "Arcul " << (a1.model ? a1.model : "Arc 1") << " este mai scump decat arcul " << (a2.model ? a2.model : "Arc 2") << endl;
        }else if(a1.pret == a2.pret) {
            cout << "Arcurile sunt de aceiasi valoare." << endl;
        }
        else {
            cout << "Arcul " << (a2.model ? a2.model : "Arc 2") << " este mai valoros decat arcul " << (a1.model ? a1.model : "Arc 1") << endl;
        }
    }


private:

     static int idArc;

    const int id;
    char* model;
    char* culoare;
    float pret;
    int* marime;
    int nrMarimi;
};

class Sageata {
public:

    /*Constructor fara parametrii*/

    Sageata() : id(++idSageata), model(nullptr), culoare(nullptr), material("necunoscut"), pret(0.0f), marime(nullptr), nrMarimi(0) {}

    /*Constructor cu parametrii*/

    Sageata(char* model, char* culoare, string material, float pret, int nrMarimi, int* marime) : id(++idSageata) {

        if (model) {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }
        else { this->model = nullptr; }

        if (culoare) {
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        }
        else { this->culoare = nullptr; }

        if (material.length() > 0) {
            this->material = material;
        }
        else { this->material = "necunoscut"; } //Mai lasam ternaru sa se odihneasca :)

        this->pret = (pret > 0) ? pret : 0;

        this->nrMarimi = (nrMarimi > 0) ? nrMarimi : 0;

        if (marime && nrMarimi > 0) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++) {
                this->marime[i] = marime[i];
            }
        }
        else {
            this->marime = nullptr;
        }
    }

    //Constructor de copiere

    Sageata(const Sageata& s) : id(++idSageata) {

        if (s.model) {
            this->model = new char[strlen(s.model) + 1];
            strcpy_s(this->model, strlen(s.model) + 1, s.model);
        }
        else { this->model = nullptr; }

        if (s.culoare) {
            this-> culoare = new char[strlen(s.culoare) + 1];
            strcpy_s(this->culoare, strlen(s.culoare) + 1, s.culoare);
        }
        else { this->culoare = nullptr; }

        this->material = s.material;
        this->pret = s.pret;
        this->nrMarimi = s.nrMarimi ? s.nrMarimi : 0; 

        if (s.marime && nrMarimi > 0) {
            this->marime = new int[s.nrMarimi];
            for (int i = 0; i < s.nrMarimi; i++) {
                this->marime[i] = s.marime[i];
            }

        }
        else { this->marime = nullptr; }

    }

   
/*
    Destructor*/ 

    ~Sageata() {
        if (model) delete[] model;
        if (culoare) delete[] culoare;
        if (marime) delete[] marime;
    }

   /* Operatori

    Operator=*/

    Sageata& operator=(const Sageata& s) {

        if (this == &s) {
            return *this;
        }

        if (this->model) {
            delete[] this->model;
        }
        if (this->culoare) {
            delete[] this->culoare;
        }
        this->material = s.material;
        this->pret = s.pret;
        this->nrMarimi = s.nrMarimi;

        if (s.model) {
            this->model = new char[strlen(s.model) + 1];
            strcpy_s(this->model, strlen(s.model) + 1, s.model);
        }
        else this->model = nullptr;

        if (s.culoare) {
            this->culoare = new char[strlen(s.culoare) + 1];
            strcpy_s(this->culoare, strlen(s.culoare) + 1, s.culoare);
        }
        else this->culoare = nullptr;
        if (this->marime) {
            delete[] this->marime;
        }
        if (s.marime) {
            
            this->marime = new int[s.nrMarimi];
            for (int i = 0; i < s.nrMarimi; i++) {
                this->marime[i] = s.marime[i];
            }

        }
        else this->marime = nullptr;

        return *this;
    }

     /*Operator<<*/

   friend ostream& operator<<(ostream& output,const Sageata& s);

   /*Scriere fisier*/

   friend void operator<<(fstream& outFile, Sageata& s) {
       outFile << s.model << endl;
       outFile << s.culoare << endl;
       outFile << s.material << endl;
       outFile << s.pret << endl;
       outFile << s.nrMarimi << endl;
       for (int i = 0; i < s.nrMarimi; i++) {
           outFile << s.marime[i] << " ";
       }
       outFile << endl;
   }

   /*Operator>>*/

   friend istream& operator>>(istream& input, Sageata& s);

   /*Citire fisier*/

   friend void operator>>(ifstream& inputFile, Sageata& s) {

       char buffer[30];

       if (s.model) {
           delete[] s.model;
           s.model = nullptr;
       }
       inputFile >> buffer;
       s.model = new char[strlen(buffer) + 1];
       strcpy_s(s.model, strlen(buffer) + 1, buffer);


       if (s.culoare) {
           delete[] s.culoare;
           s.culoare = nullptr;
       }
       inputFile >> buffer;
       s.culoare = new char[strlen(buffer) + 1];
       strcpy_s(s.culoare, strlen(buffer) + 1, buffer);

       inputFile >> s.material;
       inputFile >> s.pret;
       inputFile >> s.nrMarimi;

       if (s.marime) {
           delete[] s.marime;
           s.marime = nullptr;
       }
       s.marime = new int[s.nrMarimi];
       for (int i = 0; i < s.nrMarimi; i++) {
           inputFile >> s.marime[i];
       }

   }

   


    /*Getters*/

    int getId() const {
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
    
    int* getMarime() {
        return marime;
    }

    int getNrMarimi() {
        return nrMarimi;

    }

    /*Setters*/

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

    void setMarime() {
        cout << "Introdu numarul de marimi: " << endl;
        cin >> nrMarimi;

        if (nrMarimi > 0) {
            if (marime != nullptr) {
                delete[] marime;
            }

            marime = new int[nrMarimi];
            cout << "Introdu marimile (" << nrMarimi << " valori): " << endl;
            for (int i = 0; i < nrMarimi; i++) {
                cin >> marime[i];
            }
        }
    }

   

    /*Metode publice*/

    void descriere() {
        cout << "DESCRIERE SAGEATA:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Material: " << material << endl;
        cout << "Marimi: ";
        if (marime) {
            for (int i = 0; i < nrMarimi; i++) cout << marime[i] << " ";
        }
        else {
            cout << "Nicio marime!";
        }
        cout << endl;
        cout << "Pret: " << pret << endl << endl;
    }

    static void sageataCompare(const Sageata& s1, const Sageata& s2) {


        if (s1.pret > s2.pret) {
            cout << "Sageata " << (s1.model ? s1.model : "Sageata 1") << " este mai scumpa decat sageata " << (s2.model ? s2.model : "Sageata 2") << endl;
        }
        else if (s1.pret == s2.pret) {
            cout << "Sagetile sunt de aceiasi valoare." << endl;
        }
        else {
            cout << "Sageata " << (s2.model ? s2.model : "Sageata 2") << " este mai valoroasa decat sageata " << (s1.model ? s1.model : "Sageata 1") << endl;
        }
    }

private:

   static int idSageata;

    const int id;
    char* model;
    char* culoare;
    string material;
    float pret;
    int* marime;
    int nrMarimi;
};

class Manusi {
public:

    /*Constructor fara parametrii*/

    Manusi() : id(++idManusi), model(nullptr), culoare(nullptr), pret(0.0f), marime(nullptr), nrMarimi(0) {}

    /*Constructor cu parametrii*/

    Manusi(char* model, char* culoare, float pret, int nrMarimi, int* marime) : id(++idManusi) {

        if (model) {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }
        else {
            this->model = nullptr;
        }

        if (culoare) {
            this->culoare = new char[strlen(culoare) + 1];
            strcpy_s(this ->culoare, strlen(culoare) + 1, culoare);
        }
        else {
            this->culoare = nullptr;
        }

        
        this->pret = (pret > 0) ? pret : 0;
        
        this->nrMarimi = (nrMarimi > 0) ? nrMarimi : 0;

        if (marime && nrMarimi > 0) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++) {
                this->marime[i] = marime[i];
            }
        }
        else {
            this->marime = nullptr;
        }

    }

    /*Constructor de copiere*/

    Manusi(const Manusi& m) : id(++idManusi) {
        if (m.model) {
            this->model = new char[strlen(m.model) + 1];
            strcpy_s(this->model, strlen(m.model) + 1, m.model);

        }
        else { this->model = nullptr; }

        if (m.culoare) {
            this->culoare = new char[strlen(m.culoare) + 1];
            strcpy_s(this->culoare, strlen(m.culoare) + 1, m.culoare);
        }
        else { this->culoare = nullptr; }

        this->pret = m.pret;
        this->nrMarimi = m.nrMarimi;

        if (m.marime) {
            this->marime = new int[nrMarimi];
            for (int i = 0; i < nrMarimi; i++) {
                this->marime[i] = m.marime[i];
            }

        }
        else { this->marime = nullptr; }
    }

    /*Destructor*/

    ~Manusi() {

        if (model) delete[] model;
        if (culoare) delete[] culoare;
        if (marime) delete[] marime;
    }
    /*Operatori

    Operator=*/

    Manusi& operator=(const Manusi& m) {
        if (this->model) {
            delete[] this->model;
        }
        if (this->culoare) {
            delete[] this->culoare;
        }
        this->pret = m.pret;
        this->nrMarimi = m.nrMarimi;

        if (m.model) {
            this->model = new char[strlen(m.model) + 1];
            strcpy_s(this->model, strlen(m.model) + 1, m.model);
        }
        else this->model = nullptr;

        if (m.culoare) {
            this->culoare = new char[strlen(m.culoare) + 1];
            strcpy_s(this->culoare, strlen(m.culoare) + 1, m.culoare);
        }
        else this->culoare = nullptr;

        if (this->marime) {
            delete[] this->marime;
        }
        if (m.marime) {
            this->marime = new int[m.nrMarimi];
            for (int i = 0; i < m.nrMarimi; i++) {
                this->marime[i] = m.marime[i];
            } 
        } else this->marime = nullptr;

        return *this;
    }
    
       

    /*Operator<<*/

    friend ostream& operator<<(ostream& output, const Manusi& m);

    /*Scriere fisier*/

    friend void operator<<(fstream& out, Manusi& m) {
        out << m.model << endl;
        out << m.culoare << endl;
        out << m.pret << endl;
        out << m.nrMarimi << endl;
        for (int i = 0; i < m.nrMarimi; i++) {
            out << m.marime[i] << " ";
       }
    }

    /*Operator>>*/

    friend istream& operator>>(istream& input, Manusi& m);

    /*Citire fisier*/ 

    friend void operator>>(ifstream& input, Manusi& m) {

        char buffer[35];

        if (m.model) {
            delete[] m.model;
            m.model = nullptr;
        }
        input >> buffer;
        m.model = new char[strlen(buffer) + 1];
        strcpy_s(m.model, strlen(buffer) + 1, buffer);

        if (m.culoare) {
            delete[] m.culoare;
            m.culoare = nullptr;
        }
        input >> buffer;
        m.culoare = new char[strlen(buffer) + 1];
        strcpy_s(m.culoare, strlen(buffer) + 1, buffer);

        input >> m.pret;
        input >> m.nrMarimi;

        if (m.marime) {
            delete[] m.marime;
            m.marime = nullptr;
        }
        m.marime = new int[m.nrMarimi];
        for (int i = 0; i < m.nrMarimi; i++) {
            input >> m.marime[i];
        }
        
    }

    /*Getters*/

    int getId() const {
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

    int* getMarime() {
        return marime;
    }

    int getNrMarimi() {
        return nrMarimi;

    }
    /*Setters*/

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

    void setMarime() {
        cout << "Introdu numarul de marimi: " <<endl;
        cin >> nrMarimi;

        if (nrMarimi > 0) {
            if (marime != nullptr) {

                delete[] marime;
            }

            marime = new int[nrMarimi];
            cout << "Introdu marimile (" << nrMarimi << " valori): " <<endl;
            for (int i = 0; i < nrMarimi; i++) {
                cin >> marime[i];
            }
            
        }
    }


    /*Metode publice*/

    void descriere() {
        cout << "DESCRIERE MANUSA:" << endl;
        cout << "ID: " << id << endl;
        cout << "Model: " << (model ? model : "necunoscut") << endl;
        cout << "Culoare: " << (culoare ? culoare : "necunoscuta") << endl;
        cout << "Marimi: ";
        if (marime) {
            for (int i = 0; i < nrMarimi; i++) cout << marime[i] << " ";
        }
        else {
            cout << "Nicio marime!(Se pare ca asa se scrie corect,gramatical)";
        }
        cout << endl;
        cout << "Pret: " << pret << endl << endl;
        
    }

    static void manusiCompare(const Manusi& m1, const Manusi& m2) {


        if (m1.pret > m2.pret) {
            cout << "Manusa " << (m1.model ? m1.model : "Manusa 1") << " este mai scumpa decat manusa " << (m2.model ? m2.model : "Manusa 2") << endl;
        }
        else if (m1.pret == m2.pret) {
            cout << "Manusile sunt de aceiasi valoare." << endl;
        }
        else {
            cout << "Manusa " << (m2.model ? m2.model : "Manusa 2") << " este mai valoroasa decat manusa " << (m1.model ? m1.model : "Manusa 1") << endl;
        }
    }
    

private:

   static int idManusi;

    const int id;
    char* model;
    char* culoare;
    float pret;
    int* marime;
    int nrMarimi;
};

//Initializare id clase fara inline(No cpp17..)

int Arc::idArc = 0;
int Sageata::idSageata = 0;
int Manusi::idManusi = 0;

//Functii globale
// 
// Functie afisare linii :)

void visualSeparator() {
    cout << "----------------------------------------------------------" << endl;
}

//<<
ostream& operator<<(ostream& output, const Arc& a) {
    output << "Acesta este un arc model:" << (a.model ? a.model : "Necunoscut") << " de culoare " << (a.culoare ? a.culoare : "Necunoscuta") << " si pret " << a.pret << " cu " << a.nrMarimi << " marimi: " << endl;
    for (int i = 0; i < a.nrMarimi; i++) {
        output << a.marime[i] << " ";
    }
    output << endl;
    return output;
}

ostream& operator<<(ostream& output, const Sageata& s) {

    output << "Aceasta este o sageata model:" << (s.model ? s.model : "Necunoscut") << " de culoare " << (s.culoare ? s.culoare : "Necunoscuta") << " material " << s.material << " si pret " << s.pret << " cu " << s.nrMarimi << " marimi: " << endl;
    for (int i = 0; i < s.nrMarimi; i++) {
        output << s.marime[i] << " ";
        }
    output << endl;
    return output;

}

ostream& operator<<(ostream& output, const Manusi& m) {

    output << "Aceasta este o manusa model:" << (m.model ? m.model : "Necunoscut") << " culoare " << (m.culoare ? m.culoare : "Necunoscuta") << " si pret " << m.pret << " cu " << m.nrMarimi << " marimi disponibile: ";
    for (int i = 0; i < m.nrMarimi; i++) {
        output << m.marime[i] << " ";
    }
    output << endl;
    return output;

}

//>>

istream& operator>>(istream& input, Manusi& m) {

    char buffer[15];

    cout << " Model: ";
    input >> buffer;
    m.setModel(buffer);

    cout << " Culoare: ";
    input >> buffer;
    m.setCuloare(buffer);

    float pret;
    cout << " Pret: ";
    input >> pret;
    m.setPret(pret);

   
    m.setMarime();

    return input;
}

istream& operator>>(istream& input, Sageata& s) {
    char buffer[20];

    cout << "Model: ";
    input >> buffer;
    s.setModel(buffer);

    cout << "Culoare: ";
    input >> buffer;
    s.setCuloare(buffer);

    string material;
    cout << "Material: ";
    input >> material;
    s.setMaterial(material);

    float pret;
    cout << "Pret: ";
    input >> pret;
    s.setPret(pret);

    s.setMarime();

    return input;

}

istream& operator>>(istream& input, Arc& a) {

    char buffer[18];

    cout << "Model: ";
    input >> buffer;
    a.setModel(buffer);

    cout << "Culoare: ";
    input >> buffer;
    a.setCuloare(buffer);

    float pret;
    cout << "Pret: ";
    input >> pret;
    a.setPret(pret);

    a.setMarime();

    return input;

}

int main() {
    

    cout << "Hello, world!" << endl;
    int* v = new int[3] {10, 20, 30}; // V is for vectoras

    /*Testing ARC*/

    cout << "-----------------------------------TESTARE CLASA ARC!!----------------------------" << endl;

    Arc* arc1 = new Arc();
    arc1->descriere();
    cout << "ID-ul arcului este: " << arc1->getId() << endl;

    Arc* arc2 = new Arc();
    arc2->descriere();
    cout << "ID-ul arcului este: " << arc2->getId() << endl;

    arc2->setCuloare((char*)"negru");
    Arc* arc3 = new Arc((char*)"Adidas", (char*)"Roz", 1.2f, 3, v);
    arc2->descriere();
    arc3->descriere();
    cout << *arc2;
    Arc* arc4 = new Arc();
    *arc4 = *arc3;
    cout << *arc4;

    /*cin >> *arc4;
    cout << *arc4;*/
    cout << endl << endl;
    fstream myFileStream("Arce.txt", ios::out);
    myFileStream << *arc4;
    myFileStream.close();

    ifstream myInputFileStream("Arce.txt", ios::in);
    myInputFileStream >> *arc2;
    myInputFileStream.close();

    cout << *arc2;
    visualSeparator();
    Arc::arcCompare(*arc1, *arc3);
    /*Testing SAGEATA*/

    cout << "----------------------------------TESTARE CLASA SAGEATA!!--------------------------" << endl;

    Sageata* sageata1 = new Sageata();
    sageata1->descriere();
    cout << *sageata1;
    Sageata* sageata2 = new Sageata((char*)"BMW", (char*)"BLUE", "Carbon", 5.3f, 3, v);
    *sageata1 = *sageata2;
    cout << *sageata2 << endl;

    /*cin >> *sageata2;
    cout << *sageata2;*/

    fstream outputFile("Sagete.txt", ios::out);
    outputFile << *sageata2;
    outputFile.close();
    visualSeparator();
    Sageata::sageataCompare(*sageata1, *sageata2);
    /*Testing MANUSI*/

    cout << "----------------------------------TESTARE CLASA MANUSI!!---------------------------" << endl;

    Manusi* manusa1 = new Manusi();
    Manusi* manusa2 = new Manusi((char*)"Porto", (char*)"Gri", 2.3f, 3, v);
    manusa1->descriere();
    manusa1->setCuloare((char*)"alb");
    /*manusa1->setMarime();*/
   /*int numarMarimi =  manusa1->getNrMarimi();
   cout << numarMarimi << endl;
   int * marimi = manusa1->getMarime();
   cout << marimi[0] << endl;*/
    manusa1->descriere();
    *manusa1 = *manusa2;

    fstream exput("Manusi.txt", ios::out);
    exput << *manusa2;
    exput.close();
    Manusi* manusa3 = new Manusi();

    ifstream in("Manusi.txt", ios::in);
    in >> *manusa3;
    manusa3->descriere();
    visualSeparator();
    Manusi::manusiCompare(*manusa1, *manusa2);

    cout << "--------------------------------- "<< endl;

   /* int idManusa1=  manusa1->getId();
    char* culoareManusa1 = manusa1->getCuloare();
    cout << idManusa1 << " si " << culoareManusa1 << endl;

    cout << *manusa1 << endl;*/

    /*cin >> *manusa1;
    cout << *manusa1 << endl;*/


    

    /*Dezaloque memoir :)*/

    delete arc1; 
    delete arc2;
    delete arc3;
    delete arc4;
    delete sageata1;
    delete sageata2;
    delete manusa1;
    delete manusa2;
    delete manusa3;
    delete[] v;
    return 0;
}

//#include<iostream>
//#include <string>
//using namespace std;
//
//int suma(int a, int b) {
//    return a + b;
//}
//
//int main() {
//   
//
//    //Testing area
//
//    int x = 1024;
//    int* pointerX = &x;
//    cout << "Adresa lui x este:" << pointerX << endl;
//    int** pointerPointerX = &pointerX;
//    cout << "Adresa lui pointerX este:" << pointerPointerX << endl;
//    //Valoare x
//    cout << "Valoarea lui x prin pointerX: " << *pointerX << endl;
//    cout << "Valoarea lui x prin pointerPointerX: " << **pointerPointerX << endl;
//    
//    /*pointerX++;
//    pointerPointerX++;
//    cout << "Noua valoarea lui x prin pointerX(daca exista in memorie): " << *pointerX << endl;
//    cout << "Noua valoarea lui x prin pointerPointerX(daca exista in memorie): " << **pointerPointerX << endl;*/
//
//    int(*pointerfunctie)(int a, int b);
//    pointerfunctie = suma;
//    cout <<"Valoarea functiei va fi: " << pointerfunctie(12, 9) << endl;
//
//    int x2 = x;
//    x2++;
//    cout << "Valoare x: " << x << endl;
//    int &refx = x;
//    refx++;
//    cout << "Valoare x: " << x << endl;
//
//
//
//    return 0;
//}
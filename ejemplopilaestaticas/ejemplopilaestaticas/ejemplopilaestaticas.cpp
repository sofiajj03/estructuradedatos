// ejemplopilaestaticas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Pila.h"
#include "TipoDato.h"

using namespace std;

int main()
{
    int N;
    Pila pilita;
    TipoDato tipito;
    cout << "Ingresar el numero de elementos:";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "Ingresar el codigo del producto:";
        cin >> tipito.id;
        cout << "Ingresar la descripcion del producto:";
        cin >> tipito.descripcion;
        pilita.Apilar(tipito);
    }
   
    pilita.VerPila();
}

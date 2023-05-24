#include "Amigo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Amigo::Amigo(){
		nombre = "";
		edad = 0;
		sexo = ' ';
		estado = ' ';
	}

Amigo::Amigo(string nom, int ed, char sx) {
		nombre = nom;
		edad = ed;
		sexo = sx;
		estado = 'A';
	}

 void Amigo::setAmigo(string nom, int ed, char sx) {
		nombre = nom;
		edad = ed;
		sexo = sx;
		estado = 'A';
	}

	string Amigo::getNombre() {
		return(nombre);
	}

	int Amigo::getEdad() {
		return(edad);
	}

	char Amigo::getSexo() {
		return(sexo);
	}

	char Amigo::getEstado() {
		return(estado);
	}

	void Amigo::guardarArchivo(ofstream& fsalida) {
		fsalida.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
		fsalida.write(reinterpret_cast<char*>(&edad), sizeof(edad));
		fsalida.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
		fsalida.write(reinterpret_cast<char*>(&estado), sizeof(estado));
	}

	bool Amigo::leerArchivo(ifstream& fentrada) {
		bool k = false;
		if (fentrada.is_open() == true) {
			fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			if (fentrada.eof() == false) {
				fentrada.read(reinterpret_cast<char*>(&edad), sizeof(edad));
				fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
				fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
				k = true;
			}
			else {
				//cout << endl << "Registro no existe";
			}
		}
		else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	bool Amigo::eliminar(fstream& fes, int nroReg) {
		bool k = false;
		if (fes.is_open() == true) {
			fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			if (fes.eof() == false) {
				fes.read(reinterpret_cast<char*>(&edad), sizeof(edad));
				fes.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
				fes.read(reinterpret_cast<char*>(&estado), sizeof(estado));

				estado = 'E';
				fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
				fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
				fes.write(reinterpret_cast<char*>(&edad), sizeof(edad));
				fes.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
				fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
				k = true;
			}
			else {
				cout << endl << "Registro no existe";
			}
		}
		else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}


	bool Amigo::modificar(fstream& fes, int nroReg) {
		bool k = false;
		if (fes.is_open() == true) {
			string nomAux;
			nomAux = nombre;
			fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			if (fes.eof() == false) {
				nombre = nomAux;
				estado = 'A';
				fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
				fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
				fes.write(reinterpret_cast<char*>(&edad), sizeof(edad));
				fes.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
				fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
				k = true;
			}
			else {
				cout << endl << "Registro no existe";
			}
		}
		else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	bool Amigo::buscar(ifstream& fentrada, int nroReg) {
		bool k = false;
		if (fentrada.is_open() == true) {
			fentrada.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			fentrada.read(reinterpret_cast<char*>(&edad), sizeof(edad));
			fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
			fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
			if (fentrada.eof() == false) {
				k = true;
			}
			else {
				//cout << endl << "Registro no XX existe";
			}
		}
		else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	int Amigo::getTamBytesRegistro() {
		return(sizeof(nombre) + sizeof(edad) + sizeof(sexo) + sizeof(estado));
	}


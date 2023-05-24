#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Amigo.h"

	using namespace std;


	class ABMAmigo {
	private:
		string  nomArchivo;
		Amigo* amig;

	public:

		ABMAmigo(string nomArch);
		void introducirDatos(Amigo* newReg);
		void mostrarRegistro(int nroReg);
		void adicionarNuevo();
		void listar();
		int buscarReg();
		void eliminarReg();
		void modificarReg();
	};

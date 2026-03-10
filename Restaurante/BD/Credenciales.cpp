#include <fstream>
#include <iostream>

#include "Credenciales.hpp"

void Credenciales::agregarUsuario() {
	std::fstream archivo(archivoCredenciales, std::ios::binary | std::ios::out);

	if (archivo.is_open()) {
		Credenciales credenciales;

		std::cout << "Introduzca servidor: ";
		//std::cin.ignore();
		std::cin.getline(credenciales.servidor, 32);

		std::cout << "Introduzca usuario: ";
		//std::cin.ignore();
		std::cin.getline(credenciales.usuario, 32);

		std::cout << "Introduzca contraseña: ";
		//std::cin.ignore();
		std::cin.getline(credenciales.contrasena, 32);

		archivo.write(reinterpret_cast<char*>(&credenciales), sizeof(credenciales));

		archivo.close();
	}
	else {
		std::cerr << "Error al abrir el archivo" << std::endl;
	}
}

Credenciales& Credenciales::obtenerDatos() {
	std::ifstream archivo(archivoCredenciales, std::ios::binary);

	Credenciales credenciales;
	std::memset(credenciales.servidor, 0, 32);
	std::memset(credenciales.usuario, 0, 32);
	std::memset(credenciales.contrasena, 0, 32);

	if (archivo.is_open()) {
		archivo.read(reinterpret_cast<char*>(&credenciales), sizeof(credenciales));
		archivo.close();

		std::cout << credenciales.servidor << " "
				  << credenciales.usuario << " "
				  << credenciales.contrasena << std::endl;
	}
	else {
		std::cerr << "Error al abrir el archivo" << std::endl;
	}

	return credenciales;
}
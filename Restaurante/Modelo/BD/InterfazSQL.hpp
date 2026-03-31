#pragma once

#include <iostream>
#include "C:\Program Files\MySQL\MySQL Connector C++ 9.6\include\mysql\jdbc.h"

class InterfazSQL {
private:
	std::unique_ptr<sql::Connection> con;

public:
	InterfazSQL();

	static std::shared_ptr<InterfazSQL> obtenerInstancia();


	void mostrarDatosBD(const std::string& campos,
		const std::string& tabla,
		const std::string& parametros);

	void insertarDatosBD(const std::string& tabla,
		const std::string& campos,
		const std::string& valores);

	void mostrarMenu();

	std::vector<std::string> mostrarHistorialVentas();

	Platillo obtenerInfoPlatillo(int idPlatillo);

	void registarVenta(float subtotal, float iva, float total);

};

#pragma once

#include <iostream>
#include "C:\Program Files\MySQL\MySQL Connector C++ 9.6\include\mysql\jdbc.h"

#include "../InterfazSQL.hpp"

class AdaptadorMySQL : public InterfazSQL {
private:
	// Composición con biblioteca externa
	sql::Driver* driver;

	std::unique_ptr<sql::Connection> con;

public:
	AdaptadorMySQL();

	static std::shared_ptr<AdaptadorMySQL> obtenerInstancia();

	void mostrarMenu();

	std::vector<std::string> mostrarHistorialVentas() override;

	Platillo obtenerInfoPlatillo(int idPlatillo) override;

	void registarVenta(float subtotal, float iva, float total) override;

};
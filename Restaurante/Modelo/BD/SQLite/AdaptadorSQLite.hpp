#pragma once

#include <iostream>
#include "sqlite3.h"

#include "../InterfazSQL.hpp"

class AdaptadorSQLite : public InterfazSQL {
private:
	// Composición con biblioteca externa
	sqlite3* db;

public:
	AdaptadorSQLite();

	static std::shared_ptr<AdaptadorSQLite> obtenerInstancia();

	void mostrarMenu();

	std::vector<std::string> mostrarHistorialVentas();

	Platillo obtenerInfoPlatillo(int idPlatillo);

	void registarVenta(float subtotal, float iva, float total);

};
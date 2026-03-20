#pragma once

#include <iostream>
#include <mysql/jdbc.h>
#include <Common.hpp>

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

	void mostrarHistorialVentas();

	float obtenerCostoPlatillo(int idPlatillo);

	void registarVenta(Venta venta);

};

#include <iostream>
#include <Common.hpp>

#include "AdaptadorSQLite.hpp"
#include "../Credenciales.hpp"

std::shared_ptr<AdaptadorSQLite> AdaptadorSQLite::obtenerInstancia() {
	static std::shared_ptr<AdaptadorSQLite> instanciaUnica = nullptr;

	if (instanciaUnica == nullptr) {
		instanciaUnica = std::make_shared<AdaptadorSQLite>();
	}
	return instanciaUnica;
}

AdaptadorSQLite::AdaptadorSQLite() {
	// Obtener singleton
	driver = sql::mysql::get_driver_instance();

	Credenciales credenciales;
	//credenciales.agregarUsuario();
	credenciales = credenciales.obtenerDatos();

	// Conectar al servidor
	con.reset(driver->connect(credenciales.servidor,
							  credenciales.usuario,
							  credenciales.contrasena));

	// Equivalente a "USE restaurante"
	con->setSchema("restaurante");
}


void AdaptadorSQLite::mostrarMenu() {
	std::cout << "===========MENU===============" << std::endl;

	std::string query = "SELECT idmenu, nombre_platillo, costo_platillo FROM menu";

	// Crear objeto Statement
	std::unique_ptr< sql::Statement > stmt(con->createStatement());

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr< sql::ResultSet >	res(stmt->executeQuery(query));

	// Leer resultado
	while (res->next()) {
		std::cout << res->getString("idmenu") << "\t"
				  << res->getString("nombre_platillo") << "\t$ "
				  << res->getDouble("costo_platillo") << std::endl;
	}

	std::cout << "=============================" << std::endl;

}

std::vector<std::string> AdaptadorSQLite::mostrarHistorialVentas() {
	std::string query = "SELECT fecha_venta, total_venta FROM ventas ";

	std::vector<std::string> stringRes;

	// Crear objeto Statement
	std::unique_ptr< sql::Statement > stmt(con->createStatement());

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr< sql::ResultSet > res(stmt->executeQuery(query));

	// Leer resultado
	while (res->next()) {
		/*std::cout << res->getString("fecha_venta") << "\t$"
				  << res->getDouble("total_venta") << std::endl;
				  */

		stringRes.push_back(res->getString("fecha_venta") + "\t$" + res->getString("total_venta"));

	}

	return stringRes;
}

Platillo AdaptadorSQLite::obtenerInfoPlatillo(int idPlatillo) {
	std::string query = "SELECT nombre_platillo, costo_platillo FROM menu where idmenu = ?";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ? con variable
	pst->setInt(1, idPlatillo);

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr<sql::ResultSet> res(pst->executeQuery());

	// Obtener resultados del query
	res->next();

	Platillo platillo;

	if (res->rowsCount() == 0) {
		std::cerr << "No se encontraron registros" << std::endl;
		return platillo;
	}

	platillo.id = idPlatillo;
	platillo.nombre = res->getString("nombre_platillo");
	platillo.costo = static_cast<float>(res->getDouble("costo_platillo"));

	return platillo;

}

void AdaptadorSQLite::registarVenta(float subtotal, float iva, float total) {

	std::string query = "INSERT INTO ventas"
						"(fecha_venta, subtotal_venta, iva_venta, total_venta)"
						"VALUES(NOW(), ?, ?, ?)";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ??? con variable
	pst->setDouble(1, subtotal);
	pst->setDouble(2, iva);
	pst->setDouble(3, total);

	// Ejecutar query
	pst->executeUpdate();

	//std::cout << "Venta registrada en base de datos" << std::endl;
}



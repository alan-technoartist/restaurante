#include <iostream>
#include <mysql/jdbc.h>

#include "InterfazSQL.hpp"
#include "Credenciales.hpp"

std::shared_ptr<InterfazSQL> InterfazSQL::obtenerInstancia() {
	static std::shared_ptr<InterfazSQL> instanciaUnica = nullptr;

	if (instanciaUnica == nullptr) {
		instanciaUnica = std::make_shared<InterfazSQL>();
	}
	return instanciaUnica;
}

InterfazSQL::InterfazSQL() {
	// Obtener singleton
	sql::Driver* driver = sql::mysql::get_driver_instance();

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

void InterfazSQL::mostrarDatosBD(const std::string& campos,
					const std::string& tabla,
					const std::string& parametros) {

	std::string query = "SELECT ? FROM ? ?";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ? con variable
	pst->setString(1, campos);
	pst->setString(2, tabla);
	pst->setString(3, parametros);

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr<sql::ResultSet> res(pst->executeQuery());

	if (res->rowsCount() == 0) {
		std::cout << "No se encontraron registros" << std::endl;
		return;
	}

	// Leer resultado
	while (res->next()) {
		std::cout << res->getString("nombre_curso") << std::endl;
	}

}

void InterfazSQL::insertarDatosBD(const std::string& tabla,
						const std::string& campos,
						const std::string& valores) {

	/*std::string query = "SELECT ? FROM ? ?";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ? con variable
	pst->setString(1, campos);
	pst->setString(2, tabla);
	pst->setString(3, parametros);

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr<sql::ResultSet> res(pst->executeQuery());

	if (res->rowsCount() == 0) {
		std::cout << "No se encontraron registros" << std::endl;
		return;
	}

	// Leer resultado
	while (res->next()) {
		std::cout << res->getString("nombre_curso") << std::endl;*/
}

void InterfazSQL::mostrarMenu() {
	std::cout << "Menu restaurante:" << std::endl;

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
}

void InterfazSQL::mostrarHistorialVentas() {
	std::string query = "SELECT fecha_venta, total_venta FROM ventas ";

	// Crear objeto Statement
	std::unique_ptr< sql::Statement > stmt(con->createStatement());

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr< sql::ResultSet > res(stmt->executeQuery(query));

	// Leer resultado
	while (res->next()) {
		std::cout << res->getString("fecha_venta") << "\t$"
				  << res->getDouble("total_venta") << std::endl;
	}
}

float InterfazSQL::obtenerCostoPlatillo(int idPlatillo) {
	std::string query = "SELECT costo_platillo FROM menu where idmenu = ?";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ? con variable
	pst->setInt(1, idPlatillo);

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr<sql::ResultSet> res(pst->executeQuery());

	// Obtener resultados del query
	res->next();

	if (res->rowsCount() == 0) {
		std::cout << "No se encontraron registros" << std::endl;
		return 0.0f;
	}

	return static_cast<float>(res->getDouble("costo_platillo"));

}

void InterfazSQL::registarVenta(Venta venta) {
	std::string query = "INSERT INTO ventas"
						"(fecha_venta, subtotal_venta, iva_venta, total_venta)"
						"VALUES(NOW(), ?, ?, ?)";

	// Crear objeto PreparedStatement
	std::unique_ptr<sql::PreparedStatement> pst(con->prepareStatement(query));

	// Asociar ??? con variable
	pst->setDouble(1, venta.subtotal);
	pst->setDouble(2, venta.iva);
	pst->setDouble(3, venta.total);

	// Ejecutar query
	pst->executeUpdate();

	std::cout << "Venta registrada en base de datos" << std::endl;
}



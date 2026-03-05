#include <iostream>
#include <mysql/jdbc.h>

#include "InterfazSQL.hpp"

InterfazSQL::InterfazSQL() {
	// Obtener singleton
	sql::Driver* driver = sql::mysql::get_driver_instance();

	// Conectar al servidor
	con.reset(driver->connect("localhost", "alan", "technoartist"));

	// Equivalente a "USE escuela"
	con->setSchema("escuela");
}

void InterfazSQL::mostrarDatosBD(const std::string& campos,
					const std::string& tabla,
					const std::string& parametros) {

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
		std::cout << res->getString("nombre_curso") << std::endl;
	}*/

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
	std::string query = "SELECT nombre_platillo, costo_platillo FROM menu";

	// Crear objeto Statement
	std::unique_ptr< sql::Statement > stmt(con->createStatement());

	// Ejecutar query y asignar a ResultSet
	std::unique_ptr< sql::ResultSet >	res(stmt->executeQuery(query));

	// Leer resultado
	while (res->next()) {
		std::cout << res->getString("nombre_platillo") << "\t"
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
		std::cout << res->getString("fecha_venta") << "\t"
					<< res->getDouble("total_venta") << std::endl;
	}
}



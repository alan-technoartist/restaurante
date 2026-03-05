#include <iostream>
#include <mysql/jdbc.h>

class InterfazSQL {
private:
	std::unique_ptr<sql::Connection> con;

public:
	InterfazSQL();

	void mostrarDatosBD(const std::string& campos,
		const std::string& tabla,
		const std::string& parametros);

	void insertarDatosBD(const std::string& tabla,
		const std::string& campos,
		const std::string& valores);

	void mostrarMenu();

	void mostrarHistorialVentas();

};

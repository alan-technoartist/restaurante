#include <string>

const std::string archivoCredenciales = "credenciales.bin";

struct Credenciales {
	char servidor[32];
	char usuario[32];
	char contrasena[32];

	void agregarUsuario();
	Credenciales& obtenerDatos();
};


#include <string>

const std::string archivoCredenciales = "credenciales.bin";

struct Credenciales {
	char servidor[32]; // servidor
	char usuario[32]; // usuario
	char contrasena[32]; // contraseña

	void agregarUsuario();
	Credenciales& obtenerDatos();
};


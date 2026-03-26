#include "include/Restaurante.hpp"

int main() {
	auto modelo = std::make_shared<Modelo>();
	auto controlador = std::make_shared<Controlador>(modelo);

	// Objeto polimórfico
	std::shared_ptr<IVista> vista = std::make_shared<VistaCLI>(controlador);

	controlador->setVista(vista);
	controlador->iniciar();

	return 0;
}

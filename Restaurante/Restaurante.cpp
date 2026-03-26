#include <iostream>
#include "include/Restaurante.hpp"

int main() {
	std::shared_ptr<Modelo> modelo = std::make_shared<Modelo>();
	std::shared_ptr<IVista> vista = std::make_shared<VistaCLI>();

	Controlador controlador(modelo, vista);

	controlador.iniciar();

	return 0;
}

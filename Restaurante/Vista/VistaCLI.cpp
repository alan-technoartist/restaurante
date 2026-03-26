#include <iostream>
#include "VistaCLI.hpp"

VistaCLI::VistaCLI(std::weak_ptr<Controlador> controlador) {
	this->controlador = controlador;
}

void VistaCLI::mostrarMesas(const std::map<int, std::shared_ptr<Mesa>>& mesas) {
	for (const auto& mesa : mesas) {
		std::cout << "Mesa " << mesa.first << "\t"
			<< mesa.second->disponible << std::endl;
	}
}

void VistaCLI::asignarMesa() {
	bool prioridad;
	std::cout << "Prioridad (0/1): ";
	std::cin >> prioridad;

	// TODO: Considerar evitar llamadas al controlador
	int numMesa = controlador.lock()->asignarMesa(prioridad);

	if (numMesa == -1) {
		std::cout << "No hay mesas disponibles" << std::endl;
	}
	else {
		std::cout << "Mesa asignada: " << numMesa << std::endl;
	}

}

int VistaCLI::tomarOrden(std::shared_ptr<std::list<Platillo>> comanda) {
	int numMesa;
	std::cout << "Numero de mesa: ";
	std::cin >> numMesa;

	int i = 1;

	Platillo platillo;


	// Orden del cliente
	do {
		// FIXME
		std::cout << "Elija platillo (10 para salir)" << std::endl;

		std::cout << "Platillo " << i++ << ": ";
		std::cin >> platillo.id;

		comanda->push_back(platillo);

	} while (platillo.id != 10);

	return numMesa;
}

int VistaCLI::cerrarCuenta() {
	int numMesa;
	std::cout << "Numero de mesa: ";
	std::cin >> numMesa;

	return numMesa;
}

void VistaCLI::mostrarHistorialVentas() {
	std::cout << "Historial de ventas: " << std::endl;
	// while (...)
	//controlador.obtenerHistorialVentas();
}

int VistaCLI::menuUsuario() {
	int opcion;

	std::cout << "1. Mostar mesas" << std::endl;
	std::cout << "2. Asignar mesa" << std::endl;
	std::cout << "3. Tomar orden" << std::endl;
	std::cout << "4. Cerrar cuenta" << std::endl;
	std::cout << "5. Mostar historial ventas" << std::endl;
	std::cout << "6. Salir" << std::endl << std::endl;

	std::cout << "Opcion: ";
	std::cin >> opcion;

	return opcion;
}

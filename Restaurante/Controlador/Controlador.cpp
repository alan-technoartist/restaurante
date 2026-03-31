#include "Controlador.hpp"
#include "../Modelo/Modelo.hpp"
#include "../Vista/IVista.hpp"

Controlador::Controlador(std::shared_ptr <Modelo> modelo) {

	this->modelo = modelo;
}

void Controlador::setVista(std::shared_ptr <IVista> vista) {
	this->vista = vista;
}

int Controlador::asignarMesa(bool prioridad) {
	auto mesa = modelo->asignarMesa(prioridad);

	if (mesa != nullptr) {
		return mesa->numMesa;
	}

	return -1;
}

std::map<int, std::shared_ptr<Mesa>>& Controlador::obtenerMesas() {
	return modelo->obtenerMesas();
}

void Controlador::procesarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda) {
	modelo->procesarOrden(numMesa, comanda);
}

void Controlador::cerrarCuenta(int numMesa) {
	modelo->cerrarCuenta(numMesa);
}

void Controlador::iniciar() {
	int opcion;

	modelo->iniciarMesas();

	do {
		opcion = vista->menuUsuario();

		if (opcion == 1) {
			// Imprime mapa de mesas
			vista->mostrarMesas(obtenerMesas());
		}
		else if (opcion == 2) {
			// Pregunta prioridad
			// Llama al controlador
			// Imprime el num de mesa asignada
			// o si no hay disponibilidad
			vista->asignarMesa();
		}
		else if (opcion == 3) {
			// Pregunta num de mesa
			// Pide platillos
			int numMesa = vista->pedirMesa();
			std::shared_ptr<std::list<Platillo>> orden = vista->tomarOrden();

			procesarOrden(numMesa, orden);
		}
		else if (opcion == 4) {
			// Pregunta num de mesa
			int numMesa = vista->cerrarCuenta();
			cerrarCuenta(numMesa);
		}
		else if (opcion == 5) {
			// Imprime historial de ventas
			vista->mostrarHistorialVentas(modelo->mostrarHistorialVentas());
		}
		else {
			//std::cout << "Opcion no válida" << std::endl;
		}

	} while (opcion != 6);
}

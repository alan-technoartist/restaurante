#include <iostream>
#include "Cocina.hpp"

std::shared_ptr<Cocina> Cocina::obtenerInstancia() {
	static std::shared_ptr<Cocina> instanciaUnica = nullptr;

	if (instanciaUnica == nullptr) {
		instanciaUnica = std::make_shared<Cocina>();
	}
	return instanciaUnica;
}

void Cocina::encolarOrden(int numMesa, const std::list<Platillo>& platillos, bool prioridad) {
	auto orden = std::pair<int, std::list<Platillo>>(numMesa, platillos);

	if (prioridad) {
		colaCocina.push_front(orden);
	}
	else {
		colaCocina.push_back(orden);
	}
	/*std::cout << "Orden de mesa " << orden.first << " encolada con prioridad "
		<< ((prioridad)?"ALTA":"NORMAL") << std::endl;*/

	// Interfaz pública
	prepararOrden();
}

void Cocina::prepararOrden() {
	// ...
	// Orden lista, sacar de la cola
	colaCocina.pop_front();

	// Notificar
}

void Cocina::mostrarColaCocina() {
	if (colaCocina.empty()) {
		std::cout << "No hay ordenes en cola" << std::endl;
		return;
	}

	std::cout << "Mesa\tPlatillo" << std::endl;

	for (const auto& orden : colaCocina) {
		std::cout << orden.first << "\t";

		for (const auto& platillo : orden.second) {
			std::cout << platillo.nombre << ", ";
		}
		std::cout << std::endl;
	}
}

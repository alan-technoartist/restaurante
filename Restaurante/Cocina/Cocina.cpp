#include <iostream>
#include "Cocina.hpp"

std::shared_ptr<Cocina> Cocina::obtenerInstancia() {
	static std::shared_ptr<Cocina> instanciaUnica = nullptr;

	if (instanciaUnica == nullptr) {
		instanciaUnica = std::make_shared<Cocina>();
	}
	return instanciaUnica;
}

void Cocina::encolarOrden(int numMesa, std::list<Platillo>& platillos, bool prioridad) {
	Orden orden;
	orden.platillos = platillos;
	orden.numMesa = numMesa;

	if (prioridad) {
		colaCocina.push_front(orden);
	}
	else {
		colaCocina.push_back(orden);
	}
	std::cout << "Orden de mesa " << numMesa << " encolada con prioridad "
		<< ((prioridad)?"ALTA":"NORMAL") << std::endl;

}

void Cocina::prepararOrden() {
	Orden orden = colaCocina.front();

	for (auto& platillo : orden.platillos) {
		std::cout << "Preparando " << platillo.id << std::endl;
	}

	colaCocina.pop_front();
}

void Cocina::mostrarColaCocina() {
	if (colaCocina.empty()) {
		std::cout << "No hay ordenes en cola" << std::endl;
		return;
	}

	std::cout << "Mesa\tPlatillo" << std::endl;

	for (auto& orden : colaCocina) {
		std::cout << orden.numMesa << "\t";

		for (auto& platillo : orden.platillos) {
			std::cout << platillo.id << ", ";
		}
		std::cout << std::endl;
	}
}

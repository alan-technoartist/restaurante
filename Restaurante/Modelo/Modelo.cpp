#include "Modelo.hpp"

Modelo::Modelo() {
	controlMesas = std::make_shared<Mesas>();
}

void Modelo::iniciarMesas() {
	//
	// Iniciar mapa de mesas
	//
	for (int i = 0; i < NUM_MESAS; i++) {
		std::shared_ptr<Mesa> m = std::make_shared<Mesa>(i, true, false);

		_mesas[i] = m;
	}
}

std::map<int, std::shared_ptr<Mesa>>& Modelo::obtenerMesas() {
	return _mesas;
}

std::shared_ptr<Mesa> Modelo::buscarDisponible() {

	for (auto& mesa : _mesas) {
		if (mesa.second->disponible == true) {
			mesa.second->disponible = false;

			return mesa.second;
		}
	}

	return nullptr;
}

std::shared_ptr<Mesa> Modelo::asignarMesa(bool prioridad) {

	auto mesa = buscarDisponible();

	if (mesa != nullptr) {
		controlMesas->setPrioridad(mesa, prioridad);
	}

	return mesa;
}

void Modelo::tomarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda) {
	_mesas[numMesa]->comanda = *comanda;
	controlMesas->tomarOrden(_mesas[numMesa]);
}

void Modelo::cerrarCuenta(int numMesa) {
	//_mesas[numMesa]->pagarCuenta();
	controlMesas->pagarCuenta(_mesas[numMesa]);
}
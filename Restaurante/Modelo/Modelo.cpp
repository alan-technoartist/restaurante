#include "Modelo.hpp"

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
	std::map<int, std::shared_ptr<Mesa>> mes;
	return mes;
}

std::shared_ptr<Mesa> Modelo::buscarDisponible() {

	/*for (auto& mesa : _mesas) {
		if (mesa.second->disponible == true) {
			mesa.second->disponible = false;

			return mesa.second;
		}
	}*/

	return nullptr;
}

std::shared_ptr<Mesa> Modelo::asignarMesa(bool prioridad) {

	auto mesa = buscarDisponible();

	if (mesa != nullptr) {
		mesa->setPrioridad(prioridad);
	}

	return mesa;
}

void Modelo::tomarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda) {
	//_mesas[numMesa]->comanda = *comanda;
	//_mesas[numMesa]->tomarOrden();
}

void Modelo::cerrarCuenta(int numMesa) {
	//_mesas[numMesa]->pagarCuenta();
}
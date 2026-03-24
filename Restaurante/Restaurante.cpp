#include <iostream>
#include "include/Restaurante.hpp"

namespace Restaurante {
	void iniciarMesas() {
		//
		// Iniciar mapa de mesas
		//
		for (int i = 0; i < NUM_MESAS; i++) {
			std::shared_ptr<Mesa> m = std::make_shared<Mesa>(i, true, false);

			_mesas[i] = m;
		}
	}

	std::shared_ptr<Mesa> asignarMesa() {
		//
		// Obtener primer mesa disponible
		// 
		for (auto& mesa : _mesas) {
			if (mesa.second->disponible == true) {
				mesa.second->disponible = false;

				return mesa.second;
			}
		}

		return nullptr;
	}

	void nuevoCliente() {

	}
};

int main() {
	//Restaurante restaurante;
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();

	Restaurante::iniciarMesas();

	std::shared_ptr<Mesa> mesa;
	//
	// Atender nuevo cliente
	//
	mesa = Restaurante::asignarMesa();

	if (mesa == nullptr) {
		std::cerr << "No hay mesas disponibles" << std::endl;
		return -1;
	}
	else {
		mesa->setPrioridad(false);

		// Mostrar menú
		//isql->mostrarMenu();

		//
		// Tomar pedido y enviar orden
		//
		mesa->tomarOrden();

		// Pagar cuenta y liberar mesa
		//mesa->pagarCuenta();
	}

	//
	// Atender nuevo cliente
	//
	mesa = Restaurante::asignarMesa();

	if (mesa == nullptr) {
		std::cerr << "No hay mesas disponibles" << std::endl;
		return -1;
	}
	else {
		mesa->setPrioridad(true);

		// Mostrar menú
		//isql->mostrarMenu();

		//
		// Tomar pedido y enviar orden
		//
		mesa->tomarOrden();

		// Pagar cuenta y liberar mesa
		//mesa->pagarCuenta();
	}

	Restaurante::_mesas[0]->pagarCuenta();

	Restaurante::_mesas[1]->pagarCuenta();


	//
	// Mostrar historial ventas
	//
	//isql->mostrarHistorialVentas();

	return 0;
}

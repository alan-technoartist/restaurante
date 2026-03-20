#include <iostream>
#include "include/Restaurante.hpp"

void iniciarMesas(int numMesas) {

	for (int i = 0; i < numMesas; i++) {
		std::shared_ptr<Mesa> m = std::make_shared<Mesa>(i+1, true, false);

		_mesas[i] = m;
	}

}

int main()
{
	//
	// Interfaz con base de datos
	//
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();

	iniciarMesas(_numMesas);

	//
	// Obtener instancia a cocina
	//
	auto cocina = Cocina::obtenerInstancia();

	//
	// Obtener iterador a primer mesa disponible
	// 
	std::map<int, std::shared_ptr<Mesa>>::iterator itMesa;

	for (itMesa = _mesas.begin(); itMesa != _mesas.end(); ++itMesa) {
		if (itMesa->second->disponible == true)
			break;
	}

	if (itMesa == _mesas.end()) {
		std::cout << "No hay mesas disponibles" << std::endl;
	}
	else {
		isql->mostrarMenu();

		//
		// Ocupar mesa, tomar pedido y enviar orden
		//
		(itMesa->second)->disponible = false;
		(itMesa->second)->tomarOrden();
		(itMesa->second)->enviarOrden();

		cocina->mostrarColaCocina();
		cocina->prepararOrden();
		cocina->mostrarColaCocina();

		(itMesa->second)->pagarCuenta();
		(itMesa->second)->disponible = true;

	}

	isql->mostrarHistorialVentas();

	return 0;
}

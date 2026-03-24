#include "Mesa.hpp"
#include "../Cocina/Cocina.hpp"
#include "../BD/InterfazSQL.hpp"
#include "../Ventas/Ventas.hpp"

Mesa::Mesa(int n, bool d, bool v)
	: numMesa(n),
	  disponible(d),
	  vip(v) {
}

void Mesa::setPrioridad(bool alta) {
	if (alta) vip = true;
}


void Mesa::tomarOrden() {
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();

	Platillo platillo;
	int id;

	int num_platillos = 2;

	// Orden del cliente
	for (int i = 1; i <= num_platillos; i++) {
		std::cout << "Platillo: ";
		std::cin >> id;
		platillo.id = id;
		platillo = isql->obtenerInfoPlatillo(platillo.id);

		comanda.push_back(platillo);

	}

	enviarOrden();
}

void Mesa::enviarOrden() {
	auto cocina = Cocina::obtenerInstancia();

	cocina->encolarOrden(numMesa, comanda, vip);
}

void Mesa::pagarCuenta() {
	Ventas venta;

	venta.cerrarCuenta(this->numMesa, this->comanda);

	this->disponible = true;
}

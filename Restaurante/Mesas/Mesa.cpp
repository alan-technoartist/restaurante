#include "Mesa.hpp"
#include "../Cocina/Cocina.hpp"
#include "../BD/InterfazSQL.hpp"
#include "../Ventas/Ventas.hpp"

Mesa::Mesa(int n, bool d, bool v)
	: numMesa(n),
	  disponible(d),
	  vip(v) {
}

void Mesa::tomarOrden() {
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();

	Platillo platillo1;
	platillo1.id = 3; // Milanesa
	platillo1.costo = isql->obtenerCostoPlatillo(platillo1.id);

	std::cout << "Platillo id 3 costo : $" << platillo1.costo << std::endl;

	Platillo platillo2;
	platillo2.id = 2; // Tacos
	platillo2.costo = isql->obtenerCostoPlatillo(platillo2.id);

	std::cout << "Platillo id 2 costo : $" << platillo2.costo << std::endl;

	comanda.push_back(platillo1);
	comanda.push_back(platillo2);
}

void Mesa::enviarOrden() {
	auto cocina = Cocina::obtenerInstancia();

	cocina->encolarOrden(numMesa, comanda, vip);

}

void Mesa::pagarCuenta() {
	Ventas venta;
	venta.imprimirTotal(comanda);

	venta.cerrarCuenta(comanda);
}

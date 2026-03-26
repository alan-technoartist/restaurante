#include "Mesas.hpp"
#include "../Cocina/Cocina.hpp"
#include "../BD/InterfazSQL.hpp"
#include "../Ventas/Ventas.hpp"

void Mesas::setPrioridad(std::shared_ptr<Mesa> mesa, bool alta) {
	if (alta)
		mesa->vip = true;
}

void Mesas::tomarOrden(std::shared_ptr<Mesa> mesa) {
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();
	auto cocina = Cocina::obtenerInstancia();

	cocina->encolarOrden(mesa->numMesa, mesa->comanda, mesa->vip);
}

void Mesas::pagarCuenta(std::shared_ptr<Mesa> mesa) {
	Ventas venta;

	venta.cerrarCuenta(mesa->numMesa, mesa->comanda);

	mesa->disponible = true;
}

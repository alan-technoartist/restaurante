#include <iostream>
#include "Ventas.hpp"

void Ventas::cerrarCuenta(int numMesa, std::list<Platillo>& orden) {
	Cuenta cuenta;
	std::cout << "===========CUENTA===============" << std::endl;

	std::cout << "Mesa: " << numMesa << std::endl;
	std::cout << "Platillo" << "\t" << "Costo" << std::endl;

	float total = std::accumulate(orden.begin(), orden.end(), 0.0f,
		[](float costo, Platillo& platillo) {
			std::cout << platillo.nombre << "\t$" << platillo.costo << std::endl;

			return costo += platillo.costo;
		});

	std::cout << "Total: " << "\t\t$" << total << std::endl;
	std::cout << "================================" << std::endl;

	std::shared_ptr<InterfazSQL> isql = AdaptadorMySQL::obtenerInstancia();

	cuenta.total = total;
	cuenta.subtotal = cuenta.total * ((100.0f - IVA) / 100);
	cuenta.iva = cuenta.total - cuenta.subtotal;

	isql->registarVenta(cuenta.subtotal, cuenta.iva, cuenta.total);

}

std::vector<std::string> Ventas::mostrarHistorialVentas() {
	std::shared_ptr<InterfazSQL> isql = AdaptadorMySQL::obtenerInstancia();

	return isql->mostrarHistorialVentas();
}


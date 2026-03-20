#include <iostream>
#include "Ventas.hpp"

float Ventas::calcularTotal(std::list<Platillo>& orden) {
	float total = std::accumulate(orden.begin(), orden.end(), 0.0f,
		[](float costo, Platillo& platillo) {
			std::cout << platillo.id << "\t" << "$" << platillo.costo << std::endl;

			return costo += platillo.costo;
		});

	return total;
}

void Ventas::imprimirTotal(std::list<Platillo>& orden) {

	std::cout << "Total: " << "\t" << "$" << calcularTotal(orden) << std::endl;
}

void Ventas::cerrarCuenta(std::list<Platillo>& orden) {
	std::shared_ptr<InterfazSQL> isql = InterfazSQL::obtenerInstancia();

	Venta venta;

	std::cout << "Calculando costo + IVA" << std::endl;

	venta.total = calcularTotal(orden);
	venta.subtotal = venta.total * ((100.0f - IVA) / 100);
	venta.iva = venta.total - venta.subtotal;

	isql->registarVenta(venta);
}
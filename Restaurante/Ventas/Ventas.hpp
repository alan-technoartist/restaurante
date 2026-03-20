#pragma once

#include <list>
#include <numeric>
#include <Common.hpp>
#include "../BD/InterfazSQL.hpp"


class Ventas {
public:

	const float IVA = 16.0;

	float calcularTotal(std::list<Platillo>& orden);

	void imprimirTotal(std::list<Platillo>& orden);

	void cerrarCuenta(std::list<Platillo>& orden);

};
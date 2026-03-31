#pragma once

#include <list>
#include <numeric>
#include <Common.hpp>

#include "../BD/InterfazSQL.hpp"
#include "../Mesas/Mesas.hpp"

class Ventas {
private:
	const float IVA = 16.0f;

public:

	void cerrarCuenta(int numMesa, std::list<Platillo>& orden);

	std::vector<std::string> mostrarHistorialVentas();


};
#pragma once

#include <map>

#include "BD/InterfazSQL.hpp"
#include "Cocina/Cocina.hpp"
#include "Mesas/Mesa.hpp"
#include "Ventas/Ventas.hpp"

//#include "../Controlador/Controlador.hpp"

class Modelo {
private:
	const int NUM_MESAS = 5;

	static std::map<int, std::shared_ptr<Mesa>> _mesas;

public:
	void iniciarMesas();

	std::map<int, std::shared_ptr<Mesa>>& obtenerMesas();

	std::shared_ptr<Mesa> buscarDisponible();

	std::shared_ptr<Mesa> asignarMesa(bool prioridad);

	void tomarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda);

	void cerrarCuenta(int numMesa);
};
#pragma once

#include <map>
#include <Common.hpp>

#include "BD/InterfazSQL.hpp"
#include "Cocina/Cocina.hpp"
#include "Mesas/Mesas.hpp"
#include "Ventas/Ventas.hpp"

//#include "../Controlador/Controlador.hpp"

class Modelo {
private:
	const int NUM_MESAS = 5;

	std::map<int, std::shared_ptr<Mesa>> _mesas;

	std::shared_ptr<Mesas> controlMesas;

public:
	Modelo();

	void iniciarMesas();

	std::map<int, std::shared_ptr<Mesa>>& obtenerMesas();

	std::shared_ptr<Mesa> buscarDisponible();

	std::shared_ptr<Mesa> asignarMesa(bool prioridad);

	void procesarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda);

	void cerrarCuenta(int numMesa);

	std::vector<std::string> mostrarHistorialVentas();

};
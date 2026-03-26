#pragma once

#include <map>
#include <memory>

#include "../Modelo/Modelo.hpp"
#include "../Vista/IVista.hpp"

class Controlador {
private:

	std::shared_ptr <Modelo> modelo;
	std::shared_ptr <IVista> vista;

public:
	Controlador(std::shared_ptr<Modelo> modelo,
				std::shared_ptr<IVista> vista);

	void iniciar();

	std::map<int, std::shared_ptr<Mesa>>& obtenerMesas();

	std::shared_ptr<Mesa> asignarMesa(bool prioridad);

	void tomarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda);

	void cerrarCuenta(int numMesa);
};
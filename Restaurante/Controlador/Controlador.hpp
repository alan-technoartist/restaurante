#pragma once

#include <memory>
#include <list>
#include <map>
#include <Common.hpp>

// Declaración anticipada
class Modelo;
class IVista;

class Controlador {
private:

	std::shared_ptr <Modelo> modelo;
	std::shared_ptr <IVista> vista;

public:
	Controlador(std::shared_ptr<Modelo> modelo);

	void setVista(std::shared_ptr <IVista> vista);

	void iniciar();

	std::map<int, std::shared_ptr<Mesa>>& obtenerMesas();

	int asignarMesa(bool prioridad);

	void tomarOrden(int numMesa, std::shared_ptr< std::list<Platillo> > comanda);

	void cerrarCuenta(int numMesa);
};
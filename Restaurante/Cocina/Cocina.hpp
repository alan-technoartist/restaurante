#pragma once

#include <deque>
#include <list>
#include <memory>

#include <Common.hpp>

class Cocina {
private:
	std::deque< std::pair<int, std::list<Platillo> > > colaCocina;

	void prepararOrden();

public:
	static std::shared_ptr<Cocina> obtenerInstancia();

	void encolarOrden(int numMesa, const std::list<Platillo>& platillos, bool prioridad);

	void mostrarColaCocina();
};
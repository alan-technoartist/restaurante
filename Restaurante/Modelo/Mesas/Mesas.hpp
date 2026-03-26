#pragma once
#include <list>
#include <Common.hpp>

class Mesas {
public:

	void setPrioridad(std::shared_ptr<Mesa> mesa, bool alta);

	void tomarOrden(std::shared_ptr<Mesa> mesa);

	void pagarCuenta(std::shared_ptr<Mesa> mesa);

};
#pragma once
#include <list>
#include <Common.hpp>

#include "../BD/MySQL/AdaptadorMySQL.hpp"

class Mesas {
public:

	void setPrioridad(std::shared_ptr<Mesa> mesa, bool alta);

	void procesarOrden(std::shared_ptr<Mesa> mesa);

	void pagarCuenta(std::shared_ptr<Mesa> mesa);

};
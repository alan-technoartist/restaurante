#pragma once

#include <iostream>
#include <memory>
#include <map>

#include <Common.hpp>

#include "../BD/InterfazSQL.hpp"
#include "../Mesas/Mesa.hpp"
#include "../Ventas/Ventas.hpp"

namespace Restaurante {
	//private:
	const int NUM_MESAS = 5;

	//public:
	static std::map<int, std::shared_ptr<Mesa>> _mesas;

	void iniciarMesas();
	std::shared_ptr<Mesa> asignarMesa();

};

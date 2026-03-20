#pragma once

#include <iostream>
#include <memory>
#include <unordered_set>
#include <set>

#include <Common.hpp>
#include "BD/InterfazSQL.hpp"
#include "Mesas/Mesa.hpp"
#include "Cocina/Cocina.hpp"
#include "Ventas/ventas.hpp"

const int _numMesas = 5;

std::map<int, std::shared_ptr<Mesa>> _mesas;
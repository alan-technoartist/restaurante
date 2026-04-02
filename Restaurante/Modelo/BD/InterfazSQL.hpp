#pragma once

#include <vector>
#include <Common.hpp>

class InterfazSQL {
public:

	virtual std::vector<std::string> mostrarHistorialVentas() = 0;

	virtual Platillo obtenerInfoPlatillo(int idPlatillo) = 0;

	virtual void registarVenta(float subtotal, float iva, float total) = 0;
};
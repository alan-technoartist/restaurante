#pragma once

#include <string>

enum class TipoElemento {
	ALIMENTO,
	BEBIDA
};

struct Platillo {
	int id;
	std::string nombre;
	float costo;
	TipoElemento tipo;
};

struct Cuenta {
	float subtotal;
	float iva;
	float total;
};
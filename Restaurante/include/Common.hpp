#pragma once

#include <memory>
#include <list>
#include <string>

//#include "../Modelo/Modelo.hpp"
//#include "../Vista/IVista.hpp"

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
	float subtotal = 0;
	float iva = 0;
	float total = 0;
};

struct Mesa {
	bool disponible;
	int numMesa;
	bool vip;
	std::list<Platillo> comanda;
	Cuenta cuenta;

	Mesa(int n, bool d, bool v) :
		numMesa(n),
		disponible(d),
		vip(v) { }
};
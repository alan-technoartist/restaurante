#pragma once
#include <list>
#include <Common.hpp>

class Mesa {
public:
	bool disponible;
	std::list<Platillo> comanda;
	int numMesa;
	bool vip;
	Cuenta cuenta;

	Mesa(int numMesa, bool disponible, bool vip);

public:
	void setPrioridad(bool alta);

	void tomarOrden();

	void enviarOrden();

	void pagarCuenta();

};
#pragma once

#include <deque>
#include <list>
#include <memory>

#include <Common.hpp>

class IObservador {
public:
	virtual ~IObservador() = default;
	virtual void callback() = 0;
};

class Mesero : public IObservador {
	void callback() override {
		//std::cout << "Orden lista" << std::endl;
	}
};

class Cocina {
private:
	std::deque< std::pair<int, std::list<Platillo> > > colaCocina;

	std::list<IObservador*> observadores;

public:
	static std::shared_ptr<Cocina> obtenerInstancia();

	void prepararOrden();

	void encolarOrden(int numMesa, const std::list<Platillo>& platillos, bool prioridad);

	void mostrarColaCocina();

	void registrarObservador();

	void desregistrarObservador();
};
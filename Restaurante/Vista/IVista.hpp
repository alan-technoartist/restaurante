#pragma once

#include <memory>
#include <map>
#include "../Controlador/Controlador.hpp"

class IVista {
private:
	std::shared_ptr<Controlador> controlador;

public:
	virtual int menuUsuario() = 0;

	virtual void mostrarMesas(const std::map<int, std::shared_ptr<Mesa>>& mesas) = 0;

	virtual void asignarMesa() = 0;

	virtual int tomarOrden(std::shared_ptr<std::list<Platillo>> comanda) = 0;

	virtual int cerrarCuenta() = 0;

	virtual void mostrarHistorialVentas() = 0;

};

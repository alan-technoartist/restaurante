#pragma once

#include <memory>
#include <map>
#include <list>
#include <Common.hpp>

#include "../Controlador/Controlador.hpp"

class IVista {
protected:

	// Usamos weak pointer para evitar dependencia circular
	// entre controlador <--> vista
	std::weak_ptr<Controlador> controlador;

public:
	virtual ~IVista() = default;

	virtual int menuUsuario() = 0;

	virtual void mostrarMesas(const std::map<int, std::shared_ptr<Mesa>>& mesas) = 0;

	virtual void asignarMesa() = 0;

	virtual int pedirMesa() = 0;

	virtual std::shared_ptr<std::list<Platillo>> tomarOrden() = 0;

	virtual int cerrarCuenta() = 0;

	virtual void mostrarHistorialVentas() = 0;

};

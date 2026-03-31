#pragma once
#include <vector>
#include <Common.hpp>
#include "IVista.hpp"

class VistaCLI : public IVista {
public:
	VistaCLI(std::weak_ptr<Controlador> controlador);

	int menuUsuario() override;

	void mostrarMesas(const std::map<int, std::shared_ptr<Mesa>>& mesas) override;

	void asignarMesa() override;

	int pedirMesa() override;

	std::shared_ptr<std::list<Platillo>> tomarOrden() override;

	int cerrarCuenta() override;

	void mostrarHistorialVentas(std::vector<std::string> ventas) override;
};
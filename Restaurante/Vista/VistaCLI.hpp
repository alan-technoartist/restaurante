#include "IVista.hpp"

class VistaCLI : public IVista {
public:
	int menuUsuario() override;

	void mostrarMesas(const std::map<int, std::shared_ptr<Mesa>>& mesas) override;

	void asignarMesa() override;

	int tomarOrden(std::shared_ptr<std::list<Platillo>> comanda) override;

	int cerrarCuenta() override;

	void mostrarHistorialVentas() override;
};
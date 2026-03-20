#include <deque>
#include <list>
#include <memory>

#include <Common.hpp>

class Cocina {
private:
	struct Orden {
		std::list<Platillo> platillos;
		int numMesa;
	};

	std::deque< Orden > colaCocina;

public:
	static std::shared_ptr<Cocina> obtenerInstancia();
	void encolarOrden(int numMesa, std::list<Platillo>& orden, bool prioridad);
	void prepararOrden();
	void mostrarColaCocina();
};
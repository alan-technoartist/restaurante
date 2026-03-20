#include <list>
#include <Common.hpp>

class Mesa {
public:
	bool disponible;
	std::list<Platillo> comanda;
	int numMesa;
	bool vip;

public:
	Mesa(int numMesa, bool disponible, bool vip);
	void tomarOrden();
	void enviarOrden();
	void pagarCuenta();

	bool operator==(const Mesa& other) const {
		return numMesa == other.numMesa;
	}
	struct MesaHasher {
		std::size_t operator()(const Mesa& m) const {
			return std::hash<int>{}(m.numMesa) ^ (std::hash<bool>{}(m.disponible) << 1);
		}
	};
};
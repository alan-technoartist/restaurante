#pragma once

enum class TipoElemento {
	ALIMENTO,
	BEBIDA
};

struct Platillo {
	int id;
	float costo;
	TipoElemento tipo;
};

struct Venta {
	float subtotal;
	float iva;
	float total;
};
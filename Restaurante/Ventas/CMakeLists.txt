# Carpeta de encabezados general

# Programa principal (ejecutable)
add_library (Ventas  "Ventas.cpp" "../Cocina/Cocina.cpp")
target_link_libraries(Ventas PRIVATE InterfazSQL)
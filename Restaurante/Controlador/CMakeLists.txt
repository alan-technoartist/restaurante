# Carpeta de encabezados general
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Programa principal (ejecutable)
add_library (Controlador  "Controlador.cpp")

target_link_libraries(Controlador PRIVATE Modelo)
target_link_libraries(Controlador PRIVATE Vista)

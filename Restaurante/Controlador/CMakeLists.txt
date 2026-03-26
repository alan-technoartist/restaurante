# Carpeta de encabezados general
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/Modelo/)

#add_subdirectory (${PROJECT_SOURCE_DIR}/Restaurante/Modelo/)

# Programa principal
add_library (Controlador  "Controlador.cpp" "Controlador.hpp")

#target_link_libraries(Controlador PRIVATE Vista)
target_link_libraries(Controlador PRIVATE Modelo)

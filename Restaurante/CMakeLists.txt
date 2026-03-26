# Carpeta de encabezados general
include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/Modelo/)

# Subcarpetas
add_subdirectory ("Modelo/")
add_subdirectory ("Vista")
add_subdirectory ("Controlador")

# Programa principal (ejecutable)
add_executable (Restaurante "Restaurante.cpp" "include/Restaurante.hpp")

# Módulos de los que depende el ejecutable
target_link_libraries(Restaurante PRIVATE Modelo)
target_link_libraries(Restaurante PRIVATE Vista)
target_link_libraries(Restaurante PRIVATE Controlador)
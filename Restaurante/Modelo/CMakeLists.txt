# Carpeta de encabezados general
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

add_subdirectory ("BD")
add_subdirectory ("Mesas")
add_subdirectory ("Cocina")
add_subdirectory ("Ventas")

# Programa principal (ejecutable)
add_library (Modelo  "Modelo.cpp")

target_link_libraries(Modelo PRIVATE InterfazSQL)
target_link_libraries(Modelo PRIVATE Cocina)
target_link_libraries(Modelo PRIVATE Mesas)
target_link_libraries(Modelo PRIVATE Ventas)
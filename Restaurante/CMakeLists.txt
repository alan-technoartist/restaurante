# Carpeta de encabezados general
include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Subcarpetas
add_subdirectory ("BD")
add_subdirectory ("Mesas")
add_subdirectory ("Cocina")
add_subdirectory ("Ventas")

# Programa principal (ejecutable)
add_executable (Restaurante "Restaurante.cpp")

# Módulos de los que depende el ejecutable
target_link_libraries(Restaurante PRIVATE Mesas)
target_link_libraries(Restaurante PRIVATE InterfazSQL)
target_link_libraries(Restaurante PRIVATE Ventas)
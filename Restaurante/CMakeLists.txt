# Carpeta de encabezados general
include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Subcarpetas
add_subdirectory ("BD")

# Programa principal (ejecutable)
add_executable (Restaurante "Restaurante.cpp")

# Módulo BD
target_link_libraries(Restaurante PRIVATE InterfazSQL)



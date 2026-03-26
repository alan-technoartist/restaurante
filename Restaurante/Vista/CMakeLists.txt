# Carpeta de encabezados general
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Programa principal (ejecutable)
add_library (Vista  "VistaCLI.cpp")

target_link_libraries(Vista PRIVATE Controlador)
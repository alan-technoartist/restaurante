# Carpeta de encabezados general
include_directories(${PROJECT_SOURCE_DIR}/Restaurante/Controlador/)

# Programa principal
add_library (Vista  "VistaCLI.cpp" "VistaCLI.hpp")

target_link_libraries(Vista PRIVATE Controlador)
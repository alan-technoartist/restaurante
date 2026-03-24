# Carpeta de encabezados general
#include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Programa principal (ejecutable)
add_library (Mesas  "Mesa.cpp")

target_link_libraries(Mesas PRIVATE InterfazSQL)
target_link_libraries(Mesas PRIVATE Cocina)

# CMakeList.txt : CMake project for Restaurante, include source and define
# project specific logic here.
#

# Carpeta de encabezados
include_directories(${PROJECT_SOURCE_DIR}/include/)

# Programa principal (ejecutable)
add_executable (Restaurante "Restaurante.cpp" "BD/InterfazSQL.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Restaurante PROPERTY CXX_STANDARD 20)
endif()

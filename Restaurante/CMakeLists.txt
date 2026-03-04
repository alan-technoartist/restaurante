# CMakeList.txt : CMake project for Restaurante, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Restaurante "Restaurante.cpp" "Restaurante.hpp" "BD/InterfazSQL.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Restaurante PROPERTY CXX_STANDARD 20)
endif()

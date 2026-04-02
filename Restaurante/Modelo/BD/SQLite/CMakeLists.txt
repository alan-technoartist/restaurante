include_directories(${PROJECT_SOURCE_DIR}/Restaurante/include/)

# Construcción del módulo InterfazSQL como biblioteca (no ejecutable)
add_library(AdaptadorSQLite "AdaptadorSQLite.cpp" "sqlite3/sqlite3.c")
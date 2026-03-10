# Directorio donde se instaló MySQL Connector C++
set(MYSQL_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.6")

# Nombre de la biblioteca de importación (.lib)
set(MYSQL_LIBRARY_DIR ${MYSQL_DIR}/lib64/vs14/)

# Construcción del módulo InterfazSQL como biblioteca (no ejecutable)
add_library(InterfazSQL "InterfazSQL.cpp" "Credenciales.cpp")

target_include_directories(InterfazSQL PUBLIC ${MYSQL_DIR}/include/)
target_link_libraries(InterfazSQL PUBLIC ${MYSQL_LIBRARY_DIR}/mysqlcppconn.lib)
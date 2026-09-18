cmake_minimum_required(VERSION 3.30)
project(CatalogoBiblioteca C)

set(CMAKE_C_STANDARD 11)

# Informa ao compilador para buscar os .h dentro da pasta Libraries
include_directories(Libraries)

# Lista de todos os arquivos .c que fazem parte do programa principal
add_executable(CatalogoBiblioteca
        src/main.c
        src/biblioteca.c
        src/tabelaHash.c
        Libraries/biblioteca.h
        Libraries/tabelaHash.h
)
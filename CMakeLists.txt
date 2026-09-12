cmake_minimum_required(VERSION 3.30)
project(CatalogoBiblioteca C)

set(CMAKE_C_STANDARD 11)

include_directories(Libraries)

add_executable(CatalogoBiblioteca src/main.c
        Libraries/Livro.h
        Libraries/TabelaHash.h
        src/Livro.c
        src/TabelaHash.c
        tests/Teste.c)

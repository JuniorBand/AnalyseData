cmake_minimum_required(VERSION 3.10)
project(MeuProjeto C)

set(CMAKE_C_STANDARD 17)

# Adiciona os arquivos-fonte
add_executable(MeuProjeto
    Main.c
    List.c
    Analysis.c
)

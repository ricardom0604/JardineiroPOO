cmake_minimum_required(VERSION 4.0)
project(TP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Ferramentas)
include_directories(Plantas)

add_executable(TP
        Ferramentas/Ferramenta.cpp
        Ferramentas/Ferramenta.h
        Ferramentas/FerramentaZ.cpp
        Ferramentas/FerramentaZ.h
        Ferramentas/PacoteAdubo.cpp
        Ferramentas/PacoteAdubo.h
        Ferramentas/Regador.cpp
        Ferramentas/Regador.h
        Ferramentas/TesouraPoda.cpp
        Ferramentas/TesouraPoda.h
        Plantas/Cacto.cpp
        Plantas/Cacto.h
        Plantas/ErvaDaninha.cpp
        Plantas/ErvaDaninha.h
        Plantas/Exotica.cpp
        Plantas/Exotica.h
        Plantas/Planta.cpp
        Plantas/Planta.h
        Plantas/Roseira.cpp
        Plantas/Roseira.h
        Comandos.cpp
        Comandos.h
        Jardim.cpp
        Jardim.h
        Jardineiro.cpp
        Jardineiro.h
        main.cpp
        Posicao.cpp
        Posicao.h
        Settings.h)

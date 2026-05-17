cmake_minimum_required(VERSION 3.16)

project(toy_soldier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(toy_soldier main.cpp
    soldier.h soldier.cpp
    squad.h squad.cpp
    calculationengine.h calculationengine.cpp
    isoldier.h
    marksman.h marksman.cpp
    medic.h medic.cpp
)

include(GNUInstallDirs)
install(TARGETS toy_soldier
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

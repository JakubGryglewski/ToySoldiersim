cmake_minimum_required(VERSION 3.16)

project(toy_soldier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. KONFIGURACJA ŚRODOWISKA Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# 2. BIBLIOTEKA LOGIKI (BACKEND)
add_library(toy_soldier_core
    isoldier.h
    soldier.h soldier.cpp
    marksman.h marksman.cpp
    medic.h medic.cpp
    squad.h squad.cpp
    simulationengine.h simulationengine.cpp
)

target_link_libraries(toy_soldier_core PRIVATE Qt6::Widgets)

# 3. GŁÓWNA INTERFEJSU (FRONTEND / GUI) (NA RAZIE SĄ TU TESTY)
add_executable(toy_soldier
    main.cpp
)

target_link_libraries(toy_soldier PRIVATE toy_soldier_core Qt6::Widgets)

# 4. INSTALACJA
include(GNUInstallDirs)
install(TARGETS toy_soldier
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

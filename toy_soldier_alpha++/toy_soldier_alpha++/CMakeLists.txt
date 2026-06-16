cmake_minimum_required(VERSION 3.16)

project(toy_soldier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. KONFIGURACJA ŚRODOWISKA Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

# Szukamy pakietów Widgets oraz wbudowanego Test (dla testów jednostkowych)
find_package(Qt6 COMPONENTS Widgets Test REQUIRED)

# 2. BIBLIOTEKA LOGIKI (BACKEND)
add_library(toy_soldier_core
    isoldier.h
    soldier.h soldier.cpp
    marksman.h marksman.cpp
    medic.h medic.cpp
    squad.h squad.cpp
    simulationengine.h simulationengine.cpp
    officer.h
    officer.cpp
)

target_link_libraries(toy_soldier_core PRIVATE Qt6::Widgets)

# 3. GŁÓWNA APLIKACJA (FRONTEND / GUI)
add_executable(toy_soldier
    main.cpp
    mainwindow.h
    mainwindow.cpp
    ui/mainwindow.ui
    ui/icons.qrc
    soldieritem.h soldieritem.cpp
)

target_link_libraries(toy_soldier PRIVATE toy_soldier_core Qt6::Widgets)

# 4. INSTALACJA
include(GNUInstallDirs)
install(TARGETS toy_soldier
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ——— BEZPIECZNE TESTY JEDNOSTKOWE (Wbudowane QtTest - bez internetu) ———
option(TOY_BUILD_TESTS "Build unit tests" OFF)

if(TOY_BUILD_TESTS)
    enable_testing()

    # Tworzymy osobny program testowy z Twojego pliku test_soldier.cpp
    add_executable(Toy_Tests
        test_soldier.cpp
        test_squad.cpp
        test_officer.cpp
        test_marksman.cpp
        test_engine.cpp
        test_medic.cpp
        test_movement.cpp

    )

    # Łączymy testy z logiką gry (toy_soldier_core) oraz modułem testowym Qt6::Test
    target_link_libraries(Toy_Tests PRIVATE toy_soldier_core Qt6::Test)
endif()
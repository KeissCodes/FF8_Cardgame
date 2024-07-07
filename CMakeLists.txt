cmake_minimum_required(VERSION 3.10)

# Projektname und Version
project(triple_triad VERSION 1.0 LANGUAGES CXX)

# Setze den Standard für C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Finde die benötigten Pakete
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(CAIRO REQUIRED cairo)

# Einbeziehungsverzeichnisse
include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${CAIRO_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

# Compiler Flags
add_compile_options(-Wall)

# Quelle-Dateien
set(SRCS
    main.cpp
    board.cpp
    card.cpp
    deck.cpp
    game.cpp
    player.cpp
    draw.cpp
    button.cpp
)

# Erzeuge das ausführbare Ziel
add_executable(${PROJECT_NAME} ${SRCS})

# Verlinke die Bibliotheken
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${CAIRO_LIBRARIES} -pthread)

# Clean Ziel
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

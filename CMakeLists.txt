cmake_minimum_required(VERSION 3.16)

project(HelloWorldWasm VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Add executable using qt_add_executable for better Qt6 WASM support
qt_add_executable(HelloWorldWasm
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

# Link Qt libraries
target_link_libraries(HelloWorldWasm
    Qt6::Core
    Qt6::Widgets
)

# WebAssembly specific settings
if(EMSCRIPTEN)
    set_target_properties(HelloWorldWasm PROPERTIES
        QT_WASM_PTHREAD_POOL_SIZE 4
    )
endif()

# Install targets
install(TARGETS HelloWorldWasm
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

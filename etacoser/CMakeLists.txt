cmake_minimum_required(VERSION 2.6)
project(etacoser)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(etacoser_SRCS etacoser.cpp main.cpp)

qt4_automoc(${etacoser_SRCS})
add_executable(etacoser ${etacoser_SRCS})
target_link_libraries(etacoser ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS etacoser RUNTIME DESTINATION bin)

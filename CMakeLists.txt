cmake_minimum_required(VERSION 3.0.0)
project(Obelisk VERSION 0.1.1 LANGUAGES CXX)

include(CTest)
enable_testing()

add_executable(Obelisk ${PROJECT_SOURCE_DIR}/src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(Boost 1.74.0 COMPONENTS program_options)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/config.h.in
    ${PROJECT_SOURCE_DIR}/src/config.h
)

include_directories(
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
    Obelisk
    Boost::program_options
)


include(CPack)

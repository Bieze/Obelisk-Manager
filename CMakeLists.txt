cmake_minimum_required(VERSION 3.0.0)
project(Obelisk VERSION 0.1.3 LANGUAGES CXX)

include(CTest)
enable_testing()

add_executable(Obelisk ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/SettingsLocation.hpp)

add_test(NAME ObeliskRun COMMAND Obelisk)

execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_custom_target(AlwaysCheckGit COMMAND ${CMAKE_COMMAND}
    -DRUN_CHECK_GIT_VERSION=1
    -Dpre_configure_dir=${pre_configure_dir}
    -Dpost_configure_file=${post_configure_dir}
    -DGIT_HASH_CACHE=${GIT_HASH_CACHE}
    -P ${CURRENT_LIST_DIR}/CheckGit.cmake
    BYPRODUCTS ${post_configure_file}
)

# If it's not MacOS then it's LINUX
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX) 
    # linux stuff here
    file(TO_CMAKE_PATH $ENV{HOME}/.config/obelisk-manager CONFIG_DIR)
    file(TO_CMAKE_PATH $ENV{HOME}/.config/obelisk-manager/MASTER_PA CONFIG_DIR)
elseif(WIN32)
    # windows stuf here
    file(TO_CMAKE_PATH $ENV{APPDATA}/obelisk-manager/ CONFIG_DIR)
    file(TO_CMAKE_PATH $ENV{APPDATA}/obelisk-manager/MASTER_PA AUTH_PA)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(Boost 1.71.0 COMPONENTS program_options filesystem)
find_package(SQLite3 3.39.2)


configure_file(
    ${PROJECT_SOURCE_DIR}/src/config.h.in
    ${PROJECT_SOURCE_DIR}/src/config.h
)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${SQLite3_INCLUDE_DIRS}
)

target_link_libraries(
    Obelisk
    ${Boost_LIBRARIES}
    ${SQLite3_LIBRARIES}
)


include(CPack)


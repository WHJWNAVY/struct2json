cmake_minimum_required (VERSION 3.3.2)

project (demo
    LANGUAGES C
    VERSION "1.0.0"
)

# set(CMAKE_CXX_STANDARD 11)
set(PROJECT_EXE_NAME tests2j)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_FLAGS "-DDEBUGS2J")

set(PROJECT_LD_PATH $ENV{PKG_LIBRARY_PATH})

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBS2JSON REQUIRED struct2json)
pkg_search_module(LIBCJSON REQUIRED cJSON)
pkg_check_modules(LIBS2JSON REQUIRED struct2json)
pkg_check_modules(LIBCJSON REQUIRED cJSON)

file(GLOB SPDATAPICKLE_SRCS ./*.c ./src/*.c)

link_directories(${PROJECT_LD_PATH})

add_executable(${PROJECT_EXE_NAME} ${SPDATAPICKLE_SRCS}) 

target_link_libraries(${PROJECT_EXE_NAME} ${LIBCJSON_LIBRARIES}
                                          ${LIBS2JSON_LIBRARIES})

target_include_directories(${PROJECT_EXE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}
                                                      ${PROJECT_SOURCE_DIR}/inc
                                                      ${PROJECT_SOURCE_DIR}/src
                                                      ${LIBCJSON_INCLUDE_DIRS}
                                                      ${LIBS2JSON_INCLUDE_DIRS})

install(TARGETS ${PROJECT_EXE_NAME} RUNTIME DESTINATION bin)

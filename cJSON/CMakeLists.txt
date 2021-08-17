cmake_minimum_required (VERSION 3.3.2)

project (cJSON
    LANGUAGES C
    VERSION "1.0.0"
)

# set(CMAKE_CXX_STANDARD 11)
set(PROJECT_LIB_NAME cJSON)
set(CMAKE_BUILD_TYPE Release)

configure_file(
  "${PROJECT_NAME}.pc.in"
  "${PROJECT_NAME}.pc"
  @ONLY)

find_package(PkgConfig REQUIRED)

file(GLOB PROJECT_LIB_SRCS *.c)

FILE(GLOB_RECURSE PROJECT_LIB_HEADERS *.h)

FILE(GLOB_RECURSE PROJECT_LIB_PKGCFG ./*.pc ./*/*.pc)

# add_library(${PROJECT_LIB_NAME} SHARED ${PROJECT_LIB_SRCS})
add_library(${PROJECT_LIB_NAME} STATIC ${PROJECT_LIB_SRCS})

target_include_directories(${PROJECT_LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

install(FILES ${PROJECT_LIB_HEADERS}
    DESTINATION include/${PROJECT_LIB_NAME}
)

install(TARGETS ${PROJECT_LIB_NAME}
    ARCHIVE DESTINATION lib # for static lib
    LIBRARY DESTINATION lib # for shared lib
)
        
install(FILES ${PROJECT_LIB_PKGCFG}
        DESTINATION lib/pkgconfig)

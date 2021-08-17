cmake_minimum_required (VERSION 3.3.2)

project (struct2json
    LANGUAGES C
    VERSION "1.0.0"
)

# set(CMAKE_CXX_STANDARD 11)
set(PROJECT_LIB_NAME struct2json)
set(CMAKE_BUILD_TYPE Release)

set(PROJECT_LD_PATH $ENV{PKG_LIBRARY_PATH})

configure_file(
  "${PROJECT_NAME}.pc.in"
  "${PROJECT_NAME}.pc"
  @ONLY)

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBCJSON REQUIRED cJSON)

file(GLOB PROJECT_LIB_SRCS ./src/*.c)

FILE(GLOB_RECURSE PROJECT_LIB_HEADERS ./inc/*.h)

FILE(GLOB_RECURSE PROJECT_LIB_PKGCFG ./*.pc ./*/*.pc)

link_directories(${PROJECT_LD_PATH})

# add_library(${PROJECT_LIB_NAME} SHARED ${PROJECT_LIB_SRCS})
add_library(${PROJECT_LIB_NAME} STATIC ${PROJECT_LIB_SRCS})

target_link_libraries(${PROJECT_LIB_NAME} ${LIBCJSON_LIBRARIES})

target_include_directories(${PROJECT_LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}
                                                      ${LIBCJSON_INCLUDE_DIRS})

install(FILES ${PROJECT_LIB_HEADERS}
    DESTINATION include/${PROJECT_LIB_NAME}
)

install(TARGETS ${PROJECT_LIB_NAME}
    ARCHIVE DESTINATION lib # for static lib
    LIBRARY DESTINATION lib # for shared lib
)
        
install(FILES ${PROJECT_LIB_PKGCFG}
        DESTINATION lib/pkgconfig)

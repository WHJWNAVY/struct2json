#!/bin/sh

TOP_DIR=$(pwd)
INSTALL_PREFIX=${TOP_DIR}/install
INSTALL_PKGEXE_PATH=${INSTALL_PREFIX}/bin
INSTALL_PKGINC_PATH=${INSTALL_PREFIX}/include
INSTALL_PKGLIB_PATH=${INSTALL_PREFIX}/lib
INSTALL_PKGCFG_PATH=${INSTALL_PKGLIB_PATH}/pkgconfig
export PKG_CONFIG_PATH=${INSTALL_PKGCFG_PATH}:${PKG_CONFIG_PATH}
export PKG_LIBRARY_PATH=${INSTALL_PKGLIB_PATH}

clean_target() {
    echo "Clean target begin ..."
    [[ -d ${INSTALL_PREFIX} ]] && rm -rf ${INSTALL_PREFIX}
    mkdir ${INSTALL_PREFIX}
    echo "Clean target end ..."
}

build_prepare() {
    target=$1
    echo "Target [${target}] prepare begin ..."
    if [[ -f ${target}/build_prepare.sh ]]; then
        echo "Target [${target}] prepare ..."
        cd ${target} && ./build_prepare.sh
    fi
    echo "Target [${target}] prepare end ..."
}

build_target() {
    target=${TOP_DIR}/$1

    echo "Build [${target}] begin ..."
    build_prepare ${target}

    if [[ -f ${target}/CMakeLists.txt ]]; then
        echo "Build [${target}] ..."
        cd ${target}
        [[ -d build ]] && rm -rf build
        [[ ! -d build ]] && mkdir build
        cd build
        cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} ../
        make && make install #&& cd ..
        #cd ..
    fi
    echo "Build [${target}] end ..."
}

run_target() {
    target=$1
    echo "Run [${target}] begin ..."
    if [[ -f ${INSTALL_PKGEXE_PATH}/${target} ]]; then
        cd ${INSTALL_PKGEXE_PATH} && ./${target}
    fi
    echo "Run [${target}] end ..."
}

clean_target
build_target cJSON
build_target struct2json
build_target demo
run_target tests2j
#!/bin/sh

generate() {
    ./generate_struct_defination.py && ./generate_s2j_code.py
}

build() {
    gcc ../cJSON/cJSON.c ../struct2json/src/*.c ./*.c -I ../cJSON/ -I ../struct2json/inc/ -lm -DDEBUGS2J  -g -o tests2j
}

run() {
    ./tests2j
}

generate #&& build && run
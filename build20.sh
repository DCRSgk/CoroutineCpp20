#!/bin/bash

declare -a PROJECTS=(
"cpp20"
)

for proj in ${PROJECTS[@]}
do
    mkdir -p $proj/build
    cd $proj/build
    cmake ..
    make -j6
    cd -
done



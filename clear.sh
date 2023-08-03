#!/bin/bash

declare -a PROJECTS=(
"cpp20"
)

for proj in ${PROJECTS[@]}
do
    rm -r $proj/build
    #make clean
    #cd -
done
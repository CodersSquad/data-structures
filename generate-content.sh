#!/bin/bash

sections=(data-abstraction)

rm -rf public

for section in "${sections[@]}"; do
    pushd $section ;
    make
    popd
    mkdir -p public/
    mv $section/public/ public/$section
    cp -r $section/images public/$section
    cp -r $section/src public/$section
done

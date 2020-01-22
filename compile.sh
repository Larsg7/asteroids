#!/usr/bin/env bash

mkdir build
cd build || exit

cmake ..
make

cd ..
mv build/asteroids .
rm -rf build
#!/bin/bash


cmake -B build
cd build
make
./area_test

echo 500_000:
./area < ../polygons/polygon-500_000.txt
echo; echo

echo 1_000_000:
./area < ../polygons/polygon-1_000_000.txt
echo; echo

echo 5_000_000:
./area < ../polygons/polygon-5_000_000.txt
echo; echo

echo 10_000_000:
./area < ../polygons/polygon-10_000_000.txt
echo; echo
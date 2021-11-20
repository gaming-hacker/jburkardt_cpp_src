#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sphere_stereograph_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sphere_stereograph_test.o /$HOME/libcpp/sphere_stereograph.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_stereograph_test.o
#
mv a.out sphere_stereograph_test
./sphere_stereograph_test > sphere_stereograph_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_stereograph_test
#
echo "Normal end of execution."

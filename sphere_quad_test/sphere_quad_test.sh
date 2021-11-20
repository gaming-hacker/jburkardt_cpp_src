#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sphere_quad_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sphere_quad_test.o /$HOME/libcpp/sphere_quad.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_quad_test.o
#
mv a.out sphere_quad_test
./sphere_quad_test > sphere_quad_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_quad_test
#
echo "Normal end of execution."

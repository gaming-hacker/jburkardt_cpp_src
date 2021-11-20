#! /bin/bash
#
g++ -c -Wall -I/$HOME/include gmsh_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gmsh_io_test.o /$HOME/libcpp/gmsh_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gmsh_io_test.o
#
mv a.out gmsh_io_test
./gmsh_io_test > gmsh_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gmsh_io_test
#
echo "Normal end of execution."

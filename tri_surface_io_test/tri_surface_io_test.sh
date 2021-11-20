#! /bin/bash
#
g++ -c -Wall -I/$HOME/include tri_surface_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tri_surface_io_test.o /$HOME/libcpp/tri_surface_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tri_surface_io_test.o
#
mv a.out tri_surface_io_test
./tri_surface_io_test > tri_surface_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tri_surface_io_test
#
echo "Normal end of execution."

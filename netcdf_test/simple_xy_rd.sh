#! /bin/bash
#
g++ -c -Wall -I$HOME/include simple_xy_rd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simple_xy_rd.o -L$HOME/lib -lnetcdf_c++ -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simple_xy_rd.o
#
mv a.out simple_xy_rd
./simple_xy_rd > simple_xy_rd.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simple_xy_rd
#
echo "Normal end of execution."

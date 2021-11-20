#! /bin/bash
#
g++ -c -Wall -I$HOME/include simple_xy_wr.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simple_xy_wr.o -L$HOME/lib -lnetcdf_c++ -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simple_xy_wr.o
#
mv a.out simple_xy_wr
./simple_xy_wr > simple_xy_wr.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simple_xy_wr
#
echo "Normal end of execution."

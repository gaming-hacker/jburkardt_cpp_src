#! /bin/bash
#
g++ -c -Wall -I$HOME/include pres_temp_4D_rd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pres_temp_4D_rd.o -L$HOME/lib -lnetcdf_c++ -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pres_temp_4D_rd.o
#
mv a.out pres_temp_4D_rd
./pres_temp_4D_rd > pres_temp_4D_rd.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pres_temp_4D_rd
#
echo "Normal end of execution."

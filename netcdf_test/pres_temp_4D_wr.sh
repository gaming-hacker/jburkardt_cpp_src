#! /bin/bash
#
g++ -c -Wall -I$HOME/include pres_temp_4D_wr.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pres_temp_4D_wr.o -L$HOME/lib -lnetcdf_c++ -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pres_temp_4D_wr.o
#
mv a.out pres_temp_4D_wr
./pres_temp_4D_wr > pres_temp_4D_wr.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pres_temp_4D_wr
#
echo "Normal end of execution."

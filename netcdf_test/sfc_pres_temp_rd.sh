#! /bin/bash
#
g++ -c -Wall -I$HOME/include sfc_pres_temp_wr.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sfc_pres_temp_wr.o -L$HOME/lib -lnetcdf_c++ -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sfc_pres_temp_wr.o
#
mv a.out sfc_pres_temp_wr
./sfc_pres_temp_wr > sfc_pres_temp_wr.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sfc_pres_temp_wr
#
echo "Normal end of execution."

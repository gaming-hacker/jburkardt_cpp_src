#! /bin/bash
#
g++ -c -Wall histogram_data_2d_sample.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ histogram_data_2d_sample.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm histogram_data_2d_sample.o
#
mv a.out ~/bincpp/histogram_data_2d_sample
#
echo "Normal end of execution."

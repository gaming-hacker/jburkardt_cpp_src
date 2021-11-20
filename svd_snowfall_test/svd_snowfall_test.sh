#! /bin/bash
#
g++ -c -Wall -I/$HOME/include svd_snowfall_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ svd_snowfall_test.o /$HOME/libcpp/svd_snowfall.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm svd_snowfall_test.o
#
mv a.out svd_snowfall_test
./svd_snowfall_test > svd_snowfall_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm svd_snowfall_test
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall -I/$HOME/include st_to_ccs_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o st_to_ccs_test st_to_ccs_test.o /$HOME/libcpp/st_to_ccs.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm st_to_ccs_test.o
#
./st_to_ccs_test > st_to_ccs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm st_to_ccs_test
#
echo "Normal end of execution."

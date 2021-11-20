#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa076_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa076_test.o /$HOME/libcpp/asa076.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa076_test.o
#
mv a.out asa076_test
./asa076_test > asa076_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa076_test
#
echo "Normal end of execution."

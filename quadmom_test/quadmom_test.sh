#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quadmom_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quadmom_test.o /$HOME/libcpp/quadmom.o  /$HOME/libcpp/toms655.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadmom_test.o
#
mv a.out quadmom_test
./quadmom_test > quadmom_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadmom_test
#
echo "Normal end of execution."

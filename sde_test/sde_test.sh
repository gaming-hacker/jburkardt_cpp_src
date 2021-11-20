#! /bin/bash
#
g++ -c -Wall -I $HOME/include sde_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sde_test.o /$HOME/libcpp/sde.o /$HOME/libcpp/qr_solve.o /$HOME/libcpp/r8lib.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sde_test.o
#
mv a.out sde_test
./sde_test > sde_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sde_test
#
echo "Normal end of execution."

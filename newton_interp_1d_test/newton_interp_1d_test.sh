#! /bin/bash
#
g++ -c -Wall -I/$HOME/include newton_interp_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o newton_interp_1d_test newton_interp_1d_test.o /$HOME/libcpp/newton_interp_1d.o  /$HOME/libcpp/test_interp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm newton_interp_1d_test.o
#
./newton_interp_1d_test > newton_interp_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm newton_interp_1d_test
#
echo "Normal end of execution."

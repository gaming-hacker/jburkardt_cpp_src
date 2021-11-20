#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cube_exactness_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o cube_exactness_test cube_exactness_test.o /$HOME/libcpp/cube_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cube_exactness_test.o
#
./cube_exactness_test > cube_exactness_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cube_exactness_test
#
echo "Normal end of execution."

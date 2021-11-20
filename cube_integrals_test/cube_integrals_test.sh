#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cube_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cube_integrals_test.o /$HOME/libcpp/cube_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cube_integrals_test.o
#
mv a.out cube_integrals_test
./cube_integrals_test > cube_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cube_integrals_test
#
echo "Normal end of execution."

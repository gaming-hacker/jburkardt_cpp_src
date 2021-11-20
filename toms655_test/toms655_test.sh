#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms655_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms655_test.o /$HOME/libcpp/toms655.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms655_test.o
#
mv a.out toms655_test
./toms655_test > toms655_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms655_test
#
echo "Normal end of execution."

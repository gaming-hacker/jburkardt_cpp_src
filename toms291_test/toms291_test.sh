#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms291_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms291_test.o /$HOME/libcpp/toms291.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms291_test.o
#
mv a.out toms291_test
./toms291_test > toms291_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms291_test
#
echo "Normal end of execution."

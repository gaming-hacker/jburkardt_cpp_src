#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms179_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms179_test.o /$HOME/libcpp/toms179.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms179_test.o
#
mv a.out toms179_test
./toms179_test > toms179_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms179_test
#
echo "Normal end of execution."

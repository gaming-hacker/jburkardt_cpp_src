#! /bin/bash
#
g++ -c -I/$HOME/include toms577_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o toms577_test toms577_test.o /$HOME/libcpp/toms577.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms577_test.o
#
./toms577_test > toms577_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms577_test
#
echo "Normal end of execution."

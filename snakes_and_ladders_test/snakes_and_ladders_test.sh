#! /bin/bash
#
g++ -c -Wall -I/$HOME/include snakes_and_ladders_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ snakes_and_ladders_test.o /$HOME/libcpp/snakes_and_ladders.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm snakes_and_ladders_test.o
#
mv a.out snakes_and_ladders_test
./snakes_and_ladders_test > snakes_and_ladders_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm snakes_and_ladders_test
#
echo "Normal end of execution."

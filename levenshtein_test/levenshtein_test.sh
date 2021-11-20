#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall levenshtein_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ levenshtein_test.o /$HOME/libcpp/levenshtein.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm levenshtein_test.o
#
mv a.out levenshtein_test
./levenshtein_test > levenshtein_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm levenshtein_test
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall -I/$HOME/include set_theory_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ set_theory_test.o /$HOME/libcpp/set_theory.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm set_theory_test.o
#
mv a.out set_theory_test
./set_theory_test > set_theory_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm set_theory_test
#
echo "Normal end of execution."

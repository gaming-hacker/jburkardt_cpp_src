#! /bin/bash
#
g++ -c -Wall -I/$HOME/include combo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ combo_test.o /$HOME/libcpp/combo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm combo_test.o
#
mv a.out combo_test
./combo_test > combo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm combo_test
#
echo "Normal end of execution."

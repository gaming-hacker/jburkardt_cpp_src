#! /bin/bash
#
g++ -c -Wall -I/$HOME/include power_method_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ power_method_test.o /$HOME/libcpp/power_method.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm power_method_test.o
#
mv a.out power_method_test
./power_method_test > power_method_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm power_method_test
#
echo "Normal end of execution."

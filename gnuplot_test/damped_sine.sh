#! /bin/bash
#
g++ -c -Wall damped_sine.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ damped_sine.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm damped_sine.o
mv a.out ~/bincpp/damped_sine
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall timer_clock.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ timer_clock.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out timer_clock
#
./timer_clock > timer_clock.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm timer_clock
rm timer_clock.o
#
echo "Normal end of execution."

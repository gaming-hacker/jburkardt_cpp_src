#! /bin/bash
#
g++ -c -Wall -std=c++11 timer_chrono.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ timer_chrono.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm timer_chrono.o
#
mv a.out timer_chrono
#
./timer_chrono > timer_chrono.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timer_chrono
#
echo "Normal end of execution."

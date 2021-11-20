#! /bin/bash
#
g++ -c -Wall timer_time.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ timer_time.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out timer_time
#
./timer_time > timer_time.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm timer_time
rm timer_time.o
#
echo "Normal end of execution."

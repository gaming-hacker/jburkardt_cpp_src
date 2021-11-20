#! /bin/bash
#
g++ -c -Wall fd1d_burgers_leap.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd1d_burgers_leap.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_burgers_leap.o
#
mv a.out ~/bincpp/fd1d_burgers_leap
#
echo "Normal end of execution."

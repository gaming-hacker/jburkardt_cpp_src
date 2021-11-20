#! /bin/bash
#
g++ -c -Wall hello.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hello.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hello.o
#
mv a.out ~/bincpp/hello
#
echo "Normal end of execution."

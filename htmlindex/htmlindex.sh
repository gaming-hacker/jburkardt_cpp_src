#! /bin/bash
#
g++ -c -Wall htmlindex.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o htmlindex htmlindex.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv htmlindex ~/bincpp/htmlindex
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall -I $HOME/include memory_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ memory_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm memory_test.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/memory_test
#
echo "Normal end of execution."

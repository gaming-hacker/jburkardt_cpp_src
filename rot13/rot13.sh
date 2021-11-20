#! /bin/bash
#
g++ -c -Wall rot13.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rot13.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rot13.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/rot13
#
echo "Normal end of execution."

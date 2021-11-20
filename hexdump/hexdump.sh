#! /bin/bash
#
g++ -c -Wall hexdump.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hexdump.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hexdump.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/hexdump
#
echo "Normal end of execution."

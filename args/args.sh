#! /bin/bash
#
g++ -c -Wall args.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ args.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm args.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/args
#
echo "Normal end of execution."

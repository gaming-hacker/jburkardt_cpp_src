#! /bin/bash
#
g++ -c -Wall gfplys.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gfplys.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gfplys.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gfplys
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall gfarit.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gfarit.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gfarit.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gfarit
#
echo "Normal end of execution."

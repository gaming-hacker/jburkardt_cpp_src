#! /bin/bash
#
g++ -c -Wall shallow_water_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ shallow_water_1d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm shallow_water_1d.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/shallow_water_1d
#
echo "Normal end of execution."

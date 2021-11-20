#! /bin/bash
#
g++ -c -Wall fem2d_heat_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ ~/libcpp/fem2d_heat.o fem2d_heat_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fem2d_heat_test.o
#
chmod ugo+x a.out
mv a.out fem2d_heat_test
./fem2d_heat_test square > fem2d_heat_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem2d_heat_test
#
echo "Normal end of execution."

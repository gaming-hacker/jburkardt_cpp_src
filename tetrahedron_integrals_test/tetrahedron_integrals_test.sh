#! /bin/bash
#
g++ -c -Wall -I/$HOME/include tetrahedron_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tetrahedron_integrals_test.o /$HOME/libcpp/tetrahedron_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tetrahedron_integrals_test.o
#
mv a.out tetrahedron_integrals_test
./tetrahedron_integrals_test > tetrahedron_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tetrahedron_integrals_test
#
echo "Normal end of execution."

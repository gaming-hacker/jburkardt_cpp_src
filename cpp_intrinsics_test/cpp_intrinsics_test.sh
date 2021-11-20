#! /bin/bash
#
g++ -c -Wall cpp_intrinsics_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cpp_intrinsics_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cpp_intrinsics_test.o
#
mv a.out cpp_intrinsics_test
./cpp_intrinsics_test > cpp_intrinsics_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cpp_intrinsics_test
#
echo "Normal end of execution."

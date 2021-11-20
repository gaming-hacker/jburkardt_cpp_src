#! /bin/bash
#
g++ -c -Wall -I$HOME/include fem2d_bvp_serene_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem2d_bvp_serene_test.o ~/libcpp/fem2d_bvp_serene.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fem2d_bvp_serene_test.o
#
mv a.out fem2d_bvp_serene_test
./fem2d_bvp_serene_test > fem2d_bvp_serene_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem2d_bvp_serene_test
#
echo "Normal end of execution."

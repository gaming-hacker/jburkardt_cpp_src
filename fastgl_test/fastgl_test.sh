#! /bin/bash
#
g++ -c -Wall -I/$HOME/include fastgl_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fastgl_test.o /$HOME/libcpp/fastgl.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fastgl_test.o
#
mv a.out fastgl_test
./fastgl_test > fastgl_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fastgl_test
#
echo "Normal end of execution."

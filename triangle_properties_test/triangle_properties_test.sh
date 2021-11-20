#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_properties_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_properties_test.o /$HOME/libcpp/triangle_properties.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_properties_test.o
#
mv a.out triangle_properties_test
./triangle_properties_test > triangle_properties_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_properties_test
#
echo "Normal end of execution."

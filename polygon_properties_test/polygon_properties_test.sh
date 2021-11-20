#! /bin/bash
#
g++ -c -Wall -I/$HOME/include polygon_properties_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ polygon_properties_test.o /$HOME/libcpp/polygon_properties.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polygon_properties_test.o
#
mv a.out polygon_properties_test
./polygon_properties_test > polygon_properties_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polygon_properties_test
#
echo "Normal end of execution."

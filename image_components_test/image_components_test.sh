#! /bin/bash
#
g++ -c -Wall -I/$HOME/include image_components_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ image_components_test.o /$HOME/libcpp/image_components.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm image_components_test.o
#
mv a.out image_components_test
./image_components_test > image_components_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm image_components_test
#
echo "Normal end of execution."

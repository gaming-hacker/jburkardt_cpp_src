#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cosine_transform_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cosine_transform_test.o /$HOME/libcpp/cosine_transform.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cosine_transform_test.o
#
mv a.out cosine_transform_test
./cosine_transform_test > cosine_transform_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cosine_transform_test
#
echo "Normal end of execution."

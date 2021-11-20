#! /bin/bash
#
g++ -c -Wall -I/$HOME/include circle_segment_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ circle_segment_test.o /$HOME/libcpp/circle_segment.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_segment_test.o
#
mv a.out circle_segment_test
./circle_segment_test > circle_segment_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_segment_test
#
echo "Normal end of execution."

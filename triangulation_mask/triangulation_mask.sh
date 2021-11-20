#! /bin/bash
#
g++ -c -Wall triangulation_mask.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangulation_mask.o ~/libcpp/
#
echo "Normal end of execution."

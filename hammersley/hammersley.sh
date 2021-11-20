#! /bin/bash
#
cp hammersley.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hammersley.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hammersley.o ~/libcpp/hammersley.o
#
echo "Normal end of execution."

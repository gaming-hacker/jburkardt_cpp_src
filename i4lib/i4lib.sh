#! /bin/bash
#
cp i4lib.hpp /$HOME/include
#
g++ -c -I /$HOME/include -Wall i4lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv i4lib.o ~/libcpp/i4lib.o
#
echo "Normal end of execution."

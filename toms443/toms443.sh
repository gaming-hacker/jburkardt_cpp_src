#! /bin/bash
#
cp toms443.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms443.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms443.o ~/libcpp/toms443.o
#
echo "Normal end of execution."

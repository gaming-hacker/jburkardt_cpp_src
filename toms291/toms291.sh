#! /bin/bash
#
cp toms291.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms291.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms291.o ~/libcpp/toms291.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp stla_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include stla_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stla_io.o ~/libcpp/stla_io.o
#
echo "Normal end of execution."

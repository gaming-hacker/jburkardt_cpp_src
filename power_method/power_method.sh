#! /bin/bash
#
cp power_method.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include power_method.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv power_method.o ~/libcpp/power_method.o
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall fem2d_heat.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem2d_heat.o ~/libcpp
#
echo "Normal end of execution."

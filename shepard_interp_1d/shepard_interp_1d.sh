#! /bin/bash
#
cp shepard_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include shepard_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv shepard_interp_1d.o ~/libcpp/shepard_interp_1d.o
#
echo "Normal end of execution."

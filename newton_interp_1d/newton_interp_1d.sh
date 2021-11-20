#! /bin/bash
#
cp newton_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include newton_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv newton_interp_1d.o ~/libcpp/newton_interp_1d.o
#
echo "Normal end of execution."

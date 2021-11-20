#! /bin/bash
#
cp rbf_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include rbf_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_1d.o ~/libcpp/rbf_interp_1d.o
#
echo "Normal end of execution."

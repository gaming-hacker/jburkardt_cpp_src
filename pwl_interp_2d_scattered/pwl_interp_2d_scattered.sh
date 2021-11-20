#! /bin/bash
#
cp pwl_interp_2d_scattered.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pwl_interp_2d_scattered.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_interp_2d_scattered.o ~/libcpp/pwl_interp_2d_scattered.o
#
echo "Normal end of execution."

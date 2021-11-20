#! /bin/bash
#
cp svd_snowfall.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include svd_snowfall.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv svd_snowfall.o ~/libcpp/svd_snowfall.o
#
echo "Normal end of execution."

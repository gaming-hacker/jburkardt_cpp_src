#! /bin/bash
#
cp chebyshev_series.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include chebyshev_series.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_series.o ~/libcpp/chebyshev_series.o
#
echo "Normal end of execution."

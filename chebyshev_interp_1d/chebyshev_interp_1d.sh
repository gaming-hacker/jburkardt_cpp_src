#! /bin/bash
#
cp chebyshev_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include chebyshev_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_interp_1d.o ~/libcpp/chebyshev_interp_1d.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp stiff_ode.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include stiff_ode.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stiff_ode.o ~/libcpp/stiff_ode.o
#
echo "Normal end of execution."

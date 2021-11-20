#! /bin/bash
#
cp bisection_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include bisection_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bisection_rc.o ~/libcpp/bisection_rc.o
#
echo "Normal end of execution."

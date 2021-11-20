#! /bin/bash
#
cp local_min_rc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include local_min_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv local_min_rc.o ~/libcpp/local_min_rc.o
#
echo "Normal end of execution."

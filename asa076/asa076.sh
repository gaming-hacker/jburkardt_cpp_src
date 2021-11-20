#! /bin/bash
#
cp asa076.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa076.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa076.o ~/libcpp/asa076.o
#
echo "Normal end of execution."

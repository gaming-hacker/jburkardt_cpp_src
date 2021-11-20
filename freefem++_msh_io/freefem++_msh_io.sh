#! /bin/bash
#
cp freefem++_msh_io.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include freefem++_msh_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv freefem++_msh_io.o ~/libcpp/freefem++_msh_io.o
#
echo "Normal end of execution."

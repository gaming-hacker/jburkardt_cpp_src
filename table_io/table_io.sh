#! /bin/bash
#
cp table_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include table_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv table_io.o ~/libcpp/table_io.o
#
echo "Normal end of execution."

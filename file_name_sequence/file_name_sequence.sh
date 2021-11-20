#! /bin/bash
#
cp file_name_sequence.hpp /$HOME/include
#
g++ -c -Wall file_name_sequence.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv file_name_sequence.o ~/libcpp/file_name_sequence.o
#
echo "Normal end of execution."

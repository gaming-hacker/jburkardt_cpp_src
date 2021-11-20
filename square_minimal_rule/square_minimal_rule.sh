#! /bin/bash
#
cp square_minimal_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include square_minimal_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_minimal_rule.o ~/libcpp/square_minimal_rule.o
#
echo "Normal end of execution."

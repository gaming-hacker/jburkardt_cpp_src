#! /bin/bash
#
cp square_symq_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include square_symq_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_symq_rule.o ~/libcpp/square_symq_rule.o
#
echo "Normal end of execution."

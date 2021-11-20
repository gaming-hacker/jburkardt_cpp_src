#! /bin/bash
#
cp ornstein_uhlenbeck.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ornstein_uhlenbeck.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ornstein_uhlenbeck.o ~/libcpp/ornstein_uhlenbeck.o
#
echo "Normal end of execution."

#! /bin/bash
#
cp test_opt_con.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_opt_con.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_opt_con.o ~/libcpp/test_opt_con.o
#
echo "Normal end of execution."

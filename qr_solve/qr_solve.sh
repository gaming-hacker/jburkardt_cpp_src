#! /bin/bash
#
cp qr_solve.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include qr_solve.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv qr_solve.o ~/libcpp/qr_solve.o
#
echo "Normal end of execution."

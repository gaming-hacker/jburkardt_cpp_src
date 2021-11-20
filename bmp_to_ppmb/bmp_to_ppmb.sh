#! /bin/bash
#
g++ -c -Wall -I $HOME/include bmp_to_ppmb.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ bmp_to_ppmb.o ~/libcpp/bmp_io.o ~/libcpp/ppmb_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bmp_to_ppmb.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/bmp_to_ppmb
#
echo "Normal end of execution."

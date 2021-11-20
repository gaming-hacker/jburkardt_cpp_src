#! /bin/bash
#
g++ -c -Wall ccvt_box.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ccvt_box.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ccvt_box.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/ccvt_box
#
echo "Normal end of execution."

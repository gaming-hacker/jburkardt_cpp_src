#! /bin/bash
#
cp pdflib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pdflib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pdflib.o ~/libcpp/pdflib.o
#
echo "Normal end of execution."

#! /bin/bash
#
g++ -c -Wall fem_to_xml.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem_to_xml.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_to_xml.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem_to_xml
#
echo "Normal end of execution."

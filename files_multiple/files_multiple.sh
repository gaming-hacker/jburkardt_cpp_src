#! /bin/bash
#
g++ -c -Wall files_multiple.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ files_multiple.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm files_multiple.o
#
mv a.out $HOME/bincpp/files_multiple
#
echo "Normal end of execution."

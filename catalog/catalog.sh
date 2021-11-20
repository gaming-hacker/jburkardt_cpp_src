#! /bin/bash
#
g++ -c -Wall catalog.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o catalog catalog.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm catalog.o
#
chmod ugo+x catalog
mv catalog ~/bin/catalog
#
echo "Normal end of execution."

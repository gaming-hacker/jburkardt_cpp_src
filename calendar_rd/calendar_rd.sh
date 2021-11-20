#! /bin/bash
#
g++ -c -Wall -I /$HOME/include calendar_rd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ calendar_rd.o -lm 
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm calendar_rd.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/calendar_rd
#
echo "Normal end of execution."

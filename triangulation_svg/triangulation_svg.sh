#! /bin/bash
#
g++ -c -Wall triangulation_svg.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_svg.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_svg.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_svg
#
echo "Normal end of execution."

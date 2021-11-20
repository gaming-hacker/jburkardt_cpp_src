#! /bin/bash
#
g++ -c -Wall fem3d_project.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem3d_project.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem3d_project.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem3d_project
#
echo "Normal end of execution."

#! /bin/bash
#
#  This script is designed to compile and run C++ DISLIN examples on my LINUX system.
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
$DISLIN/bin/cpplink -c ex07
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
./ex07 > ex07_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex07
#
echo "Normal end of execution."
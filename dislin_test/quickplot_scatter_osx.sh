#! /bin/bash
#
#  This script is designed to compile and run C++ DISLIN examples on my OSX system.
#
export DISLIN=/usr/local/dislin
export DYLD_LIBRARY_PATH=$DISLIN:$DYLD_LIBRARY_PATH
#
$DISLIN/bin/cpplink -c quickplot_scatter
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
./quickplot_scatter > quickplot_scatter_osx_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quickplot_scatter
#
echo "Normal end of execution."

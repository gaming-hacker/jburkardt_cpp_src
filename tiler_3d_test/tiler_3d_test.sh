#! /bin/bash
#
$HOME/bincpp/tiler_3d > tiler_3d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

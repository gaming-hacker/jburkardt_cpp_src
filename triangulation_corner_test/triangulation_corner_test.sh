#! /bin/bash
#
$HOME/bincpp/triangulation_corner p11 > triangulation_corner_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

#! /bin/bash
#
$HOME/bincpp/star_discrepancy 0.001 10 halton_02_00010.txt > star_discrepancy_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

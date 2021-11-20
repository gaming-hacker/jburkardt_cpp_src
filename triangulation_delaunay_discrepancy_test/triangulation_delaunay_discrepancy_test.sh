#! /bin/bash
#
$HOME/bincpp/triangulation_delaunay_discrepancy ten3 > triangulation_delaunay_discrepancy_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
$HOME/bincpp/triangulation_delaunay_discrepancy ted3 >> triangulation_delaunay_discrepancy_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

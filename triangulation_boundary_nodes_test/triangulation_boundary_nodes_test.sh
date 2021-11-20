#! /bin/bash
#
$HOME/bincpp/triangulation_boundary_nodes elbow > triangulation_boundary_nodes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
$HOME/bincpp/triangulation_boundary_nodes lake >> triangulation_boundary_nodes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

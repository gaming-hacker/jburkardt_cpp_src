#! /bin/bash
#
$HOME/bincpp/fem_to_gmsh < input.txt > fem_to_gmsh_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

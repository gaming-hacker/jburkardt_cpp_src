#! /bin/bash
#
cp r4x4_t3_elements.txt fem_elements.txt
cp r4x4_t3_nodes.txt fem_nodes.txt
#
$HOME/bincpp/fem2d_project r8x8_t3 fem > fem2d_project_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

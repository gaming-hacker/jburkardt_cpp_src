#! /bin/bash
#
$HOME/bincpp/tet_mesh_rcm cube4 > tet_mesh_rcm_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

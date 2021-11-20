#! /bin/bash
#
$HOME/bincpp/tet_mesh_tet_neighbors cube > tet_mesh_tet_neighbors_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

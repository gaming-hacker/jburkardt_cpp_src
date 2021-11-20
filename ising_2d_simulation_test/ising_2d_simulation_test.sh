#! /bin/bash
#
$HOME/bincpp/ising_2d_simulation > ising_2d_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

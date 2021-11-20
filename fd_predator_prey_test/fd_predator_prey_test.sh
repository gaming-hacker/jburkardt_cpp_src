#! /bin/bash
#
$HOME/bincpp/fd_predator_prey 100 > trf_100.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/bincpp/fd_predator_prey 1000 > trf_1000.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
$HOME/bincpp/fd_predator_prey 10000 > trf_10000.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

#! /bin/bash
#
$HOME/bincpp/linpack_bench > linpack_bench_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

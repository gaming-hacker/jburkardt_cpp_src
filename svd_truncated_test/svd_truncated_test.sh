#! /bin/bash
#
$HOME/bincpp/svd_truncated > svd_truncated_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

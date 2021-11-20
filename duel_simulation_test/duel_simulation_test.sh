#! /bin/bash
#
$HOME/bincpp/duel_simulation < input > duel_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

#! /bin/bash
#
$HOME/bincpp/fair_dice_simulation < input > fair_dice_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

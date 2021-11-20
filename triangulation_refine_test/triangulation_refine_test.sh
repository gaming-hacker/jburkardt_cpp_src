#! /bin/bash
#
$HOME/bincpp/triangulation_refine box3 >    triangulation_refine_test.txt
$HOME/bincpp/triangulation_refine house6 >> triangulation_refine_test.txt
$HOME/bincpp/triangulation_refine irreg6 >> triangulation_refine_test.txt
#
echo "Normal end of execution."

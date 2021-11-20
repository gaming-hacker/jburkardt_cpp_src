#! /bin/bash
#
g++ /$HOME/libcpp/test_partial_digest.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out test_partial_digest_test
./test_partial_digest_test > test_partial_digest_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_partial_digest_test
#
echo "Normal end of execution."

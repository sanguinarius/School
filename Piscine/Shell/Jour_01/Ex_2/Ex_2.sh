#!/bin/bash

mkdir test0
mkdir test2
touch -t 201210040000 test0
touch -t 201210040000 test2
touch -t 201210040000 test1
touch -t 201210040000 test3
touch -t 201210040000 test4
touch -t 201210040000 test5
touch -t 201210040000 testJour01
echo "tot" > test1
echo "a" > test4
echo "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" > testJour01
echo -n "a" > test3
echo -n "a" > test5
ln -s testJour01 test6
ln test3 .toto
ln test5 .toto2
touch -t 201210040000 test0
touch -t 201210040000 test2
touch -t 201210040000 test1
touch -t 201210040000 test3
touch -t 201210040000 test4
touch -t 201210040000 test5
touch -t 201210040000 testJour01
touch -mht 201210040000.00 test6
chmod 715 test0
chmod 414 test1
chmod 504 test2
chmod 404 test3
chmod 020 test4
chmod 404 test5
chmod 615 testJour01
chmod -h 777 test6

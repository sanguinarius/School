#!/bin/bash

if [ $# == 1 ]
    then
    toto=`echo $1 | wc -c | sed 's/ //g'`
    let "toto-=1"
    echo $toto
    else
    echo ""
fi

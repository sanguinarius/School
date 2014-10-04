#!/bin/bash

if [ $# == 1 ]
    then
    ls -l $1 | awk 'NR%2==1'
fi

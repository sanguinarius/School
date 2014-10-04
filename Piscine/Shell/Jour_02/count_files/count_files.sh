#!/bin/bash

if [ $# == 1 ]
    then
    find $1 -type f -o -type d | wc -l | sed 's/ //g'
fi

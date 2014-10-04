#!/bin/bash

if [ $# == 2 ]; then
    user= cut -d : -f 1 $1
    echo $user
fi

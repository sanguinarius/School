#!/bin/bash

echo -e "obase=13\nibase=5\n$MY_NBR1+$MY_NBR2" | tr "'" 0 | tr "\\" 1 | tr "\"" 2 | tr "\?" 3 | tr "\!" 4 | tr "mrdoc" "01234" | sed "s/3base/obase/" | bc | tr "0123456789ABC" "gtaio luSnemf"
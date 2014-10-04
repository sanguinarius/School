#!/bin/bash

cat passwd | sed 's/etna1/newbee/g' | sed 's/prof/gentil/g' | awk -F : '{if ($0 ~ /newbee/ || $0 ~ /gentil/) print $0}'

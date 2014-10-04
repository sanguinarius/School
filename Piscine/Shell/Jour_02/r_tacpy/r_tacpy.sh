#!/bin/bash

cat passwd | grep -e "etna1" -e "etna2" -e "etna3" | awk -F : '{if (NR % 2 == 0) print $1}' | rev | sort -r > toto
cat toto | awk -v min="$MY_LINE1" -v max="$MY_LINE2" '{if (NR >= min && NR <= max) print $0}' | tr '\n' ',' > tata
echo "." >> tata
sed 's/\,\./\./g' tata
rm toto
rm tata

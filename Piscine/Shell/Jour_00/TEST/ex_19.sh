#!/bin/bash

awk -F: '{if ($3 % 2 == 1) print $0;}' /etc/passwd

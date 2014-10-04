#!/bin/bash

awk -F : '{if (tolower($5) ~ "rinaz" && tolower($5) ~ "samir") print $0}' passwd | wc -l | sed 's/ //g'

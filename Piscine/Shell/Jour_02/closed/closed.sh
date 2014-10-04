#!/bin/bash

awk -F: '{if ($7 == "/bin/shells/close") print $1;}' passwd

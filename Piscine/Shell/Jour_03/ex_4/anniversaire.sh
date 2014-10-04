#!/bin/bash

if [ $# == 1 ]
    then
    day=`date "+%d"`
    month=`date "+%m"`
    year=`date "+%Y"`
    day_anni=`echo $1 | awk -v toto=$1 -F - '{print $1}'`
    month_anni=`echo $1 | awk -v toto=$1 -F - '{print $2}'`
    year_anni=`echo $1 | awk -v toto=$1 -F - '{print $3}'`
    i=$year_anni
    let "year--"
    let "year++"
    while [ $i -lt $year ]
    do
	(( i++ ))
    done
    let "i-=$year_anni"
    if [ $month -lt $month_anni ]
	then
	(( i--))
	elif [ $month = $month_anni ]
	then
	if [ $day -lt $day_anni ]
	    then
	    (( i-- ))
	fi
    fi
    echo -n "Age : $i "
    if [ $i == 0 ]
	then
	echo "an"
	else
	echo "ans"
    fi
    i=0
    month=`echo $month|sed 's/^0*//'`
    month_anni=`echo $month_anni|sed 's/^0*//'`
    day=`echo $day|sed 's/^0*//'`
    day_anni=`echo $day_anni|sed 's/^0*//'`
    while [ $month != $month_anni ] || [ $day != $day_anni ]
    do
	if [ $month == 1 ] && [ $day == 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 2 ] && [ $day = 28 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 3 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 4 ] && [ $day = 30 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 5 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 6 ] && [ $day = 30 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 7 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 8 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 9 ] && [ $day = 30 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 10 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 11 ] && [ $day = 30 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    day=1
	elif [ $month == 12 ] && [ $day = 31 ]
	    then
	    (( month++ ))
	    (( i++ ))
	    month=1
	    day=1
	else
	    (( i++ ))
	    (( day++ ))
	fi
    done
    echo -n "Prochain anniversaire dans : $i "
    if [ $i == 0 ] || [ $i == 1 ]
	then
	echo "jour"
	else
	echo "jours"
    fi
fi

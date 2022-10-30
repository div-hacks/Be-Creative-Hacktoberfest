#! /bin/bash

#Comparing over patterns
#This script shows how many days are in the current month

#Get the current month:

month=$(date +%m)

#Is it February?
if [[ ${month} -eq 2 ]]
then
	echo "There are 28 days in February. In leap years, it has 29 days."
#Write a pattern for 30 days months:
elif [[ ${months} = @(04|06|09|11) ]]
then
	echo "This month has 30 days."
else
	echo "This month has 31 days."
fi

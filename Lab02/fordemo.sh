#!/bin/bash
#fordemo.sh
NUMS="1 2 3 4 5 6 7 8 9"
for i in $NUMS; do
	printf "%d\n" "$i"
	q=$(expr "$i" + 1)
	printf "%d\n" "$q"
done
for file in "$HOME"/.bash*; do
	printf "%s\n" "$file"
done
for file in $(find . -type d -name "L*"); do
	printf "%s\n" "$file"
done

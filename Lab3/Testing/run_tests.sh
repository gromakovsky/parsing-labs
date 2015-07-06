#!/bin/bash

rm -f obfuscated_*.cpp
for filename in *.cpp; do
    echo "Obfuscating $filename"
    ./obfuscator "$filename" -o "obfuscated_$filename"
    if [ $? -eq 0 ]; then
        echo "$filename successfully obfuscated"
    else
        echo "$filename obfuscation failed"
    fi
done


#!/bin/bash

i=0

while read -r line; do
    let "i=$i+1"
    echo "$line" > input.txt
    error=$( { ./make_graph.sh "graph$i.eps"; } 2>&1 )
    if [ -n "$error" ]; then
        echo "Test $i failed:"
        echo "$error"
    else
        echo "Test $i passed"
    fi
done < tests

rm -f input.txt

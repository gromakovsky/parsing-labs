#!/bin/bash

i=0
failed_tests=0

while read -r line; do
   let "i=$i+1"
   echo "$line" > input.txt

   echo "Test $i started"
   error=$( { ./make_graph.sh "graph$i.eps"; } 2>&1 )

   if [ -n "$error" ]; then
      result="BAD"
      echo "$error"
   else
      result="GOOD"
   fi

   read -r expected
   if [ "$result" == "$expected" ]; then
      echo "Test $i passed"
   else
      echo "Test $i failed"
      let "failed_tests=$failed_tests+1"
   fi

done < tests

rm -f input.txt

exit $failed_tests

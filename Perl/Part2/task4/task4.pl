#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    s/(\b)(\w+)(\W+)(\w+)/$1$4$3$2/;
    print;
}

#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    s/(\d+)0( |$)/$1$2/g;
    print;
}

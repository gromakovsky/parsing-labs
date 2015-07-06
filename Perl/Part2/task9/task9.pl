#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    s/\(([^)]*)\)/()/g;
    print;
}

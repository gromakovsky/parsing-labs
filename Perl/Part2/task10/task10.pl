#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
#    s/(a[^a]*a){3}/bad/g;
    s/(a.*?a){3}/bad/g;
    print;
}

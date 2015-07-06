#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    print if /\(([^()]*[^\w()]\w+[^\w()][^()]*|\w+[^\w()][^()]*|[^()]*[^\w()]\w+|\w+)\)/
}

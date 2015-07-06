#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    s/(\b)(\w)(\w)(\w*)(\b)/$1$3$2$4$5/g;
    print;
}

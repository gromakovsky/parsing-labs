#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    print if /z.{3}z/;
}

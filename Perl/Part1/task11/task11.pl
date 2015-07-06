#!/usr/bin/env perl
use strict;
use warnings;
 
while (<>) {
    print if /^(1(01*0)*1|0)*$/;
}

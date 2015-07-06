#!/usr/bin/env perl
use strict;
use warnings;

while (<>) {
    print if /(^|\W)+cat($|\W)+/;
}

#!/usr/bin/env perl
use strict;
use warnings;

my $empty_string = '^ *$';

sub remove_tags {
    my $string = shift;
    $string =~ s/<[^>]+>//g;
    return $string;
}

while (<>) {
    $_ = remove_tags($_);
    unless (/$empty_string/) {
        s/^ +//;
        s/ +$//;
        s/ +/ /g;
        print;
        last;
    }
}

my $prev_empty = 0;

while (<>) {
    $_ = remove_tags($_);
    unless (/$empty_string/) {
        if ($prev_empty) {
            print "\n";
            $prev_empty = 0;
        }
        s/^ +//;
        s/ +$//;
        s/ +/ /g;
        print;
    } else {
        $prev_empty = 1;
    }
}

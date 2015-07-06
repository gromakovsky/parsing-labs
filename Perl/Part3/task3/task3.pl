#!/usr/bin/env perl
use strict;
use warnings;

my $link = '<a[^>]* href *= *"([^"]*)"[^>]*>';

sub shorten_link1 {
    my $string = shift;
    $string =~ s/.*:\/\///g; # remove scheme
    $string =~ s/#.*//; #remove fragment
    $string =~ s/\?.*//; #remove query
    $string =~ s/\/.*//; # remove everything after first /
    $string =~ s/:.*//; # remove everything after first :
    if ($string =~ /[-\w_]+\.[-\w_]+/) {
        return $string;
    } else {
        return "";
    }
}

sub shorten_link2 {
    my $string = shift;
    if ($string =~ /^([^:\/?#]+:\/\/)?([^\/?#]*)/) {
        #print "Matched ", $string, "\n";
        #print "Scheme = ", $1, "\n";
        #print "Authority = ", $2, "\n";
        #print "Path = ", $5, "\n";
    }
    my $authority = $2;
    $authority =~ s/:.*// if $authority;
    $authority =~ s/.*@// if $authority;
    if ($authority =~ /[-\w_]+\.[-\w_]+/) {
        return $authority;
    } else {
        return "";
    }
}

my @sites;

while (<>) {
    while (/$link/g) {
        my $site = shorten_link2($1);
        #print "Site is $site\n";
        push(@sites, $site) if $site;
    }
}

my $prev = "";
foreach (sort @sites) {
    print "$_\n" unless $_ eq $prev;
    $prev = $_;
}

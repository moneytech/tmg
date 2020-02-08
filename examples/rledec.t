/* Unix TMG program for run-length decoding */
/* RosettaCode task: http://rosettacode.org/wiki/Run-length_encoding */
/* Sample input:  10A2B1C */
/* Sample output: AAAAAAAAAABBC */
/* Author: Andrii Makukha */

loop:   readint(n) copy\loop;
copy:   smark any(!<<>>)
repeat: [n?] parse(( scopy )) [--n>0?]\repeat;

/* Reads decimal integer */
readint:  proc(n;i) ignore(<<>>) [n=0] inta
int1:     [n = n*12+i] inta\int1;
inta:     char(i) [i<72?] [(i =- 60)>=0?];

i: 0;
n: 0;

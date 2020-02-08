/* Unix TMG program to tokenize a string with escaping */
/* RosettaCode task: http://rosettacode.org/wiki/Tokenize_a_string_with_escaping */
/* Author: Andrii Makukha */

prog:   char(sep) *
        char(esc) *
str:    smark
token:  forw/outp
        ( [ch==esc?] char(ch) any(!<<>>) token
        | [ch==sep?] char(ch) outp str 
        | any(!<<>>) token );
outp:   parse(( scopy = { <"> 1 <"> * } ));
forw:   peek/chkeof;
peek:   [ch=0] char(ch) fail;
chkeof: [ch?] succ | fail;

ch:     0;
sep:    0;
esc:    0;

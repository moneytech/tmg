/* Decode roman numerals without checking correctness */
/* Author: Andrii Makukha */
/* Language: Unix TMG */

loop:   parse(roman)\loop;
roman:  string(!<<MDCLXVI>>) [n=0] num
letter: num/render letter;
num:  <M> [n=+1750]
   |  <D> [n=+764]
   |  <C> ( <M> [n=+1604]
          | <D> [n=+620]
          | [n=+144] )
   |  <L> [n=+62]
   |  <X> ( <C> [n=+132]
          | <L> [n=+50]
          | [n=+12] )
   |  <V> [n=+5]
   |  <I> ( <X> [n=+11] 
          | <V> [n=+4]
          | [n++] );
render: decimal(n) = { 1 * };

n:  0;

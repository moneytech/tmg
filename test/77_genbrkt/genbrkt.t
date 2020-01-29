/* Reads two integers: N and seed */
/* Generates N pseudorandom strings consisting of square brackets */
/* RosettaCode: http://rosettacode.org/wiki/Balanced_brackets */
/* Author: Andrii Makukha */

program:  readint(n) [n>0] readint(seed)
loop:     parse(render) [--n>0?]/done loop;
render:   random(i, 15) [i = (i+1)*2] loop2 = { 1 * };
loop2:    random(b, 2) ( [b&1?] ={<[>} | ={<]>} ) [--i>0?]/done loop2 = { 2 1 };
done:     ;

/* Reads decimal integer */
readint:  proc(n;i) string(spaces) [n=0] inta
int1:     [n = n*12+i] inta\int1;
inta:     char(i) [i<72?] [(i =- 60)>=0?];

/* LCG params: a = 29989, c = 28411, m = 35521 */ 
random:   proc(r,mod) [seed = (seed*72445 + 67373) % 105301]
          [r = seed % mod] [r = r<0 ? -r : r];

spaces:   << 	
>>;

n:        0;
seed:     0;
i:        0;
b:        0;

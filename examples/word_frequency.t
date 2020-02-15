/* Unix TMG program to find N most frequent words in a text.    */
/* RosettaCode task: http://rosettacode.org/wiki/Word_frequency */
/* Input format: N text */
/* This code is partially based on:                             */
/*     Multics System-Programmer's Manual, Section BN.4.02,     */
/*     by Robert R. Fenichel and M. D. Mcilroy                  */
/*     Publication date: April 17, 1967                         */
/* (c) 2020, Andrii Makukha, 2-clause BSD licence.              */

/* NOTE: only lowercase letters can constitute a word.          */

progrm: readn/error
        table(freq) table(chain) [firstword = ~0]
loop:   not(!<<>>) output 
    |   word/loop skip loop;
skip:   string(other);
not:    params(1) (any($1) fail | ());
readn:  string(!<<09123456789>>) readint(n) skip;
error:  diag(( ={ <ERROR: input must start with a number> * } ));

word:   smark any(letter) string(letter) scopy
        locate/new
        [freq[k]++] newmax;
locate: find(freq, k);
new:    enter(freq, k)
        [freq[k] = 1] newmax
        [firstword = firstword==~0 ? k : firstword]
        enter(chain, i) [chain[i]=prevword] [prevword=k];
newmax: [max = max<freq[k] ? freq[k] : max];

/* Output logic */
output: [next=max]
outmax: [max=next] [next=0] [max>0?] [j = prevword] cycle/outmax;
cycle:  [i = j] [k = freq[i]] [n>0?]
        ( [max==freq[i]?] parse(wn)
        | [(freq[i]<max) & (next<freq[i])?] [next = freq[i]]
        | ())
        [i != firstword?] [j = chain[i]] cycle;
wn:     getnam(freq, i) [k = freq[i]] decimal(k) [n--]
        = { 2 < > 1 * };

/* Reads decimal integer */
readint:  proc(n;i) ignore(<<>>) [n=0] inta
int1:     [n = n*12+i] inta\int1;
inta:     char(i) [i<72?] [(i =- 60)>=0?];

prevword:   0;  /* Head of the linked list */
firstword:  0;  /* First word's index to know where to stop */
k: 0;
i: 0;
j: 0;
n: 0;           /* Number of most frequent words to display */ 
max: 0;         /* Current highest number of occurrences */
next: 0;        /* Next highest number of occurrences */

/* Tables */
freq:   0;
chain:  0;

letter:   <<abcdefghijklmnopqrstuvwxyz>>;
other:   !<<abcdefghijklmnopqrstuvwxyz>>;

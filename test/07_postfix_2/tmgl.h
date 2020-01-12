// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "infix expression"
#define DST_LANGUAGE "Polish postfix"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	(tword)&ignore,
#define __space    (tword)&labels[1]
	__space,
	(tword)&_l,
#define __alpha    (tword)&labels[2]
	__alpha,
	(tword)&_l,
#define __letter   (tword)&labels[3]
	__letter,
	(tword)&_l,
#define __digit    (tword)&labels[4]
	__digit,
	(tword)&_o,
	(tword)&_st,
	(tword)&_p,
	1 + (tword)&parse,
#define __expr     (tword)&labels[5]
	__expr,
#undef _1
#define _1         (tword)&start[14]
	(tword)&_tp,
	3,
	(tword)&_tp,
	1,
	1 + (tword)&_tp,
	2,
// __expr:
#define __term     (tword)&labels[6]
	__term,
#define __expr1    (tword)&start[21]
#define __addop    (tword)&labels[7]
	__addop,
	(tword)&alt,
#define __done     (tword)&labels[8]
	__done,
	__term,
	(tword)&trans,
	1 + _1,
	(tword)&bundle,
	1 + (tword)&salt,
	__expr1,
#undef _1
#define _1         (tword)&start[30]
	(tword)&_tp,
	3,
	(tword)&_tp,
	1,
	1 + (tword)&_tp,
	2,
// __term:
#define __factor   (tword)&labels[9]
	__factor,
#define __term1    (tword)&start[37]
#define __mulop    (tword)&labels[10]
	__mulop,
	(tword)&alt,
	__done,
	__factor,
	(tword)&trans,
	1 + _1,
	(tword)&bundle,
	1 + (tword)&salt,
	__term1,
#undef _2
#define _2         (tword)&start[46]
	(tword)"EXP ",
#undef _1
#define _1         (tword)&start[47]
	(tword)&_tp,
	2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_2,
// __factor:
#define __primary  (tword)&labels[11]
	__primary,
	(tword)&_pxs,
	(tword)'^',
	(tword)&alt,
	__done,
	__factor,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[61]
	(tword)"LOAD ",
#undef _1
#define _1         (tword)&start[62]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)' ',
// __primary:
#define __value    (tword)&labels[12]
	__value,
	(tword)&alt,
#define __3        (tword)&labels[13]
	__3,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __2        (tword)&labels[14]
	__2,
// __3:
	(tword)&_pxs,
	(tword)'(',
	__expr,
	(tword)&_pxs,
	(tword)')',
// __2:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[81]
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[83]
	1 + (tword)&_tp,
	1,
// __value:
#define __ident    (tword)&labels[15]
	__ident,
	(tword)&alt,
#define __5        (tword)&labels[16]
	__5,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __4        (tword)&labels[17]
	__4,
// __5:
#define __number   (tword)&labels[18]
	__number,
	(tword)&trans,
	1 + _2,
// __4:
	1 + (tword)&succ,
// __done:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[97]
	(tword)"ADD ",
#undef _1
#define _1         (tword)&start[98]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[100]
	(tword)"SUB ",
#undef _3
#define _3         (tword)&start[101]
	1 + (tword)&_tx,
	_4,
// __addop:
	(tword)&_pxs,
	(tword)'+',
	(tword)&alt,
#define __7        (tword)&labels[19]
	__7,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __6        (tword)&labels[20]
	__6,
// __7:
	(tword)&_pxs,
	(tword)'-',
	(tword)&trans,
	1 + _3,
// __6:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[116]
	(tword)"MUL ",
#undef _1
#define _1         (tword)&start[117]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[119]
	(tword)"DIV ",
#undef _3
#define _3         (tword)&start[120]
	1 + (tword)&_tx,
	_4,
// __mulop:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __11       (tword)&labels[21]
	__11,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __10       (tword)&labels[22]
	__10,
// __11:
	(tword)&_pxs,
	(tword)'/',
	(tword)&trans,
	1 + _3,
// __10:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[135]
	1 + (tword)&_tp,
	1,
// __ident:
	(tword)&smark,
	(tword)&any,
	__letter,
	(tword)&string,
	__alpha,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[145]
	1 + (tword)&_tp,
	1,
// __number:
	(tword)&smark,
	(tword)&any,
	__digit,
	(tword)&string,
	__digit,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _1,
// __space:
	1,
// __letter:
	2,
// __digit:
	4,
// __alpha:
	0,
#define __classtab (tword)&start[159]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	0,
	0,
	0,
	0,
	0,
	0,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[287]
	1 + (tword)&_pxs,
	(tword)'\n',
#define _tn        (tword)&start[289]
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[155],     // __space
	(tword)&start[158],     // __alpha
	(tword)&start[156],     // __letter
	(tword)&start[157],     // __digit
	(tword)&start[20],      // __expr
	(tword)&start[36],      // __term
	(tword)&start[103],     // __addop
	(tword)&start[96],      // __done
	(tword)&start[53],      // __factor
	(tword)&start[122],     // __mulop
	(tword)&start[68],      // __primary
	(tword)&start[85],      // __value
	(tword)&start[75],      // __3
	(tword)&start[80],      // __2
	(tword)&start[137],     // __ident
	(tword)&start[92],      // __5
	(tword)&start[95],      // __4
	(tword)&start[147],     // __number
	(tword)&start[111],     // __7
	(tword)&start[115],     // __6
	(tword)&start[130],     // __11
	(tword)&start[134],     // __10
};

// Used builtins:
//   _l
//   _o
//   _p
//   _pxs
//   _st
//   _tp
//   _tx
//   _txs
//   alt
//   any
//   bundle
//   ignore
//   parse
//   salt
//   scopy
//   smark
//   string
//   succ
//   tgoto
//   trans

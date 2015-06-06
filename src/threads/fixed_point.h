#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/*
 	* 使用17.14格式，17位整数，14位小数，整型左移14位即为浮点型
	* Convert n to fixed point:	n * f
	* Convert x to integer (rounding toward zero):	x / f
	* Convert x to integer (rounding to nearest):	(x + f / 2) / f if x >= 0, 
													(x - f / 2) / f if x <= 0.
	* Add x and y:	x + y
	* Subtract y from x:	x - y
	* Add x and n:	x + n * f
	* Subtract n from x:	x - n * f
	* Multiply x by y:	((int64_t) x) * y / f
	* Multiply x by n:	x * n
	* Divide x by y:	((int64_t) x) * f / y
	* Divide x by n:	x / n
*/ 

typedef int64_t fixed_t;

#define SHIFT_AMOUNT 14
#define INT2FLOAT(n) ((fixed_t)(n << SHIFT_AMOUNT))
#define FLOAT2INTPART(x) (x >> SHIFT_AMOUNT)
#define FLOAT2INTNEAR(x) (x >= 0 ? ((x + (1 << (SHIFT_AMOUNT - 1))) >> SHIFT_AMOUNT) : ((x - (1 << SHIFT_AMOUNT)) >> SHIFT_AMOUNT))
#define FLOATADDFLOAT(x, y) (x + y)
#define FLOATSUBFLOAT(x, y) (x - y)
#define FLOATADDINT(x, n) (x + (n << SHIFT_AMOUNT))
#define FLOATSUBINT(x, n) (x - (n << SHIFT_AMOUNT))
#define FLOATMULFLOAT(x, y) ((((int64_t)x) * y) >> SHIFT_AMOUNT)
#define FLOATMULINT(x, n) (x * n)
#define FLOATDIVFLOAT(x, y) ((((int64_t)x) << SHIFT_AMOUNT) / y)
#define FLOATDIVINT(x, n) (x / n)

/*#define FFORM 16384
#define INT2FLOAT(n) (n*FFORM)
#define FLOAT2INTPART(x) (x/FFORM)
#define FLOAT2INTNEAR(x) (x>=0?((x+FFORM/2)/FFORM):((x-(FFORM/2))/FFORM))
#define FLOATADDFLOAT(x,y) (x+y)
#define FLOATSUBFLOAT(x,y) (x-y)
#define FLOATADDINT(x,n) (x+(n*FFORM))
#define FLOATSUBINT(x,n) (x-(n*FFORM))
#define FLOATMULFLOAT(x,y) ((((int64_t)x)*y)/FFORM)
#define FLOATMULINT(x,n) (x*n)
#define FLOATDIVFLOAT(x,y) ((((int64_t)x)*FFORM)/y)
#define FLOATDIVINT(x,n) (x/n)*/

#endif
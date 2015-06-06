#define f 16384 //We use the 17.14 form of floating point
#define int_to_fix(n)  (n*f)                   // Convert n to fixed point 
#define fix_to_int_zero(x) (x/f)//Convert x to integer(rounding toward zero) 
#define fix_to_int_nearest(x) ((x>=0)?(x+f/2)/f:(x-f/2)/f)  // Convert x to integer(rounding to nearest). 
#define add_fix_to_fix(x,y) (x+y)			// Add x and y. 
#define sub_fix_to_fix(x,y) (x-y)			// Subtract y from x. 
#define add_fix_to_int(x,n) (x+n*f)			// Add x and n. 
#define sub_fix_to_int(x,n) (x-n*f)			// Subtract n from x. 
#define mul_fix_to_fix(x,y) (((int64_t)x)*y/f)		// Multiply x by y. 
#define mul_fix_to_int(x,n) (x*n)		 	// Multiply x by n. 
#define div_fix_to_fix(x,y) (((int64_t)x)*f/y)		// Divide x by y. 
#define div_fix_to_int(x,n) (x/n)			// Divide x by n. 



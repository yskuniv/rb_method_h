#ifndef _RB_METHOD_H_
#define _RB_METHOD_H_

#define RB_RANGE_EACH(from, to, num, exp)			\
	for (typeof(from) num = (from); num <= (to); ++num)	\
		exp

#define RB_TIMES(count, num, exp)		\
	RB_RANGE_EACH(0, (count) - 1, num, exp)

#define RB_EACH(array, length, elm, exp)				\
	for (typeof(&*(array)) elm = (array), end = elm + (length); elm < end; ++elm) \
		exp

#define RB_EACH_ROTATE(array, length, from, elm, exp)			\
	RB_TIMES(length, i__,						\
		 ({							\
			 typeof(&*(array)) elm = (array) + ((from) + i__) % (length); \
			 exp;						\
		 }))

#define RB_INJECT(array, length, init, sum, elm, func)		\
	({							\
		typeof(init) sum = (init);			\
		RB_EACH(array, length, elm, sum = func);	\
		sum;						\
	})

#define RB_GENERAL_MAX_BY(array, length, elm, exp, opr)	\
	({						\
		typeof(&*(array)) elm = array;		\
		typeof(exp) max__ = exp;		\
		typeof(&*(array)) ret__ = elm;		\
		RB_EACH((array) + 1, (length) - 1, elm,	\
			({				\
				if (exp opr max__) {	\
					max__ = exp;	\
					ret__ = elm;	\
				}			\
			}));				\
		ret__;					\
	})

#define RB_MAX_BY(array, length, elm, exp)		\
	RB_GENERAL_MAX_BY(array, length, elm, exp, >)

#define RB_MIN_BY(array, length, elm, exp)		\
	RB_GENERAL_MAX_BY(array, length, elm, exp, <)	\

#define RB_FIND(array, length, elm, cond)		\
	({						\
		typeof(&*(array)) ret__ = NULL;		\
		RB_EACH(array, length, elm,		\
			({				\
				if (cond) {		\
					ret__ = elm;	\
					break;		\
				}			\
			}));				\
		ret__;					\
	})

#define RB_FIND_ROTATE(array, length, from, elm, cond)		\
	({							\
		typeof(&*(array)) ret__ = NULL;			\
		RB_EACH_ROTATE(array, length, from, elm,	\
			       ({				\
				       if (cond) {		\
					       ret__ = elm;	\
					       break;		\
				       }			\
			       }));				\
		ret__;						\
	})

#endif /* _RB_METHOD_H_ */

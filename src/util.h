#ifndef _AUP_UTIL_H
#define _AUP_UTIL_H

#include "aup.h"

typedef enum {
	AUP_OK = 0,
	AUP_COMPILE_ERR,
	AUP_RUNTIME_ERR
} aupStt;

typedef struct _aupCtx aupCtx;
typedef struct _aupVM aupVM;

#define AUP_VM	aupVM *vm

// Combine two low bytes
#define AUP_CMB(l, r)	(uint8_t)(((char)(l) & 0xF) | ((char)(r) & 0xF) << 4)
#define AUP_CMB_L(c)	(char)(((c) & 0xF))
#define AUP_CMB_R(c)	(char)((((c) >> 4) & 0xF))

#endif
#include <stdio.h>
#include <stdlib.h>

#include "value.h"
#include "object.h"
#include "memory.h"

static const char
	__nil[]  = "nil",
	__bool[] = "bool",
	__int[]  = "int",
	__num[]  = "num";

const char *aupV_typeOf(aupV value)
{
	switch (AUP_TYPE(value)) {
		default:
		case AUP_TNIL:
			return __nil;
		case AUP_TBOOL:
			return __bool;
		case AUP_TINT:
			return __int;
		case AUP_TNUM:
			return __num;
		case AUP_TOBJ:
			return aupO_typeOf(AUP_AS_OBJ(value));
	}
}

void aupV_print(aupV value)
{
	switch (AUP_TYPE(value)) {
		default:
		case AUP_TNIL:
			printf("nil");
			break;
		case AUP_TBOOL:
			printf(AUP_AS_BOOL(value) ? "true" : "false");
			break;
		case AUP_TINT:
			printf("%lld", AUP_AS_INT(value));
			break;
		case AUP_TNUM:
			printf("%.14g", AUP_AS_NUM(value));
			break;
		case AUP_TOBJ:
			aupO_print(AUP_AS_OBJ(value));
			break;
	}
}

void aupVa_init(aupVa *array)
{
	array->count = 0;
	array->capacity = 0;
	array->values = NULL;
}

int aupVa_write(aupVa *array, aupV value)
{
	if (array->capacity < array->count + 1) {
		int oldCapacity = array->capacity;
		array->capacity = AUP_GROW_CAP(oldCapacity);
		array->values = realloc(array->values, array->capacity * sizeof(aupV));
	}

	array->values[array->count] = value;
	return array->count++;
}

void aupVa_free(aupVa *array)
{
	free(array->values);
	aupVa_init(array);
}

int aupVa_find(aupVa *array, aupV value)
{
#define IS_EQUAL(v1, v2) \
	AUP_TYPE(v1) == AUP_TYPE(v2) && \
	AUP_AS_RAW(v1) == AUP_AS_RAW(v2)

	for (int i = 0; i < array->count; i++) {
		if (IS_EQUAL(array->values[i], value)) {
			return i;
		}
	}

	return -1;
}


#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAYLIST_ET_PTR   (1 << 0)
#define ARRAYLIST_ET_INT   (1 << 1)
#define ARRAYLIST_ET_FLOAT (1 << 2)
#define ARRAYLIST_ERROR    (1 << 3)
const char ARRAYLIST_ER_MSG_MALLOC[] = "Failed to allocate memory.";
const char ARRAYLIST_ER_MSG_OUTOFRANGE[] = "Out of range.";
const char ARRAYLIST_ER_MSG_WRONG_VARIABLE[] = "This ArrayList is not initialized for this variable type.";
#define ArrayListGetSize(PointerOfArrayList)  (PointerOfArrayList->size)
#define CHECK_ARRAYLIST_VARIABLE_TYPE(PointerOfArrayList,FLAGU) (PointerOfArrayList->flag & FLAGU)
struct ArrayElement{
	struct ArrayElement *last;
	struct ArrayElement *next;
	union{
		void *ptr;
		long integer;
		double floating;
	}value;
};

typedef struct SuperSG_ArrayList_structure{
	unsigned int size;
	unsigned char flag;
	const char *errMsg;
	struct ArrayElement *head;
	struct ArrayElement *butt;
}ArrayList;
extern int checkTypeArrayList(ArrayList *ptr);
extern int checkErrorArrayList(ArrayList *ptr);
extern const char * getErrorMessageArrayList(ArrayList *ptr);
extern ArrayList * newArrayList(int type);
extern void freeArrayList(ArrayList *ptr);
extern void ArrayListAddInt(ArrayList *ptr,long val);
extern void ArrayListAddFloat(ArrayList *ptr,double val);
extern void ArrayListAddPtr(ArrayList *ptr,void *val);
extern void ArrayListInsertInt(ArrayList *ptr,int index,long val);
extern void ArrayListInsertFloat(ArrayList *ptr,int index,float val);
extern void ArrayListInsertPtr(ArrayList *ptr,int index,void *val);
extern long ArrayListGetInt(ArrayList *ptr,int index);
extern double ArrayListGetFloat(ArrayList *ptr,int index);
extern void * ArrayListGetPtr(ArrayList *ptr,int index);
extern void ArrayListDeleteAt(ArrayList *ptr,int index);

#define STRINGBUILDER_TYPE_CHAR 1
#define STRINGBUILDER_TYPE_STR 2
struct StringBuilder_ele{
    char type;
    size_t size;
    union{
        char c;
        char *str;
    }val;
    struct StringBuilder_ele *next;
};
typedef struct StringBuilder_struct{
    size_t size;
    struct StringBuilder_ele *head;
    struct StringBuilder_ele *butt;
}StringBuilder;
extern void StringBuilder_append_char(StringBuilder *ptr,char c);
extern StringBuilder * new_StringBuilder();
extern void StringBuilder_free(StringBuilder *ptr);
extern void StringBuilder_append_str(StringBuilder *ptr,const char *str);
extern char * StringBuilder_toString(StringBuilder *ptr);
extern size_t StringBuilder_getSize(StringBuilder *ptr);

#define STRMAP_TYPE_PTR 1
#define STRMAP_TYPE_STRING 2
#define STRMAP_TYPE_DOUBLE 3
#define STRMAP_TYPE_LONG 4
struct StrMap_ele_structure{
    char *key;
    union{
        void *pval;
        char *sval;
        double dval;
        long lval;
    }val;
    struct StrMap_ele_structure *less;
    struct StrMap_ele_structure *greater;
};
typedef struct StrMap_structure{
    int type;
    struct StrMap_ele_structure *head;
}StrMap;
#endif

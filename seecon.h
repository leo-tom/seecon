
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

#define CMAP_TYPE_STR 0
#define CMAP_TYPE_LONG 1
#define CMAP_TYPE_DOUBLE 2
#define CMAP_TYPE_PTR 3
#define CMAP_TYPE_LESS_THAN_DIS 4

#define CMAP_ERROR_NO_NULL_PTR 1
#define CMAP_ERROR_WRONG_KEY_TYPE 2
#define CMAP_ERROR_WRONG_ELEMENT_TYPE 3
extern const char const *MAP_ERROR_MSG[];
struct Map_ele_structure{
	union key{
		double dval;
		char *sval;
		long lval;
	}
	union{
			void *pval;
			char *sval;
			double dval;
			long lval;
	}val;
	struct Map_ele_structure *less;
	struct Map_ele_structure *greater;
};
typedef struct Map_structure{
    unsigned char type; /*First 4 bit is for key, last 4 bit for value*/
		short int errno;
		char *errmsg;
    struct Map_ele_structure *head;
}cMap;
const struct cMap_element_types_structure{
	char Pointer = CMAP_TYPE_PTR;
	char String = CMAP_TYPE_STR;
	char Integer = CMAP_TYPE_LONG;
	char Double = CMAP_TYPE_DOUBLE;
}cMapTypes;
extern cMap * new_cMap(int keytype,int element_type);
extern void cMap_free(cMap *);
/*ptr only*/
extern void cMap_setcmp(int (func)(void *,void*));
extern void cMap_set_error(cMap *map,int error_type);

extern int cMap_set_real(cMap *map,void *,void *);
/*change kee and value to void pointer */
#ifndef __GNUC__
#warning it is reccomended to compile seecon with gcc.
#define cMap_set(map_ptr,cmap_kee,cmap_ele) ( (cMap_set_real(map_ptr,&(cmap_kee),&(cmap_ele) )))
#elif __GNUC__ >= 4.9

#define cMap_set(map_ptr,cmap_kee,cmap_ele) { \
	char cmap_type_indentify = 0; \
	_Generic(cmap_kee, \
		char * : cmap_type_indentify &= CMAP_TYPE_STR << 4 , \
		long   : cmap_type_indentify &= CMAP_TYPE_LONG << 4 , \
		double : cmap_type_indentify &= CMAP_TYPE_DOUBLE << 4 , \
		default : cmap_type_indentify &= CMAP_TYPE_DOUBLE << 4 \
	) \
	_Generic(cmap_ele, \
		char * : cmap_type_indentify &= CMAP_TYPE_STR , \
		long   : cmap_type_indentify &= CMAP_TYPE_LONG , \
		double : cmap_type_indentify &= CMAP_TYPE_DOUBLE , \
		default : cmap_type_indentify &= CMAP_TYPE_DOUBLE \
	) \
	if(cmap_type_indentify & 0xf0 != map_ptr->type & 0xf0){ \
		cMap_set_error(map_ptr,CMAP_ERROR_WRONG_KEY_TYPE); \
	}else if( cmap_type_indentify & 0xf0 !=  map_ptr->type & 0xf0){ \
		cMap_set_error(map_ptr,CMAP_ERROR_WRONG_ELEMENT_TYPE); \
	}else{ \
		cMap_set_real(map_ptr,&(cmap_kee),&(cmap_ele)); \
	} \
}
#else
#warning better to have gcc version of >= 4.9 but compiling anyways
#define cMap_set(map_ptr,cmap_kee,cmap_ele) ( (cMap_set_real(map_ptr,&(cmap_kee),&(cmap_ele) )))
#endif

extern struct Map_ele_structure * _cMap_get_long(cMap *,long lval);
extern struct Map_ele_structure * _cMap_get_double(cMap *,double dval);
extern struct Map_ele_structure * _cMap_get_ptr(cMap *,const void *ptr);
extern struct Map_ele_structure * _cMap_get_str(cMap *,const char *str);
#define CMAP_GET_VALUE(cmap_get_value_ptr,cmap_ele_ptr) ( \
	cmap_get_value_ptr->type & 0x0f == CMAP_TYPE_LONG \
		? cmap_ele_ptr->val.lval \
	: cmap_get_value_ptr->type & 0x0f == CMAP_TYPE_STR \
		? cmap_ele_ptr->val.sval \
	: cmap_get_value_ptr->type & 0x0f == CMAP_TYPE_DOUBLE \
		? cmap_ele_ptr->val.dval \
	: cmap_get_value_ptr->type & 0x0f == CMAP_TYPE_PTR \
		? cmap_ele_ptr->val.pval \
)
#define cMap_get(cmap_get_ptr,cmap_get_kee) _Generic(cmap_get_kee,
	const char * : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_str(cmap_get_ptr,cmap_get_kee)),
	int          : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_long(cmap_get_ptr,cmap_get_kee)),
	long         : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_long(cmap_get_ptr,cmap_get_kee)),
	float        : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_double(cmap_get_ptr,cmap_get_kee)),
	double       : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_double(cmap_get_ptr,cmap_get_kee)),
	default      : CMAP_GET_VALUE(cmap_get_ptr,_cMap_get_ptr(cmap_get_ptr,cmap_get_kee))
)
/*internal*/

#endif

#include "seecon.h"


/*Returns integer represent type of element this array list can have*/
int checkTypeArrayList(ArrayList *ptr){
	return ptr->flag & (ARRAYLIST_ET_FLOAT | ARRAYLIST_ET_INT | ARRAYLIST_ET_PTR );
}
/*Return non-zero when there is error*/
int checkErrorArrayList(ArrayList *ptr){
	return ptr->flag & ARRAYLIST_ERROR;
}
/*Do not free pointer which is given from this function*/
const char * getErrorMessageArrayList(ArrayList *ptr){
	if(checkErrorArrayList(ptr)){
		return ptr->errMsg;
	}
	return NULL;
}
/*Remember to call freeArrayList*/
ArrayList * newArrayList(int type){
	if(!(type & (ARRAYLIST_ET_FLOAT | ARRAYLIST_ET_INT | ARRAYLIST_ET_PTR))){
		return NULL;
	}
	ArrayList *ptr = calloc(1,sizeof(ArrayList));
	if(ptr == NULL){
		return NULL;
	}
	ptr->flag = type;
	return ptr;
}
/*Call this!*/
void freeArrayList(ArrayList *ptr){
	struct ArrayElement *element = ptr->head;
	struct ArrayElement *tmp;
	free(ptr);
	while(element!=NULL){
		tmp = element->next;
		free(element);
		element = tmp;
	}
}
/*Dont use dis as an user*/
struct ArrayElement * newArrayElement(){
	return calloc(1,sizeof(struct ArrayElement));
}
#define Is_This_First_Element_Of_Array_List(givenValue) givenValue->head == NULL
/*Add int*/
void ArrayListAddInt(ArrayList *ptr,long val){
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_INT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	struct ArrayElement *ele = ptr->butt;
	if(Is_This_First_Element_Of_Array_List(ptr)){
		if((ptr->butt = ptr->head = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		ptr->butt->value.integer = val;
		ptr->size++;
		return;
	}
	if((ele->next = newArrayElement())==NULL){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
		return;
	}
	ele->next->last = ele;
	ele = ele->next;
	ele->value.integer = val;
	ptr->butt = ele;
	ptr->size++;
}
/*Add float*/
void ArrayListAddFloat(ArrayList *ptr,double val){
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_FLOAT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	struct ArrayElement *ele = ptr->butt;
	if((ele->next = newArrayElement())==NULL){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
		return;
	}
	if(Is_This_First_Element_Of_Array_List(ptr)){
		if((ptr->butt = ptr->head = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		ptr->butt->value.floating = val;
		ptr->size++;
		return;
	}
	ele->next->last = ele;
	ele = ele->next;
	ele->value.floating = val;
	ptr->butt = ele;
	ptr->size++;
}
/*Add ptr*/
void ArrayListAddPtr(ArrayList *ptr,void *val){
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_PTR)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	struct ArrayElement *ele = ptr->butt;
	if(Is_This_First_Element_Of_Array_List(ptr)){
		if((ptr->butt = ptr->head = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		ptr->butt->value.ptr = val;
		ptr->size++;
		return;
	}
	if((ele->next = newArrayElement())==NULL){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
		return;
	}
	ele->next->last = ele;
	ele = ele->next;
	ele->value.ptr = val;
	ptr->butt = ele;
	ptr->size++;
}
void ArrayListInsertInt(ArrayList *ptr,int index,long val){
	if(Is_This_First_Element_Of_Array_List(ptr)){
		ArrayListAddInt(ptr,val);
		return;
	}
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_INT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	int n;
	struct ArrayElement *ele;
	struct ArrayElement *nele;
	if(ptr->size < index || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return;
	}else if(ptr->size == index){
		/*means add*/
		ArrayListAddInt(ptr,val);
		return;
	}else if(ptr->size / 2 > index){
		/*head is closer*/
		ele = ptr->head;
		for(n=0;n<index;n++){
			ele = ele->next;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		if(ele->last != NULL){
			ele->last->next = nele;
			nele->last = ele->last;
			ele->last = nele;
			nele->next = ele;
		}else{
			/*ele->last == NULL arraylist.insert(0);*/
			ele->last = nele;
			nele->next = ele;
			ptr->head = nele;
		}
		ptr->size++;
	}else{
		/*butt is closer*/
		index = ptr->size - index;
		ele = ptr->butt;
		for(n=0;n<index;n++){
			ele = ele->last;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		nele->last = ele->last;
		nele->next = ele;
		nele->last->next = nele;
		ele->last = nele;
	}
	nele->value.integer = val;
}

void ArrayListInsertFloat(ArrayList *ptr,int index,float val){
	if(Is_This_First_Element_Of_Array_List(ptr)){
		ArrayListAddFloat(ptr,val);
		return;
	}
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_FLOAT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	int n;
	struct ArrayElement *ele;
	struct ArrayElement *nele;
	if(ptr->size < index || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return;
	}else if(ptr->size == index){
		/*means add*/
		ArrayListAddFloat(ptr,val);
		return;
	}else if(ptr->size / 2 > index){
		/*head is closer*/
		ele = ptr->head;
		for(n=0;n<index;n++){
			ele = ele->next;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		if(ele->last != NULL){
			ele->last->next = nele;
			nele->last = ele->last;
			ele->last = nele;
			nele->next = ele;
		}else{
			/*ele->last == NULL arraylist.insert(0);*/
			ele->last = nele;
			nele->next = ele;
			ptr->head = nele;
		}
	}else{
		/*butt is closer*/
		index = ptr->size - index;
		ele = ptr->butt;
		for(n=0;n<index;n++){
			ele = ele->last;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		nele->last = ele->last;
		nele->next = ele;
		nele->last->next = nele;
		ele->last = nele;
	}
	/*Reaching here means operation had been executed correctly*/
	ptr->size++;
	nele->value.floating = val;
}

void ArrayListInsertPtr(ArrayList *ptr,int index,void *val){
	if(Is_This_First_Element_Of_Array_List(ptr)){
		ArrayListAddPtr(ptr,val);
		return;
	}
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_PTR)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return;
	}
	int n;
	struct ArrayElement *ele;
	struct ArrayElement *nele;
	if(ptr->size < index || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return;
	}else if(ptr->size == index){
		/*means add*/
		ArrayListAddPtr(ptr,val);
		return;
	}else if(ptr->size / 2 > index){
		/*head is closer*/
		ele = ptr->head;
		for(n=0;n<index;n++){
			ele = ele->next;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		if(ele->last != NULL){
			ele->last->next = nele;
			nele->last = ele->last;
			ele->last = nele;
			nele->next = ele;
		}else{
			/*ele->last == NULL arraylist.insert(0);*/
			ele->last = nele;
			nele->next = ele;
			ptr->head = nele;
		}
	}else{
		/*butt is closer*/
		index = ptr->size - index;
		ele = ptr->butt;
		for(n=0;n<index;n++){
			ele = ele->last;
		}
		if((nele = newArrayElement())==NULL){
			ptr->flag |= ARRAYLIST_ERROR;
			ptr->errMsg = ARRAYLIST_ER_MSG_MALLOC;
			return;
		}
		nele->last = ele->last;
		nele->next = ele;
		nele->last->next = nele;
		ele->last = nele;
	}
	/*Reaching here means operation had been executed correctly*/
	ptr->size++;
	nele->value.ptr = val;
}

long ArrayListGetInt(ArrayList *ptr,int index){
	struct ArrayElement *ele;
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_INT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return 0;
	}
	if(index >= ArrayListGetSize(ptr) || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return 0;
	}else if(index < ArrayListGetSize(ptr) / 2){
		/*head is closer*/
		ele = ptr->head;
		while(index > 0){
			ele = ele->next;
			index--;
		}
	}else{
		ele = ptr->butt;
		index = ArrayListGetSize(ptr) - index - 1;
		while(index > 0){
			ele = ele->last;
			index--;
		}
	}
	return ele->value.integer;
}
double ArrayListGetFloat(ArrayList *ptr,int index){
	struct ArrayElement *ele;
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_FLOAT)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return 0;
	}
	if(index >= ArrayListGetSize(ptr) || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return 0;
	}else if(index < ArrayListGetSize(ptr) / 2){
		/*head is closer*/
		ele = ptr->head;
		while(index > 0){
			ele = ele->next;
			index--;
		}
	}else{
		ele = ptr->butt;
		index = ArrayListGetSize(ptr) - index - 1;
		while(index > 0){
			ele = ele->last;
			index--;
		}
	}
	return ele->value.floating;
}
void * ArrayListGetPtr(ArrayList *ptr,int index){
	struct ArrayElement *ele;
	if(!CHECK_ARRAYLIST_VARIABLE_TYPE(ptr,ARRAYLIST_ET_PTR)){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_WRONG_VARIABLE;
		return NULL;
	}
	if(index >= ArrayListGetSize(ptr) || index < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return 0;
	}else if(index < ArrayListGetSize(ptr) / 2){
		/*head is closer*/
		ele = ptr->head;
		while(index > 0){
			ele = ele->next;
			index--;
		}
	}else{
		ele = ptr->butt;
		index = ArrayListGetSize(ptr) - index - 1;
		while(index > 0){
			ele = ele->last;
			index--;
		}
	}
	return ele->value.ptr;
}
/*Does not free pointer that this function have*/
void ArrayListDeleteAt(ArrayList *ptr,int index){
	struct ArrayElement *ele;
	register int size = ArrayListGetSize(ptr);
	if(size <= index || size < 0){
		ptr->flag |= ARRAYLIST_ERROR;
		ptr->errMsg = ARRAYLIST_ER_MSG_OUTOFRANGE;
		return;
	}
	if(index == 0 && size == 1){
		free(ptr->head);
		ptr->butt = NULL;
		ptr->head = NULL;
		ptr->size--;
		return;
	}else if(index == 0){
		ele = ptr->head;
		ptr->head = ele->next;
		free(ele);
		ptr->size--;
		return;
	}else if(index == size - 1){
		ele = ptr->butt;
		ptr->butt = ele->last;
		free(ele);
		ptr->size--;
		return;
	}else if(size / 2 > index){
		while(index > 0){
			ele = ele->next;
			index--;
		}
	}else{
		index = size - index - 1;
		while(index > 0){
			ele = ele->next;
			index--;
		}
	}
	ele->last->next = ele->next;
	ele->next->last = ele->last;
	free(ele);
	ptr->size--;
}

StringBuilder * new_StringBuilder(){
    return calloc(1,sizeof(StringBuilder));
}
void StringBuilder_append(StringBuilder *ptr,struct StringBuilder_ele *ele){
    if(ptr->butt != NULL){
        ptr->butt->next = ele;
        ptr->butt = ele;
    }else{
        ptr->butt = ele;
        ptr->head = ele;
    }
}
void StringBuilder_append_char(StringBuilder *ptr,char c){
    struct StringBuilder_ele *ele = calloc(1,sizeof(struct StringBuilder_ele));
    ele->type = STRINGBUILDER_TYPE_CHAR;
    ele->val.c = c;
    StringBuilder_append(ptr,ele);
    (ptr->size)++;
}

void StringBuilder_append_str(StringBuilder *ptr,const char *str){
    int size = strlen(str);
    ptr->size += size;
    size++;
    struct StringBuilder_ele *ele = malloc(sizeof(struct StringBuilder_ele));
    ele->type = STRINGBUILDER_TYPE_STR;
    ele->val.str = malloc(size);
    ele->size = size;
    strcpy(ele->val.str,str);
    StringBuilder_append(ptr,ele);
}

size_t StringBuilder_getSize(StringBuilder *ptr){
    return ptr->size;
}
char * StringBuilder_toString(StringBuilder *ptr){
    char *buff = malloc(ptr->size + 1);
    char *buff_head = buff;
    struct StringBuilder_ele *ele = ptr->head;
    while(ele!= NULL){
        if(ele->type == STRINGBUILDER_TYPE_CHAR){
            *buff++ = ele->val.c;
        }else{
            size_t cou;
            size_t to = ele->size;
            char *str = ele->val.str;
            for(cou = 0;cou < to;cou++){
                *buff++ = *str++;
            }
        }
        ele = ele->next;
    }
    *buff = 0;
    return buff;
}
void StringBuilder_free(StringBuilder *builder){
    struct StringBuilder_ele *ele = builder->head;
    struct StringBuilder_ele *tmp;
    while(ele!=NULL){
        tmp = ele->next;
        if(ele->type == STRINGBUILDER_TYPE_CHAR){
            free(ele);
        }else{
            free(ele->val.str);
            free(ele);
        }
        free(ele);
        ele = tmp;
    }
    free(builder);
}

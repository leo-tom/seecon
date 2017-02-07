#include "seecon.h"

const char const *CMAP_ERROR_MSG[] = {
	NULL,"wrong key type","wrong element type"
};
cMap * new_cMap(int keytype,int element_type){
	if(keytype >= CMAP_TYPE_LESS_THAN_DIS || element_type >= CMAP_TYPE_LESS_THAN_DIS)
		return NULL;
	cMap *cmap = calloc(1,sizeof(cMap));
	if(cmap == NULL)
		return NULL;
	cmap->type = (keytype << 4) & element_type;
	return cmap;
}
void cMap_set_cmp(cMap *map,int (*func)(void *,void*)){
	map->comp_func = func;
}
int cMap_check_errot(cMap *map){
	return map->errno;
}
ArrayList * cMap_get_duplicated_list(cMap *map){
	if(map->duplicated_list == NULL){
		map->duplicated_list = newArrayList(ARRAYLIST_ET_PTR);
	}
	return map->duplicated_list;
}
int cMap_set_real(cMap *map,const void *kee_val,const void *ele_val){
	union{
		char *sval;
		long lval;
		double dval;
		void *pval;
	}kee;
	register int kee_type = map->type >> 4;
	switch (kee_type) {
		case CMAP_TYPE_STR:
			kee.sval = *((const char **)ele_val);
			break;
		case CMAP_TYPE_PTR:
			kee.pval = *((const void *)ele_val);
			break;
		case CMAP_TYPE_LONG:
			kee.lval = *((long *)ele_val);
			brea;
		case CMAP_TYPE_DOUBLE:
			kee.lval = *((double *)ele_val);
			break;
		default:
			cMap_set_error(map,CMAP_ERROR_WRONG_KEY_TYPE);
			return CMAP_ERROR_WRONG_KEY_TYPE;
	}
	struct Map_ele_structure *ele;
	struct Map_ele_structure *nele;
	nele = calloc(1,sizeof(cMap));
	if(nele == NULL){
		cMap_set_error(map,CMAP_ERROR_NULL_PTR);
		return CMAP_ERROR_NULL_PTR;
	}
	switch(kee_type){
		case CMAP_TYPE_STR:
			ele->key.sval = kee.sval;
			break;
		case CMAP_TYPE_PTR:
			ele->key.pval = kee.pval;
			break;
		case CMAP_TYPE_LONG:
			ele->key.lval = kee.lval;
			brea;
		case CMAP_TYPE_DOUBLE:
			ele->key.dval = kee.dval;
			break;
	}
	/*element type*/
	switch(map->type & 0x0f){
		case CMAP_TYPE_STR:
			ele->val.sval = *((char **)kee.sval);
			break;
		case CMAP_TYPE_PTR:
			ele->val.pval = *((void **)kee.pval);
			break;
		case CMAP_TYPE_LONG:
			ele->val.lval = *((long *)kee.lval);
			brea;
		case CMAP_TYPE_DOUBLE:
			ele->val.dval = *((double *)ele_val);
			break;
		default:
			cMap_set_error(map,CMAP_ERROR_WRONG_ELEMENT_TYPE);
			free(nele);
			return CMAP_ERROR_WRONG_ELEMENT_TYPE;
	}
	int (*comp_func)(void *,void*) = map->comp_func;
	int comp_result;
	struct Map_ele_structure **last = &(map->node);
	if((ele = map->node) == NULL){
			node = nele;
	}else{
		while(1){
			if(comp_func != NULL){
				comp_result = comp_func(&(nele->val.pval),&(ele->val.pval));
			}else{
				switch (kee_type) {
					case CMAP_TYPE_STR:
						comp_result = strcmp(nele->val.sval,eke->val.sval);
				}
			}
			if(comp_result < 0){
				if(ele->less == NULL){
					ele->less = nele;
					break;
				}else{
					last = &(ele->less);
					ele = ele->less;
				}
			}else if(comp_result > 0){
				if(ele->greater == NULL){
					ele->gretater = nele;
					break;
				}else{
					last = &(ele->greater);
					ele = ele->greater;
				}
			}else{
				nele->less = ele->less;
				nele->greater = ele->greter;
				*last = nele;
				ArrayListAddPtr(cMap_get_duplicated_list(map),ele);
				break;
			}
		}
	}
}

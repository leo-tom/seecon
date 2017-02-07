#include "seecon.h"

const char const *CMAP_ERROR_MSG[] = {
	NULL,"wrong key type","wrong element type"
};
/*set funcs*/

const void *CMAP_FUNCS[] = {
  /*str kee*/
  const void ()(void *,void *)[] = {
      const void ()(void *,void *); /*str val*/
      const void ()(void *,void *); /*long*/
      const void ()(void *,void *); /*double*/
      const void ()(void *,void *); /*ptr*/
  };

};
const void (CMAP_SET_FUNCS_)
/*This macro is able to change function that cMap call dynamically*/

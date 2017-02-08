#include "seecon.h"

main(){
  ArrayList *list = newArrayList(ARRAYLIST_ET_INT);
  ArrayListAddInt(list,1);
  ArrayListAddInt(list,5);
  ArrayListAddInt(list,10);
  int i;
  for(i=0;i<ArrayListGetSize(list);i++){
    printf("%ld\n", ArrayListGetInt(list,i));
  }
  freeArrayList(list);
  StringBuilder *builder = new_StringBuilder();
  StringBuilder_append_str(builder,"This");
  StringBuilder_append_char(builder,' ');
  StringBuilder_append_str(builder,"is test");
  char *str = StringBuilder_toString(builder);
  printf("%s\n", str);
  StringBuilder_free(builder);
  free(str);
}

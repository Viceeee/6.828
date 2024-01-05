#include <stdio.h>
int main(){
	char *null_ptr=NULL;
//	printf("address = %p = %s\n",(void*)null_ptr, null_ptr);
//what happens if next line?

	printf("address = %p = %c\n",(void*)null_ptr, *null_ptr);
}

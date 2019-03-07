#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <time.h>

time_t time(time_t *tlo){
time_t (*newtime) (time_t *tloc);
newtime = dlsym(RTLD_NEXT, "time");
if(*tlo == (time_t)1487642091 ){	

	printf("Real\n");
	*tlo = (*newtime)(NULL);
	return (*newtime)(NULL);
}
else
{
	printf("Fake\n");
	*tlo = (time_t)1487642091;
	return (time_t)1487642091;
}

}
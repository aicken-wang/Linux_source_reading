#include <unistd.h>

#include <sys/syscall.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sysctl.h>

int _sysctl(struct __sysctl_args *args);

#define OSNAMESZ 100
int main(void)
{
    struct __sysctl_args args;
    char osname[OSNAMESZ];
    size_t osname1th;
    int name[] ={CTL_KERN,KERN_OSTYPE};
    
    memset(&args, 0, sizeof(struct __sysctl_args));
    args.name = name;
    args.nlen = sizeof(name)/sizeof(name[0]);
    args.oldval = osname;
    args.oldlenp = &osname1th;
    osname1th = sizeof(osname);
    if( syscall(SYS__sysctl, &args) == -1) {
        perror("_sysctl");
        exit(EXIT_FAILURE);
    }
    printf("this machine is runing %*s\n", osname1th, osname);
    exit(EXIT_SUCCESS);
}
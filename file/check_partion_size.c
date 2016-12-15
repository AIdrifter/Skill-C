#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <stdint.h>

int main()
{
    struct statvfs vfsbuf;
    int error = statvfs("./",&vfsbuf);
    unsigned long u64FreeSpaceInKB = (((uint64_t)vfsbuf.f_bfree * (uint64_t)vfsbuf.f_frsize) / 1024);
    printf(" partion free size  is %lu\n",u64FreeSpaceInKB);
}

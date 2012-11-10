#include "apue.h"
#include "../apue.2e/lib/error.c"
#include <fcntl.h>
#include <sys/mman.h>

#ifndef FILEMODE
#define FILEMODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP | S_IXOTH)
#endif

int main(int argc, const char *argv[])
{
	int fdin, fdout;
	void *src, *dst;
	struct stat statbuf;

	if (argc != 3) 
	    err_quit("usage: %s <fromfile> <tofile>", argv[0]);
	if ((fdin = open(argv[1], O_RDONLY)) < 0) 
	    err_quit("can't open %s for reading", argv[1]);
	if ((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILEMODE)) < 0) err_sys("can't create %s for writing", argv[2]);

	if ((fstat(fdin, &statbuf)) < 0) 
	    err_sys("fstat error");

	if (lseek(fdout, statbuf.st_size-1, SEEK_SET) == -1) 
	    err_sys("lseek error");
	if (write(fdout, "", 1) != 1) 
	    err_sys("write error");

	if ((src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0)) == MAP_FAILED) 
	    err_sys("mmap error for output");

	if ((dst = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED) 
	    err_sys("mmap error for output");
	memcpy(dst, src, statbuf.st_size);
	return 0;
}

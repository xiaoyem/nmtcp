/*
 * Portions of this software are covered by the following copyright:
 *
 * Copyright (c) 1995, 1998 Douglas E. Comer, David L. Stevens, and
 * Prentice Hall, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the copyright holders. The names of the copyright holders
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty. The authors
 * assume no liability for damages incidental or consequential, nor is the
 * software warranted for correctness or suitability for any purpose.
 *	Portions of this software are documented in the book:
 *
 *	Internetworking With TCP/IP Vol 2:
 *	Design, Implementation, and Internals
 *
 *	Prentice Hall, Upper Saddle River, New Jersey.
 *	ISBN: 0-13-973843-6
 *
 * This software may not be sold or published in printed form without written
 * permission from the copyright holders.
 */

#include <stdio.h>
#include "ip.h"

int main(int argc, char **argv) {
	ipaddr ia;

	ia = 0x00000000;
	printf("'0.0.0.0'         belongs to Class A: %d\n", IP_CLASSA(ia));
	ia = 0xffffff7f;
	printf("'127.255.255.255' belongs to Class A: %d\n", IP_CLASSA(ia));
	ia = 0x00000080;
	printf("'128.0.0.0'       belongs to Class B: %d\n", IP_CLASSB(ia));
	ia = 0xffffffbf;
	printf("'191.255.255.255' belongs to Class B: %d\n", IP_CLASSB(ia));
	ia = 0x000000c0;
	printf("'192.0.0.0'       belongs to Class C: %d\n", IP_CLASSC(ia));
	ia = 0xffffffdf;
	printf("'223.255.255.255' belongs to Class C: %d\n", IP_CLASSC(ia));
	ia = 0x000000e0;
	printf("'224.0.0.0'       belongs to Class D: %d\n", IP_CLASSD(ia));
	ia = 0xffffffef;
	printf("'239.255.255.255' belongs to Class D: %d\n", IP_CLASSD(ia));
	ia = 0x000000f0;
	printf("'240.0.0.0'       belongs to Class E: %d\n", IP_CLASSE(ia));
	ia = 0xfffffff7;
	printf("'247.255.255.255' belongs to Class E: %d\n", IP_CLASSE(ia));
	return 0;
}


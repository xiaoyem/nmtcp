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

/*
 * revised by xiaoyem
 */

#include <arpa/inet.h>
#include "ip.h"

/* convert an IP packet header from host to net byte order */
struct ip *iph2net(struct ip *pip) {
	/* NOTE: does not include IP options */
	pip->ip_len     = htons(pip->ip_len);
	pip->ip_id      = htons(pip->ip_id);
	pip->ip_fragoff = htons(pip->ip_fragoff);
	return pip;
}


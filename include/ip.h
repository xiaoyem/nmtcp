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

#define IP_ALEN       4       /* IP address length in bytes (octets) */
typedef unsigned long ipaddr; /* internet address                    */

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define IP_CLASSA(x) (((x) & 0x80000000) == 0)          /* IP Class A */
#define IP_CLASSB(x) (((x) & 0xc0000000) == 0x80000000) /* IP Class B */
#define IP_CLASSC(x) (((x) & 0xe0000000) == 0xc0000000) /* IP Class C */
#define IP_CLASSD(x) (((x) & 0xf0000000) == 0xe0000000) /* IP Class D */
#define IP_CLASSE(x) (((x) & 0xf8000000) == 0xf0000000) /* IP Class E */
#else
#define IP_CLASSA(x) (((x) & 0x80) == 0x00)             /* IP Class A */
#define IP_CLASSB(x) (((x) & 0xc0) == 0x80)             /* IP Class B */
#define IP_CLASSC(x) (((x) & 0xe0) == 0xc0)             /* IP Class C */
#define IP_CLASSD(x) (((x) & 0xf0) == 0xe0)             /* IP Class D */
#define IP_CLASSE(x) (((x) & 0xf8) == 0xf0)             /* IP Class E */
#endif

#define IPT_ICMP   1  /* protocol type for ICMP packets */
#define IPT_IGMP   2  /* protocol type for IGMP packets */
#define IPT_TCP    6  /* protocol type for TCP packets  */
#define IPT_EGP    8  /* protocol type for EGP packets  */
#define IPT_UDP    17 /* protocol type for UDP packets  */
#define IPT_OSPF   89 /* protocol type for OSPF packets */

struct ip {
	unsigned char	ip_verlen;  /* IP version & header length (in longs) */
	unsigned char	ip_tos;     /* type of service                       */
	unsigned short	ip_len;     /* total packet length (in octets)       */
	short		ip_id;      /* datagram id                           */
	short		ip_fragoff; /* fragment offset (in 8-octet's)        */
	unsigned char	ip_ttl;     /* time to live, in gateway hops         */
	unsigned char	ip_proto;   /* IP protocol (see IPT_* above)         */
	short		ip_cksum;   /* header checksum                       */
	ipaddr		ip_src;     /* IP address of source                  */
	ipaddr		ip_dst;     /* IP address of destination             */
	unsigned char	ip_data[1]; /* variable length data                  */
};

#define IP_VERSION 4   /* current version value               */
#define IP_MINHLEN 5   /* minimum IP header length (in longs) */
#undef  IP_TTL
#define IP_TTL     255 /* Initial time-to-live value          */

#define IP_MF      0x2000 /* more fragments bit        */
#define IP_DF      0x4000 /* don't fragment bit        */
#define IP_FRAGOFF 0x1fff /* fragment offset mask      */
#define IP_PREC    0xe0   /* precedence portion of TOS */

#define IPP_NETCTL 0xe0 /* network control  */
#define IPP_INCTL  0xc0 /* internet control */
#define IPP_CRIT   0xa0 /* critical         */
#define IPP_FLASHO 0x80 /* flash over-ride  */
#define IPP_FLASH  0x60 /* flash            */
#define IPP_IMMED  0x40 /* immediate        */
#define IPP_PRIO   0x20 /* priority         */
#define IPP_NORMAL 0x00 /* normal           */

/* macro to compute a datagram's header length (in bytes) */
#define IP_HLEN(pip) ((pip->ip_verlen & 0xf) << 2)
#define IPMHLEN      20 /* minimum IP header length (in bytes) */

#define IPO_COPY   0x80 /* copy on fragment mask */
#define IPO_CLASS  0x60 /* option class          */
#define IPO_NUM    0x17 /* option number         */

#define IPO_EOOP   0x00 /* end of options                    */
#define IPO_NOP    0x01 /* no operation                      */
#define IPO_SEC    0x82 /* DoD security/compartmentalization */
#define IPO_LSRCRT 0x83 /* loose source routing              */
#define IPO_SSRCRT 0x89 /* strict source routing             */
#define IPO_RECRT  0x07 /* record route                      */
#define IPO_STRID  0x88 /* stream ID                         */
#define IPO_TIME   0x44 /* internet timestamp                */

/* FIXME */
#define IP_MAXLEN  2024 /* maximum IP datagram length */

/* FIXME */
extern int ipproc();
#define IPSTK      512  /* stack size for IP process */
#define IPPRI      100  /* IP runs at high priority  */
#define IPNAM      "ip" /* name of IP process        */
#define IPARGC     0    /* count of args to IP       */

extern ipaddr ip_maskall;  /* = 255.255.255.255 */
extern ipaddr ip_anyaddr;  /* = 0.0.0.0         */
extern ipaddr ip_loopback; /* = 127.0.0.1       */

extern int ippid, gateway;

struct ip *iph2net(struct ip *), *ipnet2h(struct ip *);
unsigned short cksum(int *, unsigned);
/* int ipsend(ipaddr, struct ep *, unsigned, u_char, u_char, u_char); */
/* int ipputp(unsigned, ipaddr, struct ep *); */
char isbrc(ipaddr);


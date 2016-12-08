/*
 * Copyright (c) 2016, Dalian Futures Information Technology Co., Ltd.
 *
 * Xiaoye Meng <mengxiaoye at dce dot com dot cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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


#
# Copyright (c) 2001, 2002 Swedish Institute of Computer Science.
# All rights reserved. 
# 
# Redistribution and use in source and binary forms, with or without modification, 
# are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission. 
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
# SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
# OF SUCH DAMAGE.
#
# This file is part of the lwIP TCP/IP stack.
# 
# Author: Adam Dunkels <adam@sics.se>
#

all compile: arp_main udp_main icmp_main
.PHONY: all

include ../Common.mk

clean:
	rm -f *.o $(LWIPLIBCOMMON) $(APPLIB) arp_main udp_main icmp_main *.s .depend* *.core core

depend dep: .depend

include .depend

.depend: arp_main.c udp_main.c icmp_main.c $(LWIPFILES) $(APPFILES)
	$(CCDEP) $(CFLAGS) -MM $^ > .depend || rm -f .depend

arp_main: .depend $(LWIPLIBCOMMON) $(APPLIB) arp_main.o $(APPFILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o arp_main arp_main.o $(APPLIB) $(LWIPLIBCOMMON)

udp_main: .depend $(LWIPLIBCOMMON) $(APPLIB) udp_main.o $(APPFILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o udp_main udp_main.o $(APPLIB) $(LWIPLIBCOMMON)

icmp_main: .depend $(LWIPLIBCOMMON) $(APPLIB) icmp_main.o $(APPFILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o icmp_main icmp_main.o $(APPLIB) $(LWIPLIBCOMMON)

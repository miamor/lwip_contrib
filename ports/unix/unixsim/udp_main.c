#include "lwip/opt.h"

#include "lwip/pbuf.h"
//#include "lwip/netif.h"
#include "lwip/udp.h"

unsigned char debug_flags;
#define UDP_HLEN 8

static ip_addr_t src_ip, dst_ip;
static u16_t src_port, dst_port;

/*-----------------------------------------------------------------------------------*/
int main(int argc, char **argv) 
{
    struct udp_pcb * u_pcb;
    struct pbuf *p;

    debug_flags = LWIP_DBG_OFF;
    p = pbuf_alloc(PBUF_IP, UDP_HLEN, PBUF_RAM);

    IP4_ADDR(&src_ip, 192, 168, 0, 2);
    IP4_ADDR(&dst_ip, 192, 168, 0, 3);
    src_port = 80;
    dst_port = 80;
    //udp_bind(u_pcb, &ipaddr, 0);

    /* Associate the UDP PCB with the remote address.
     * Sets the remote end of the pcb. This function does not generate any network traffic, but only set the remote address of the pcb. It binds the pcb to a local address if it is not already bound. It returns ERR_USE if no port is available, ERR_RTE if there is no route to the destination, or ERR_OK. Connecting is only needed when using udp_send(). For unconnected pcbs, udp_sendto() can be used to send to any specified remote address. Connected pcbs only receive data from the connected remote address, while unconected pcbs receive datagrams from any remote address. */
    //udp_connect(u_pcb, &src_ip, 0);

    /* Same as udp_send(), but sends to any remote address. */
    u_pcb = udp_new();
    udp_bind(u_pcb, &src_ip, src_port);
    udp_connect(u_pcb, &src_ip, src_port);

    u8_t tos = 10;
    udp_sendto_if_src_packet(u_pcb, p, &dst_ip, dst_port, &src_ip, tos);
}
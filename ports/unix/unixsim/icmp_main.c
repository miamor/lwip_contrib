#include "lwip/opt.h"

#include "lwip/netif.h"


static ip_addr_t src_ip, dst_ip;
static u16_t src_port, dst_port;

/*-----------------------------------------------------------------------------------*/
int main(int argc, char **argv) 
{
    struct udp_pcb * u_pcb;
    struct pbuf *p;

    IP4_ADDR(&src_ip, 192, 168, 0, 2);
    IP4_ADDR(&dst_ip, 192, 168, 0, 3);
    src_port = 80;
    dst_port = 80;
    //udp_bind(u_pcb, &ipaddr, 0);
    
    //icmp_received_packet(p, 0);
}
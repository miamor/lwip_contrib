#include "lwip/opt.h"

#include "lwip/netif.h"
#include "lwip/pbuf.h"
#include "netif/etharp.h"


static ip_addr_t ipaddr, netmask, gw, ipaddr_ask;

err_t ethw_init(struct netif *netif);
  
unsigned char debug_flags;

#define ETHARP_HWADDR_LEN 6

int hwaddr_len;
unsigned char hwaddr[ETHARP_HWADDR_LEN];

static struct pbuf* p;

/*-----------------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    //char ip_str[16] = {0}, nm_str[16] = {0}, gw_str[16] = {0};
    
    /* use debug flags defined by debug.h */
    debug_flags = LWIP_DBG_OFF;

    /* Network interface variables */
    //struct netif netif;
    /* Set network address variables */
    IP4_ADDR(&gw, 192, 168, 0, 1);
    IP4_ADDR(&ipaddr, 192, 168, 0, 2);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&ipaddr_ask, 192, 168, 0, 2);

    /* The lwIP single-threaded core: initialize the network stack */
    //lwip_init();
    /* Bring up the network interface */
    /* Hint: netif_init(); was already called by lwip_init(); above */
    //netif_add(&netif, &ipaddr, &netmask, &gw, NULL);
    
    /* ethhw_init() is user-defined */
    /* use ip_input instead of ethernet_input for non-ethernet hardware */
    /* (this function is assigned to netif.input and should be called by the hardware driver) */

    /*netif_set_default(&netif);
    netif_set_up(&netif);*/

    //pbuf_alloc(PBUF_RAW, SIZEOF_ETHARP_PACKET, PBUF_RAM);
    // get an ARP packet to ask MAC adr of ipaddr
    hwaddr_len = ETHARP_HWADDR_LEN;

    /* set MAC hardware address */
    hwaddr[0] = 0xAC;
    hwaddr[1] = 0xD1;
    hwaddr[2] = 0xB8;
    hwaddr[3] = 0xCC;
    hwaddr[4] = 0x0C;
    hwaddr[5] = 0x3B;


    //p = NULL;
    //p = pbuf_alloc(PBUF_RAW, SIZEOF_ETHARP_PACKET, PBUF_RAM);
    p = pbuf_alloc(PBUF_LINK, SIZEOF_ETHARP_HDR, PBUF_RAM);
    //etharp_request_packet(&p, (struct eth_addr *)hwaddr, &ipaddr, &ipaddr_ask);
    pbuf_free(p);
}
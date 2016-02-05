#include <stdlib.h>
#include <arpa/inet.h>
#include "apr_network_io.h"
#include "apr_pools.h"

/**
 * # gcc lookup.c -o lookup $(apr-1-config --cflags --cppflags --includes --link-ld)
 * # ./lookup google.com 80
 * 
 * @author bostrt
 */
int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Usage: %s host port\n", argv[0]);
    return APR_EGENERAL;
  }
  
  apr_status_t rv;
  apr_pool_t *pool;
  apr_pool_t *pool_data;
  apr_sockaddr_t *addr;
  char *host = argv[1];
  apr_port_t port = atoi(argv[2]);

  rv = apr_initialize();
  if (rv != APR_SUCCESS) {
    printf("APR apr_initialize err\n");
    return APR_EGENERAL;
  }
  
  apr_pool_create(&pool_data, NULL);
  apr_pool_create(&pool, NULL);

  rv = apr_sockaddr_info_get(&addr, host, APR_UNSPEC, port, APR_IPV4_ADDR_OK, pool);

  if (rv != APR_SUCCESS) {
    printf("APR apr_sockaddr_info_get err\n");
    return APR_EGENERAL;
  }

  printf("%s:%d => %s\n", addr->hostname, addr->port, inet_ntoa(addr->sa.sin.sin_addr));

  apr_pool_destroy(pool);
  apr_pool_destroy(pool_data);
  apr_terminate();

  return APR_SUCCESS;
}

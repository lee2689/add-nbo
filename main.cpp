#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char **argv){

    FILE *fp;
    FILE *fb;
    char data[] = {0,};

    fp = fopen(argv[1], "rb");
    fb = fopen(argv[2], "rb");

    fread(data, 50, 1, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(data);
    uint32_t n = ntohl(*p);

    fread(data, 50, 1, fb);
    uint32_t* p2 = reinterpret_cast<uint32_t*>(data);
    uint32_t n2 = ntohl(*p2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n, n, n2, n2, n+n2, n+n2);

    fclose(fp);
    fclose(fb);
}

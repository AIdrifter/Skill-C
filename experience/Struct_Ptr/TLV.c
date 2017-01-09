#include <stdio.h>
#include <stdlib.h>

/* TLV  Type Length Value */

struct tlvs
{
    int t;
    int l;
    char v[0];
};

int add_tlv(char *dst, enum TLV_TYPE type, int len, char *value);
void handle_tlv(char *data, int size);

int main(){
    offset += add_tlv(buf+offset, TYPE_0, strlen(STR1), STR1);
    offset += add_tlv(buf+offset, TYPE_1, strlen(STR2), STR2);
    offset += add_tlv(buf+offset, TYPE_2, strlen(STR3), STR3);
    handle_tlv(buf, offset);
}

typedef void (*type_foo)(char *data, int len);
type_foo foo[] =
{
    type0_bar,
    type1_bar,
    type2_bar,
};

int add_tlv(char *dst, enum TLV_TYPE type, int len, char *value)
{
    struct tlvs *tlv = (struct tlvs *)dst;

    tlv->t = type;
    tlv->l = len;
    memcpy(tlv->v, value, len);

    return (sizeof(struct tlvs)+len);
}


void handle_tlv(char *data, int size)
{
    int offset = 0;
    while(size){
        struct tlvs *tlv = (struct tlvs *)(data+offset);
        int data_len = sizeof(struct tlvs) + tlv->l;
        foo[tlv->t](tlv->v, tlv->l);
        offset += data_len;
        size -= data_len;
    }
}


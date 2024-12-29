#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char *argv[])
{
    int ret = check_operation_type(argv);
    if(ret == e_encode){
        printf("Selected Encoding\n");
        EncodeInfo encInfo;
        if(read_and_validate_encode_args(argv, &encInfo) == e_success){
            printf("Read and validation is successfully completed\n");
            do_encoding(&encInfo);
        }
        else{
            printf("Read and validation failed\n");
        }
    }
    else if(ret == e_decode){
        printf("Selected Decoding\n");
        DecodeInfo decInfo;
        if(read_and_validate_decode_args(argv, &decInfo) == e_success){
            printf("Read and validation is successfully completed\n");
            do_decoding(&decInfo);
        }
        else{
            printf("Read and validation failed\n");
        }
    }
    else{
        printf("ERROR : Select either encoding or decoding\n");
    }
}
OperationType check_operation_type(char *argv[]){
    /* check if argv[1] is -e or not*/
    if(strcmp(argv[1], "-e")==0){
        return e_encode;
    }
    else if(strcmp(argv[1], "-d")==0){
        return e_decode;
    }
    else{
        return e_unsupported;
    }
}
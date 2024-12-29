#include "decode.h"

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo){
    if((strstr(argv[2], ".bmp")) != NULL){
        printf("It is bmp file\n");
        decInfo->output_image_fname = argv[2];
    }
    else{
        return e_failure;
    }
    if(argv[3] != NULL){
        decInfo->decoded_secret_fname = malloc(strlen(argv[3]) + MAX_FILE_SUFFIX + 1);
        strcpy(decInfo->decoded_secret_fname, argv[3]);
    }
    else{
        decInfo->decoded_secret_fname = malloc(strlen("O_Secret") + MAX_FILE_SUFFIX + 1);
        strcpy(decInfo->decoded_secret_fname, "O_Secret");
    }
    return e_success;
}

Status do_decoding(DecodeInfo *decInfo){
    if(open_file(decInfo)==e_success){
        printf("Opened output image file successfully\n");
        if(decode_magic_string(decInfo) == e_success){
            printf("Decoded magic string and user's magic string matches successfully\n");
            if(decode_secret_file_extn_size(decInfo)==e_success){
                printf("Decoded secret file extn size successfully\n");
                if(decode_secret_file_extn(decInfo)==e_success){
                    printf("Successfully decoded the secret file extn\n");
                    if(open_output_file(decInfo) == e_success){
                        printf("Opened result output file successfully\n");
                        if(decode_secret_file_size(decInfo) == e_success){
                            printf("Successfully decoded secret file size\n");
                        }
                        else{
                            printf("Failed to decode secret file size\n");
                        }
                    }
                    else{
                        printf("Failed to open result output file\n");
                    }
                }
                else{
                    printf("Failed to decode secret file extn\n");
                }
            }
            else{
                printf("Failed to decode secret file extn\n");
            }
        }
        else{
            printf("Failed to decode magic string\n");
        }
    }
    else{
        printf("Failed to open output image file\n");
    }   
}


Status open_file(DecodeInfo *decInfo)
{
    // output Image file
    decInfo->fptr_output_image = fopen(decInfo->output_image_fname, "r");
    // Do Error handling
    if (decInfo->fptr_output_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->output_image_fname);
    	return e_failure;
    }
    fseek(decInfo->fptr_output_image, 54, SEEK_SET);
    return e_success;
}

Status decode_magic_string(DecodeInfo *decInfo){
    char magic_string[3] = {0};
    char user_magic_string[3];
    char arr[8];
    for(int i=0; i<2; i++){
        fread(arr, 8, 1, decInfo->fptr_output_image);
        magic_string[i] = decode_char_from_lsb(arr);
    }
    printf("Enter the magic string : \n");
    scanf("%[^\n]", user_magic_string);
    if(strcmp(magic_string, user_magic_string)==0){
        printf("The entered magic string is correct.\tThe magic string is %s\n",magic_string);
    }
    else{
        printf("The user entered magic string doesn't match with actual magic string\n");
        return e_failure;
    }
    return e_success;
}

Status decode_char_from_lsb(char *arr){
    char data = 0;
    for(int i=0; i<8; i++){
        data = data | ((arr[i]&1) << (7-i));
    }
    return data;
}

Status decode_int_from_lsb(int *data, char *arr){
    *data = 0;
    for(int i=0; i<32; i++){
        *data = *data | ((arr[i]&1) << (31-i));
    }
    return e_success;
}

Status decode_secret_file_extn_size(DecodeInfo *decInfo){
    int data;
    char arr[32];
    fread(arr, 32, 1, decInfo->fptr_output_image);
    decode_int_from_lsb(&data, arr);
    decInfo->secret_file_extn_size = data;
    printf("The secret file extn size is %d\n",data);
    return e_success;
}

Status decode_secret_file_extn(DecodeInfo *decInfo){
    // printf("%d\n", decInfo->secret_file_extn_size);
    char extn[decInfo->secret_file_extn_size + 1];
    char arr[8];
    for(int i=0; i < decInfo->secret_file_extn_size; i++){
        fread(arr, 8, 1, decInfo->fptr_output_image);
        extn[i] = decode_char_from_lsb(arr);
    }
    printf("%s\n", extn);
    strcat(decInfo->decoded_secret_fname, extn);
    printf("%s\n",decInfo->decoded_secret_fname);
    return e_success;
}

Status open_output_file(DecodeInfo *decInfo)
{
    // output file
    decInfo->fptr_decoded_secret = fopen(decInfo->decoded_secret_fname, "w");
    // Do Error handling
    if(decInfo->fptr_decoded_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decoded_secret_fname);
    	return e_failure;
    }
    return e_success;
}

Status decode_secret_file_size(DecodeInfo *decInfo){
    int data;
    char arr[32];
    fread(arr, 32, 1, decInfo->fptr_output_image);
    decode_int_from_lsb(&data, arr);
    decInfo->secret_file_size = data;
    printf("The secret file size is %d\n",data);
    return e_success;
}
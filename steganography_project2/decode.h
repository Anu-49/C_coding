#ifndef DECODE_H
#define DECODE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types.h"

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
    /* Output Image info */
    char *output_image_fname; // stores output.bmp file name
    FILE *fptr_output_image; // pointer for output.bmp file
    int secret_file_extn_size; // store secret file extn size after decoding
    int secret_file_size; // store secret file size after decoding
    // char image_data[MAX_IMAGE_BUF_SIZE];

    /* Output File Info */
    // char *secret_fname;
    // FILE *fptr_secret;
    // char extn_secret_file[MAX_FILE_SUFFIX];
    // char secret_data[MAX_SECRET_BUF_SIZE];
    // long size_secret_file;

    /* Output File Info */
    char *decoded_secret_fname;
    FILE *fptr_decoded_secret;

} DecodeInfo;

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

Status do_decoding(DecodeInfo *decInfo);

Status open_file(DecodeInfo *decInfo);

Status decode_magic_string(DecodeInfo *decInfo);

Status decode_char_from_lsb(char *arr);

Status decode_int_from_lsb(int *data, char *arr);

Status decode_secret_file_extn_size(DecodeInfo *decInfo);

Status decode_secret_file_extn(DecodeInfo *decInfo);

Status open_output_file(DecodeInfo *decInfo);

Status decode_secret_file_size(DecodeInfo *decInfo);

#endif

// /* Encoding function prototype */

// /* Check operation type */
// OperationType check_operation_type(char *argv[]);

// /* Read and validate Encode args from argv */
// Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo);

// /* Perform the encoding */
// Status do_encoding(EncodeInfo *encInfo);

// /* Get File pointers for i/p and o/p files */
// Status open_files(EncodeInfo *encInfo);

// /* check capacity */
// Status check_capacity(EncodeInfo *encInfo);

// /* Get image size */
// uint get_image_size_for_bmp(FILE *fptr_image);

// /* Get file size */
// uint get_file_size(FILE *fptr);

// /* Copy bmp image header */
// Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);

// /* Store Magic String */
// Status encode_magic_string(char *magic_string, EncodeInfo *encInfo);

// Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo);

// /* Encode secret file extenstion */
// Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo);

// /* Encode secret file size */
// Status encode_secret_file_size(long file_size, EncodeInfo *encInfo);

// /* Encode secret file data*/
// Status encode_secret_file_data(EncodeInfo *encInfo);

// /* Encode function, which does the real encoding */
// Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image);

// /* Encode a byte into LSB of image data array */
// Status encode_byte_to_lsb(char data, char *image_buffer);

// Status encode_size_to_lsb(int data, char *image_buffer);

// /* Copy remaining image bytes from src to stego image after encoding */
// Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);

// #endif

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stddef.h>

#define HTTP_MAX_REQUEST_LEN 8192*4 
#define HTTP_METHOD_MAX_LEN 8
#define HTTP_PATH_MAX_LEN 2048
#define HTTP_PROTOCOL_MAX_LEN 16
#define HTTP_PROTOCOL_VER "HTTP/1.1"

typedef enum {
    HTTP_PARSE_INVALID,
    HTTP_INVALID_PROTOCOL,
    HTTP_PARSE_OK
} http_parse_e;

typedef struct {
    char method[HTTP_METHOD_MAX_LEN];
    char path[HTTP_PATH_MAX_LEN];
    char protocol[HTTP_PROTOCOL_MAX_LEN];
} http_request;

http_parse_e read_http_request(int socket_fd, http_request *request);

#endif


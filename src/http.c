#include "http.h"
#include "util.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>

http_parse_e read_http_request(int socket_fd, http_request *request) {
    char buffer[HTTP_MAX_REQUEST_LEN] = {0};
    ssize_t bytes_read = read(socket_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) {
        printf("read bytes: %ld\n", bytes_read);
        return HTTP_PARSE_INVALID;
    }

    buffer[bytes_read] = '\0';
    if (sscanf(buffer, "%7s %2047s %15s", request->method, request->path, request->protocol) != 3) {
        return HTTP_PARSE_INVALID;
    }

    if (strcmp(request->protocol, HTTP_PROTOCOL_VER) != 0) {
        return HTTP_INVALID_PROTOCOL;
    }

    return HTTP_PARSE_OK;
}



/*
Practice for calling API's from C

Cat API's as a test.

gcc -o restapi restapi.c -lcurl
*/

#include <stdlib.h> 
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>


typedef struct {
    char *string;
    size_t size;
} Response;


/*  This is what libcurl expects. Used to write to our Response struct. */
size_t write_chunk(void *data, size_t size, size_t nmeb, void *userdata);


int main() {
    CURL *curl = curl_easy_init();
    CURLcode result;
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl\n");
        return EXIT_FAILURE;
    }
    
    Response response;
    response.string = malloc(1);
    response.size   = 0;


    /* Setup the API call*/
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_chunk);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &response); // So write_chunk gets it


    result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return EXIT_FAILURE;
    }


    printf("%s\n\n\n", response.string);


    // Cleanup
    free(response.string);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}


size_t write_chunk(void *data, size_t size, size_t nmemb, void *userdata) {

    // Update the size of the response.
    size_t real_size = size * nmemb;

    Response* response = (Response *) userdata; // Our passed in variable

    char *ptr = realloc(response->string, response->size + real_size+1);

    if (ptr == NULL) {
        /* Function failed due to size not returning properly */
        return 0; 
    }
    
    response->string = ptr;
    // memcpy at the end of the response->string
    memcpy(&(response->string[response->size]), data, real_size);
    response->size += real_size;
    response->string[response->size] = '\0';

    return real_size;
}


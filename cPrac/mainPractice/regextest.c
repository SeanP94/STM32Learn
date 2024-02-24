/* Regex to capture multiple groups */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>


int re_match(char * str);
char* re_find(char * str);
char* re_findall(char * str);



void print_result(int return_value){
  if (return_value == 0){
    printf("Pattern found.\n");
  }
  else if (return_value == REG_NOMATCH){
    printf("Pattern not found.\n");
  }
  else{
    printf("An error occured.\n");
  }
}



int main() {
    
    regex_t regex;
    // char *addr = "1234 Super Street,\n SuperCity CA 92420;1235 Super Street,\n SuperCity CA 92420";
    char *addr = "Super Street,Street,Street,Street,";
    char *subStr;
    // char *re_pattern = "[a-zA-Z0-9 ]+";
    char *re_pattern = "[a-zA-Z ]+,";
    size_t max_groups = 5;
    size_t max_matches = 100;
    
    
    
    
    /* Compile regex pattern. */
    if (regcomp(&regex, re_pattern, REG_EXTENDED)) {
        printf("Failed to compile regular expression.\n");
        return EXIT_FAILURE;   
    }

    subStr = addr;
    for (size_t j = 0; j < max_matches; ++j ) {
        /* If no more matches, break out */
        regmatch_t groups[max_groups];
        if (regexec(&regex, subStr, max_groups, groups, 0)) break;
        
        size_t subStr_offset = 0;    
        for (size_t i = 0; i < max_groups; ++i) {
            if (groups[i].rm_so == (size_t) -1) break; 

            if (i == 0) subStr_offset = groups[i].rm_eo;


            char single_addr[strlen(subStr)+1];
            strcpy(single_addr, subStr);
            single_addr[groups[i].rm_eo] = 0;
            printf("Address : %s\n", single_addr + groups[i].rm_so);
            
        }
        subStr += subStr_offset;
        // printf("\n-------------------\n%s\n-------------------\n", subStr);
    }
    
    regfree(&regex);
    return EXIT_SUCCESS;
}
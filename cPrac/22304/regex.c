/* Regex to capture multiple groups */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>


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
    char *addr = "1234 Super Street,\n SuperCity CA 92420;1235 Super Street,\n SuperCity CA 92420";
    char *re_pattern = "\\s[a-zA-Z0-9]+\\s";
    size_t max_groups = 5;
    regmatch_t groups[max_groups];
    // printf("%s\n", re_pattern);
    
    /* Compile regex pattern. */
    if (regcomp(&regex, re_pattern, REG_EXTENDED|REG_NOSUB)) {
        printf("Failed to compile regular expression.\n");
        return EXIT_FAILURE;   
    }
    
    if (regexec(&regex, addr, max_groups, groups, 0) == 0) {
        for (size_t i = 0; i < max_groups; ++i) {
            if (groups[i].rm_so == (size_t)-1) break; 

            char single_addr[strlen(addr)+1];
            strcpy(single_addr, addr);
            single_addr[groups[i].rm_eo] = 0;
            printf("Address : %s\n", single_addr + groups[i].rm_so);

        }
    }
    regfree(&regex);
    
    return EXIT_SUCCESS;
}
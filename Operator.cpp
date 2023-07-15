#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char operators[] = {'+', '-', '*', '=','/', '%', '^', '(', ')', '[', ']', '{', '}', '<', '>', '&', '|', '!', ','};
    int operator_count = sizeof(operators) / sizeof(operators[0]);
    int found = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < operator_count; j++) {
            if (str[i] == operators[j]) {
                found++;
                printf("Operator '%d' : '%c'.\n", found,operators[j]);
            }
        }
    }

    if (!found){
        printf("The string does not contain any mathematical operators.\n");
    }
        printf("number of operators %d",found);


    return 0;
}

#include<stdio.h>
#include<string.h>
//check bounds

int is_within_bounds(int index, int size){
    return (index>=0 && index<size);
}

int is_to_low(int index){
    return index<0;
}

int is_to_high(int index,int size){
    return index>=size;
}


//is_too_far

int is_too_far(int index,int size,int offset){
    return (index+offset>=size);
}

int null_terminated_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}




int main(){
    int arr[]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index=5;

    int offset = 2;

    // Check bounds
    if (is_within_bounds(index, size)) {
        printf("Index %d is within bounds.\n", index);
    } else if (is_to_low(index)) {
        printf("Index %d is too low.\n", index);
    } else if (is_to_high(index, size)) {
        printf("Index %d is too high.\n", index);
    }

    // Check if index is too far
    if (is_too_far(index, size, offset)) {
        printf("Index %d with offset %d is too far.\n", index, offset);
    } else {
        printf("Index %d with offset %d is within bounds.\n", index, offset);
    }

    // Null-terminated string example
    const char *str = "Hello, world!";
    int str_length = null_terminated_length(str);
    printf("Length of null-terminated string \"%s\" is %d.\n", str, str_length);

    // Calculate length using strlen
    int t_size = strlen(str);
    printf("Length of string using strlen: %d.\n", t_size);

    return 0;
}

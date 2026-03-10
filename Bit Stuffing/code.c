#include <stdio.h>
#include <string.h>
int main() {
 char data[100], stuffedData[150];
 int i, j = 0, count = 0;
 printf("Enter the binary data (e.g., 111111): ");
 scanf("%s", data);
 for (i = 0; i < strlen(data); i++) {
 // Copy the current bit to the stuffed array
 stuffedData[j++] = data[i];
 if (data[i] == '1') {
 count++;
 } else {
 count = 0;
 }
 // If five consecutive 1s are found, stuff a '0'
 if (count == 5) {
 stuffedData[j++] = '0';
 count = 0; // Reset counter after stuffing
 }
 }
 stuffedData[j] = '\0'; // Null-terminate the new string
 printf("\n--- Bit Stuffing Result ---\n");
 printf("Original Data: %s\n", data);
 printf("Stuffed Data: %s\n", stuffedData);
 printf("Transmitted Frame (with flags): 01111110 %s 01111110\n", 
stuffedData);
 return 0;
}
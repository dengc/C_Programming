/** test.c: Test suite for lab4_lib.c functions
*
* Name: John Thorne
* Email: jrthorne@purdue.edu
* Course: CNIT 315
* Lab batch: 4
* Lab assignment: 4
* Date: 3/10/15
*
* Name:Scott Jean
* Email:sajean@purdue.edu
* Course: CNIT 315
* Lab batch: 4
* Lab assignment: 4
* Date:2/24/15
*
* Collaborators: Group 4
*
*
* Name: Xuefeng Luo (Henry)
* Email: hakunamatatahenry@gmail.com
* Course: CNIT 315
* Lab batch: 4
* Lab assignment: 4
* Date: 4/1/2015
*/
#include <stdlib.h>
#include <stdio.h>
#include "lab4_lib.h"
/* Function Prototypes */
int testWordCount();
int testAlphaNumeric();
int testWordRemove();
/* Main program entry point */
int main()
{
printf("===========================\n");
printf("===========Test.c==========\n");
printf("===========================\n");
printf("Testing String Input...\n");
/* Test String Input */
// Define this test in comments here
/*
Purpose: to test programs ability to determine
if there is string input and to accept any string input
results
(Will print error code with message)
*/
int errCode = 0;
int stringPass = 1;
if(acceptString("\0") == 0)
{
printf("Test for null failed error code %d, please check for a null string", errCode);
stringPass=0;
}
errCode++;
if(acceptString("!!!") == 1)
{
printf("Test for special characters failed error code %d, please allow string with special characters", errCode);
stringPass=0;
}
errCode++;
if(acceptString(" space space ") == 1)
{
printf("Test for spaces failed error code %d, please allow string with spaces", errCode);
stringPass=0;
}
errCode++;
if(acceptString("1234") == 1)
{
printf("Test for numbers failed error code %d, please allow string with a numbers", errCode);
stringPass=0;
}
errCode++;
char Long[507];
int x;
x = 0;
while(x < 506)
{
Long[x] = 'a';
x++;
}
if(acceptString(Long) == 1)
{
printf("Test for long string failed error code %d, please allow strings of maximum length", errCode);
stringPass=0;
}
if(stringPass==0)
{
printf("String input test FAILED!\n");
}
else
{
printf("String input test PASSED!\n");
}
printf("===========================\n");
printf("Testing string lengths:\n");
/* Test String Lengths */
/* Test will verify if program is able to give
correct lengths using combinations of different
appropriate ASCII characters.
Results will be printed with an error code
*/
int lengthPass = 1;
errCode++;
if(findLength("\0") != 0)
{
printf("Test for null failed error code %d, please check for a null string", errCode);
lengthPass = 0;
}
errCode++;
if(findLength("cat") != 3)
{
printf("Test for correct length failed error code %d, %d returned for ""cat""", errCode, findLength("cat"));
lengthPass = 0;
}
if(findLength("bigolwordthatisreallybig") != 24)
{
printf("Test for correct length failed error");
printf("code %d, %d returned for string of length 24", errCode, findLength("bigolwordthatisreallybig"));
lengthPass = 0;
}
errCode++;
if(findLength("!#$") != 3)
{
printf("Test for special characters failed error code %d, %d returned for ""!#$""", errCode, findLength("!#$"));
lengthPass = 0;
}
errCode++;
if(findLength("Cat123") != 6)
{
printf("Test for capital letters failed error code %d, %d returned for ""Cat123""", errCode, findLength("Cat123"));
lengthPass = 0;
}
if(lengthPass==0)
{
printf("String length check test FAILED!\n");
}
else
{
printf("String length check test PASSED!\n");
}
printf("===========================\n");
printf("Testing vowel counts:\n");
/* Test Vowel Counting */
// Define this test in comments here
int vowelPass = 1; // 1 means passed
errCode++;
if(vowelCount("\0") != 0)
{
printf("Test for null failed error code %d, please check for a null string", errCode);
vowelPass=0;
}
errCode++;
if(vowelCount("cat") != 1)
{
printf("Test for correct vowel num failed error code %d, %d returned for ""cat""", errCode, vowelCount("cat"));
vowelPass=0;
}
if(vowelCount("aeiou") != 5)
{
printf("Test for all vowels failed error");
printf("code %d, %d returned for ""aeiou""", errCode, vowelCount("aeiou"));
vowelPass=0;
}
errCode++;
if(vowelCount("!#$") != 0)
{
printf("Test for 0 return failed error code %d, %d returned for ""!#$""", errCode, vowelCount("!#$"));
vowelPass=0;
}
errCode++;
if(vowelCount("AeIoU") != 5)
{
printf("Test for capital letters failed error code %d, %d returned for ""AeIoU""", errCode, vowelCount("AeIoU"));
vowelPass=0;
}
errCode++;
if(vowelCount("aaeei") != 5)
{
printf("Test for repeated vowels failed error code %d, %d returned for ""aaeei""", errCode, vowelCount("aaeei"));
vowelPass=0;
}
if(vowelPass==0)
{
printf("Vowel counting test FAILED.\n");
}
else
{
printf("Vowel counting test PASSED!\n");
}
/* Test Word-Counts - John Thorne (@hidden0)
This function will use a variety of strings
with varying characters separating them, as well
as add garbage throughout the string to see if
the function will properly count words.
Word was defined as something beginning and
ending with a space character, or possibly punctuation.
*/
printf("===========================\n");
printf("Testing Word counts:\n");
int wordCountResult = testWordCount();
if(wordCountResult==0)
{
printf("Word count test PASSED!\n");
}
else
{
printf("Word count test FAILED on string %d\n.",wordCountResult);
}
/* Test AlphaNumeric Characters - John Thorne (@hidden0)
This test will simply run through every ASCII character in the
ASCII table and check if the correct result is returned.
*/
printf("===========================\n");
printf("Testing Alpha Numeric Characters:\n");
int alphaNumericResult = testAlphaNumeric();
if(alphaNumericResult==1)
{
printf("Alpha Numeric char test PASSED!\n");
}
else
{
printf("Alpha Numeric char test FAILED.\n");
}
/* Test Substrings */
// Define this test in comments here
/* Test Concatenation */
// Define this test in comments here
//This test will test strings to see if they are ready for concatenation
// Test will verify if strings are able to be concatenated by checking string inputs
int failure;
failure = 0;
int concatPass = 1;
if(concat("\0", "\0") == 1)
{
printf("Test for null failure %d, should not allow two null values", failure);
concatPass = 0;
}
if(concat("$$$$", "@@@#") == 1)
{
printf("Test for special characters failure %d, please allow strings to use special characters", failure);
concatPass = 0;
}
if(concat("3523", "4579") == 1)
{
printf("Test for numbers failed error code %d, please allow string with a numbers", errCode);
concatPass = 0;
}
if(concatPass==0)
{
printf("String concat test FAILED!\n");
}
else
{
printf("String concat test PASSED!\n");
}
/* Test String removal */
printf("===========================\n");
printf("Testing String Removal:\n");
int removeTest=testWordRemove();
if(removeTest==0)
{
printf("String Removal test PASSED!\n");
}
else
{
printf("String Removal test FAILED.\n");
}
return 0;
//Henry Test start
//----------------------------
int errorCounter = 0;
char* line;//Old string for remove
char* target;//remove string target
char* old;//Old string for substring
char* substring;//to store the substring
int pos;//to indicate the position of the substring
int len;//to indicate the length of the substring
int functionReturn = -1;
/*
Test for remove string
*/
//Test for null line string
line = "";
target = "ABC";
functionReturn = removestr(line, target);
if(functionReturn == 0)
{
printf("Null input string PASS!\n");
}
else
{
errorCounter++;
printf("Null input string NOT PASS!\n");
}
//Test for null target string
line = "ABC";
target = "";
functionReturn = removestr(line, target);
if(line == "ABC")
{
printf("Null target string PASS!\n");
}
else
{
errorCounter++;
printf("Null target string NOT PASS!");
}
//Test for invalid target string
line = "Hello";
target = "Hello World";
functionReturn = removestr(line, target);
if(line == "Hello")
{
printf("Invalid target string PASS!\n");
}
else
{
errorCounter++;
printf("Invalid target string NOT PASS!\n");
}
//Test for multiple target string
line = "Hello World Hello";
target = "Hello World";
functionReturn = removestr(line, target);
if(line == " World ")
{
printf("Multiple target string PASS!\n");
}
else
{
errorCounter++;
printf("Multiple target string NOT PASS!\n");
}
//Test for normal target string
line = "Hello World";
target = "World";
functionReturn = removestr(line, target);
if(line == "Hello ")
{
printf("Normal target string PASS!\n");
}
else
{
errorCounter++;
printf("Normal target string NOT PASS!\n");
}
//Test for special target string
line = "AABBCCDDEEFF";
target = "CD";
functionReturn = removestr(line, target);
if(line == "AABBEEFF")
{
printf("Special target string PASS!\n");
}
else
{
errorCounter++;
printf("Special target string NOT PASS!\n");
}
/*
Test for substring
*/
//Test for null old string
old = "";
substring = "";
pos = 1;
len = 1;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 1)
{
print("Null old string check PASS!");
}
else
{
errorCounter++;
printf("Null old string check NOT PASS!");
}
//Test for longer length string
old = "Hello";
substring = "";
pos = 1;
len = 100;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 1)
{
print("Longer length string check PASS!");
}
else
{
errorCounter++;
printf("Longer length string check NOT PASS!");
}
//Test for out of range string
old = "Hello";
substring = "";
pos = 100;
len = 1;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 1)
{
print("out of range string check PASS!");
}
else
{
errorCounter++;
printf("out of range string check NOT PASS!");
}
//Test for negative position
old = "Hello";
substring = "";
pos = -1;
len = 1;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 1)
{
print("negative position check PASS!");
}
else
{
errorCounter++;
printf("negative position check NOT PASS!");
}
//Test for negative length
old = "Hello";
substring = "";
pos = 1;
len = -1;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 1)
{
print("negative length check PASS!");
}
else
{
errorCounter++;
printf("negative length check NOT PASS!");
}
//Test for normal substring
old = "Hello";
substring = "";
pos = 2;
len = 2;
functionReturn = substring(old, substring, pos, len);
if(functionReturn == 0 && substirng == "el")
{
print("normal substring check PASS!");
}
else
{
errorCounter++;
printf("normal substring check NOT PASS!");
}
//Henry work end
//---------------------------------------
}
/** Function: testAlphaNumeric()
*
* Purpose: To stress test and validate the coding of the Alpha Numeric function
*/
int testAlphaNumeric()
{
/* Initialize test Variables */
char testChar = '0';
int i = 0;
int result = 0;
int pass = 1;
for(i=0;i<127;i++)
{
testChar = (char) i;
result = alphanum(testChar);
// This if condition checks the ranges of ascii characters that are not alpha numeric
// if the ranges given have a result of 1, the test failed and pass = 0, which is returned
if(((i>=0 && i<=47) || (i>=58 && i<=64) || (i>=91 && i<=96) || (i>122)) && result==1)
{
pass = 0;
}
}
return pass;
}
/** Function: testWordCount()
*
* Purpose: To stress test and validate the coding teams word counting function
*
* Method: Take several common place strings and set their correct answers manually.
* Send the strings to the test function and check output with the answer. If wrong,
* fail the test. If correct, pass the test.
*
* Returns:
* 0 - Passed all tests
* 1 - Failed test strings[0]
* 2 - Failed test strings[1]
* 3 - Failed test strings[2]
* 4 - Failed test strings[3]
* 5 - Failed test strings[4]
* 6 - Failed test strings[5]
* 7 - Failed test strings[6]
* 8 - Failed test strings[7]
* 9 - Failed test strings[8]
* 10 - Failed test strings[9]
*/
int testWordCount()
{
/* Initialize test variables */
int failCode = 0; // 0 is pass all tests
int c = 0; // counter for the for loop
char *strings[10];
strings[0] = "The fast brown fox jumped over the lazy dog.";
strings[1] = "Beam me up, Scotty!";
strings[2] = "\tThis is an indented sentence?";
strings[3] = "\nA new line./";
strings[4] = " Extra spaces between words and at the end. ";
strings[5] = "";
strings[6] = " ";
strings[7] = " ";
strings[8] = "One";
strings[9] = "Thishouldonlybeoneword";
int answer[10];
answer[0] = 9;
answer[1] = 4;
answer[2] = 5;
answer[3] = 3;
answer[4] = 8;
answer[5] = 0;
answer[6] = 0;
answer[7] = 0;
answer[8] = 1;
answer[9] = 1;
/* Run all strings through function. If it fails, return specific error code */
// Loop through strings array
int val = 0;
for(c=0;c<10;c++)
{
val=wordCount(strings[c]);
if(val!=answer[c])
{
failCode = c+1;
}
}
return failCode;
}
int testWordRemove()
{
/* Initialize test variables */
char S1[] = "Quick test";
char S2[] = "ick";
char answer[] = "Qu test";
while(removestr(S1,S2));
int x = 0;
int goodFlag = 0;
for(x=0;x<strlen(S1);x++)
{
if(S1[x]=='\0')
{
break;
}
if(S1[x]!=answer[x])
{
goodFlag = 1;
}
}
return goodFlag;
}

/*
 * Date: 2018-06-20
 *
 * Description:
 * Check if any permutation of a given string is palindrom or not.
 * For any string to become palindrom it can have at most one character which is
 * getting repeated odd number of times. Other characters must occur even number
 * of times. So using a bit vector, we can check odd occurence of one character.
 *
 * As we are using bit vector which restricts us to use just only lower(or only
 * upper) case characters in input string. If we want to support other
 * characters, we can have a hash map of 255 characters and check for at max one
 * character having odd frequency.
 *
 * Complexity:
 * Time: O(n), Space: O(1)
 */

#include "stdio.h"
#include "string.h"

/*
 * Validates input string.
 *
 * Args:
 * s: Input string
 * l: Length of input string
 *
 * Returns:
 * 1 - String is valid
 * 0 - String is onvalid
 */
int validate_input(char s[], unsigned short int l) {
  unsigned short int i = 0;
  for(i = 0; i < l; i++) {
    if (s[i] < 97 || s[i] > 123)
      return 0;
  }
  return 1;
}

/*
 * Checks if any permutation of string can be palindrom.
 *
 * Args:
 * s: Input string
 * l: Length of input string
 *
 * Retruns:
 * 1 - Palindrom possible
 * 0 - Palindrom not possible
 */
int is_any_permutation_palindrom(char s[], unsigned short int l) {
  unsigned int bit_vector = 0;
  unsigned short int i = 0;
  for (i = 0; i < l; i++) {
    // XOR toggles bit every time so on every odd count it will set that
    // position to 1 and on every even number of count it will turn it to 0.
    bit_vector ^= 1 << (s[i] - 'a');
  }
  // Check if only bit is set in bit vector.
  if (bit_vector & (bit_vector - 1))
    return 0;
  return 1;
}

int main() {
	char input[100];
  unsigned short len = 0;
  printf("Enter input string(smaller case): ");
	fgets(input, 100, stdin);
  len = strlen(input);
  // fgets also includes '\n' in string length so len - 1
  if (!validate_input(input, len - 1)) {
    printf("Input is invalid!\n");
    return -1;
  }
  if (is_any_permutation_palindrom(input, len - 1)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
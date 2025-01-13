int val(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int res = 0; // Initialize the result
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        // If the current value is less than the next value, subtract it
        if (val(s[i]) < val(s[i + 1])) {
            res -= val(s[i]);
        } else {
            // Otherwise, add it
            res += val(s[i]);
        }
    }
    return res;
}

//----> better Roman to Interger code [ 0ms ] <--------

#include <string.h>

int romanToInt(char* s) {
    int f = 0;  // Initialize the result to 0
    
    // Iterate over each character in the string
    for (int i = 0; i < strlen(s); i++) {
        // Check for subtraction cases first
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) 
            f -= 1;  // Subtract 1 for IV or IX
         else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) 
            f -= 10; // Subtract 10 for XL or XC
         else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) 
            f -= 100; // Subtract 100 for CD or CM
        
        // For normal cases, just add the corresponding value
        else if (s[i] == 'I') {
            f += 1;
        } else if (s[i] == 'V') {
            f += 5;
        } else if (s[i] == 'X') {
            f += 10;
        } else if (s[i] == 'L') {
            f += 50;
        } else if (s[i] == 'C') {
            f += 100;
        } else if (s[i] == 'D') {
            f += 500;
        } else if (s[i] == 'M') {
            f += 1000;
        }
    }
    
    return f;  // Return the computed integer value
}

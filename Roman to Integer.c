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

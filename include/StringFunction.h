#pragma once

unsigned int GetAmountSymbolsInString( const char *String ) {
    unsigned int AmountSymbols = 0;
    while(*String) {
        AmountSymbols++;
        String++;
    }
    return AmountSymbols;
}

void CopyString( char *String, const char *StringToCopy ) {
    while(*StringToCopy) {
        *String = *StringToCopy;
        String++;
        StringToCopy++;
    }
    *String = '\0';
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "utils.hpp"

u8 confusion[512] = {
0xac,0xd1,0x25,0x94,0x1f,0xb3,0x33,0x28,0x7c,0x2b,0x17,0xbc,0xf6,0xb0,0x55,0x5d,
0x8f,0xd2,0x48,0xd4,0xd3,0x78,0x62,0x1a,0x02,0xf2,0x01,0xc9,0xaa,0xf0,0x83,0x71,
0x72,0x4b,0x6a,0xe8,0xe9,0x42,0xc0,0x53,0x63,0x66,0x13,0x4a,0xc1,0x85,0xcf,0x0c,
0x24,0x76,0xa5,0x6e,0xd7,0xa1,0xec,0xc6,0x04,0xc2,0xa2,0x5c,0x81,0x92,0x6c,0xda,
0xc6,0x86,0xba,0x4d,0x39,0xa0,0x0e,0x8c,0x8a,0xd0,0xfe,0x59,0x96,0x49,0xe6,0xea,
0x69,0x30,0x52,0x1c,0xe0,0xb2,0x05,0x9b,0x10,0x03,0xa8,0x64,0x51,0x97,0x02,0x09,
0x8e,0xad,0xf7,0x36,0x47,0xab,0xce,0x7f,0x56,0xca,0x00,0xe3,0xed,0xf1,0x38,0xd8,
0x26,0x1c,0xdc,0x35,0x91,0x43,0x2c,0x74,0xb4,0x61,0x9d,0x5e,0xe9,0x4c,0xbf,0x77,
0x16,0x1e,0x21,0x1d,0x2d,0xa9,0x95,0xb8,0xc3,0x8d,0xf8,0xdb,0x34,0xe1,0x84,0xd6,
0x0b,0x23,0x4e,0xff,0x3c,0x54,0xa7,0x78,0xa4,0x89,0x33,0x6d,0xfb,0x79,0x27,0xc4,
0xf9,0x40,0x41,0xdf,0xc5,0x82,0x93,0xdd,0xa6,0xef,0xcd,0x8d,0xa3,0xae,0x7a,0xb6,
0x2f,0xfd,0xbd,0xe5,0x98,0x66,0xf3,0x4f,0x57,0x88,0x90,0x9c,0x0a,0x50,0xe7,0x15,
0x7b,0x58,0xbc,0x07,0x68,0x3a,0x5f,0xee,0x32,0x9f,0xeb,0xcc,0x18,0x8b,0xe2,0x57,
0xb7,0x49,0x37,0xde,0xf5,0x99,0x67,0x5b,0x3b,0xbb,0x3d,0xb5,0x2d,0x19,0x2e,0x0d,
0x93,0xfc,0x7e,0x06,0x08,0xbe,0x3f,0xd9,0x2a,0x70,0x9a,0xc8,0x7d,0xd8,0x46,0x65,
0x22,0xf4,0xb9,0xa2,0x6f,0x12,0x1b,0x14,0x45,0xc7,0x87,0x31,0x60,0x29,0xf7,0x73,
0x2c,0x97,0x72,0xcd,0x89,0xa6,0x88,0x4c,0xe8,0x83,0xeb,0x59,0xca,0x50,0x3f,0x27,
0x4e,0xae,0x43,0xd5,0x6e,0xd0,0x99,0x7b,0x7c,0x40,0x0c,0x52,0x86,0xc1,0x46,0x12,
0x5a,0x28,0xa8,0xbb,0xcb,0xf0,0x11,0x95,0x26,0x0d,0x34,0x66,0x22,0x18,0x6f,0x51,
0x9b,0x3b,0xda,0xec,0x5e,0x00,0x2a,0xf5,0x8f,0x61,0xba,0x96,0xb3,0xd1,0x30,0xdc,
0x33,0x75,0xe9,0x6d,0xc8,0xa1,0x3a,0x3e,0x5f,0x9d,0xfd,0xa9,0x31,0x9f,0xaa,0x85,
0x2f,0x92,0xaf,0x67,0x78,0xa5,0xab,0x03,0x21,0x4f,0xb9,0xad,0xfe,0xf3,0x42,0xfc,
0x17,0xd7,0xee,0xa3,0xd8,0x80,0x14,0x2e,0xa0,0x47,0x55,0xc4,0xff,0xe5,0x13,0x3f,
0x81,0xb6,0x7a,0x94,0xd0,0xb5,0x54,0xbf,0x91,0xa7,0x37,0xf1,0x6b,0xc9,0x1b,0xb1,
0x3c,0xb6,0xd9,0x32,0x24,0x8d,0xf2,0x82,0xb4,0xf9,0xdb,0x7d,0x44,0xfb,0x1e,0xd4,
0xea,0x5d,0x35,0x69,0x23,0x71,0x57,0x01,0x06,0xe4,0x55,0x9a,0xa4,0x58,0x56,0xc7,
0x4a,0x8c,0x8a,0xd6,0x6a,0x49,0x70,0xc5,0x8e,0x0a,0x62,0xdc,0x29,0x4b,0x42,0x41,
0xcb,0x2b,0xb7,0xce,0x08,0xa1,0x76,0x1d,0x1a,0xb8,0xe3,0xcc,0x7e,0x48,0x20,0xe6,
0xf8,0x45,0x93,0xde,0xc3,0x63,0x0f,0xb0,0xac,0x5c,0xba,0xdf,0x07,0x77,0xe7,0x4e,
0x1f,0x28,0x10,0x6c,0x59,0xd3,0xdd,0x2d,0x65,0x39,0xb2,0x74,0x84,0x3d,0xf4,0xbd,
0xc7,0x79,0x60,0x0b,0x4d,0x33,0x36,0x25,0xbc,0xe0,0x09,0xcf,0x5b,0xe2,0x38,0x9e,
0xc0,0xef,0xd2,0x16,0x05,0xbe,0x53,0xf7,0xc2,0xc6,0xa2,0x24,0x98,0x1c,0xad,0x04
};

u32 diffusion[32] = {
0xf26cb481,0x16a5dc92,0x3c5ba924,0x79b65248,0x2fc64b18,0x615acd29,0xc3b59a42,0x976b2584,
0x6cf281b4,0xa51692dc,0x5b3c24a9,0xb6794852,0xc62f184b,0x5a6129cd,0xb5c3429a,0x6b978425,
0xb481f26c,0xdc9216a5,0xa9243c5b,0x524879b6,0x4b182fc6,0xcd29615a,0x9a42c3b5,0x2584976b,
0x81b46cf2,0x92dca516,0x24a95b3c,0x4852b679,0x184bc62f,0x29cd5a61,0x429ab5c3,0x84256b97
};

u8 invalid[] = {
0x0f, 0x11, 0x20, 0x3e, 0x44, 0x5a, 0x6b, 0x75,
0x80, 0x9e, 0xaf, 0xb1, 0xcb, 0xd5, 0xe4, 0xfa
};

u8 simplified[] = {
0x0f, 0x01, 0x00, 0x0e, 0x04, 0x0a, 0x0b, 0x05,
0x00, 0x0e, 0x0f, 0x01, 0x0b, 0x05, 0x04, 0x0a
};

u8 partlySafe01[] = {
0x02, 0x03, 0x06, 0x07, 0x12, 0x13, 0x16, 0x17,
0x22, 0x23, 0x26, 0x27, 0x32, 0x33, 0x36, 0x37,
0x42, 0x43, 0x46, 0x47, 0x52, 0x53, 0x56, 0x57,
0x62, 0x63, 0x66, 0x67, 0x72, 0x73, 0x76, 0x77,
0x82, 0x83, 0x86, 0x87, 0x92, 0x93, 0x96, 0x97,
0xa2, 0xa3, 0xa6, 0xa7, 0xb2, 0xb3, 0xb6, 0xb7,
0xc2, 0xc3, 0xc6, 0xc7, 0xd2, 0xd3, 0xd6, 0xd7,
0xe2, 0xe3, 0xe6, 0xe7, 0xf2, 0xf3, 0xf6, 0xf7
};

u8 partlySafe10[] = {
0x08, 0x09, 0x0c, 0x0d, 0x18, 0x19, 0x1c, 0x1d,
0x28, 0x29, 0x2c, 0x2d, 0x38, 0x39, 0x3c, 0x3d,
0x48, 0x49, 0x4c, 0x4d, 0x58, 0x59, 0x5c, 0x5d,
0x68, 0x69, 0x6c, 0x6d, 0x78, 0x79, 0x7c, 0x7d,
0x88, 0x89, 0x8c, 0x8d, 0x98, 0x99, 0x9c, 0x9d,
0xa8, 0xa9, 0xac, 0xad, 0xb8, 0xb9, 0xbc, 0xbd,
0xc8, 0xc9, 0xcc, 0xcd, 0xd8, 0xd9, 0xdc, 0xdd,
0xe8, 0xe9, 0xec, 0xed, 0xf8, 0xf9, 0xfc, 0xfd
};

u8 safe01[] = {
0x03, 0x07, 0x12, 0x13, 0x22, 0x23, 0x32, 0x36,
0x46, 0x47, 0x52, 0x56, 0x63, 0x67, 0x76, 0x77,
0x82, 0x83, 0x92, 0x96, 0xa3, 0xa7, 0xb2, 0xb3,
0xc3, 0xc7, 0xd6, 0xd7, 0xe6, 0xe7, 0xf2, 0xf6,
};

u8 safe10[] = {
0x0c, 0x0d, 0x19, 0x1d, 0x28, 0x2c, 0x3c, 0x3d,
0x48, 0x4c, 0x58, 0x59, 0x68, 0x69, 0x79, 0x7d,
0x88, 0x8c, 0x9c, 0x9d, 0xac, 0xad, 0xb9, 0xbd,
0xc8, 0xc9, 0xd9, 0xdd, 0xe8, 0xec, 0xf8, 0xf9,
};

std::vector< std::vector< int > > confusion_reverse1 = {
{106},{26},{24,94},{89},{56},{86},{227},{195},
{228},{95},{188},{144},{47},{223},{70},{},
{88},{},{245},{42},{247},{191},{128},{10},
{204},{221},{23},{246},{83,113},{131},{129},{4},
{},{130},{240},{145},{48},{2},{112},{158},
{7},{253},{232},{9},{118},{132,220},{222},{176},
{81},{251},{200},{6,154},{140},{115},{99},{210},
{110},{68},{197},{216},{148},{218},{},{230},
{161},{162},{37},{117},{},{248},{238},{100},
{18},{77,209},{43},{33},{125},{67},{146},{183},
{189},{92},{82},{39},{149},{14},{104},{184,207},
{193},{75},{},{215},{59},{15},{123},{198},
{252},{121},{22},{40},{91},{239},{41,181},{214},
{196},{80},{34},{},{62},{155},{51},{244},
{233},{31},{32},{255},{119},{},{49},{127},
{21,151},{157},{174},{192},{8},{236},{226},{103},
{},{60},{165},{30},{142},{45},{65},{250},
{185},{153},{72},{205},{71},{137,171},{96},{16},
{186},{116},{61},{166,224},{3},{134},{76},{93},
{180},{213},{234},{87},{187},{122},{},{201},
{69},{53},{58,243},{172},{152},{50},{168},{150},
{90},{133},{28},{101},{0},{97},{173},{},
{13},{},{85},{5},{120},{219},{175},{208},
{135},{242},{66},{217},{11,194},{178},{229},{126},
{38},{44},{57},{136},{159},{164},{55,64},{249},
{235},{27},{105},{},{203},{170},{102},{46},
{73},{1},{17},{20},{19},{},{143},{52},
{111,237},{231},{63},{139},{114},{167},{211},{163},
{84},{141},{206},{107},{},{179},{78},{190},
{35},{36,124},{79},{202},{54},{108},{199},{169},
{29},{109},{25},{182},{241},{212},{12},{98,254},
{138},{160},{},{156},{225},{177},{74},{147}
};

void printEquationSystem() {
    std::vector< int > a,b;
    int conf1 = 0, conf2 = 0;
    char del = '^';
    bool initialized = false;
    for( u8 j = 0; j < 32; ++j ) {
        std::cout << "input[" << utl::base10 << (int)j << ']' << ' ' << '=' << ' ';
        conf1 = 0; conf2 = 0;
        for( u8 k = 0; k < 32; ++k ) {
            if( ( diffusion[ j ] >> k ) & 1 ) {
                if( !( k % 2 ) ) {
                    std::cout << ( initialized ? ( utl::pasteChr( ' ', del, ' ' ) ) : std::string( "" ) ) << "c1[" << utl::base10 << (int)k << ']';
                    ++conf1;
                } else {
                    std::cout << ( initialized ? ( utl::pasteChr( ' ', del, ' ' ) ) : std::string( "" ) ) << "c2[" << utl::base10 << (int)k << ']';
                    ++conf2;
                }
                initialized = true;
            }
        }
        initialized = false;
        std::cout << ';' << std::endl;
        a.push_back( conf1 );
        b.push_back( conf2 );
    }
    std::cout << std::endl;
    for( size_t i = 0; i < a.size(); ++i ) {
      std::cout << "confusion 1" << '\t' << "confusion 2" << std::endl;
      std::cout << utl::base10 << a[ i ] << ' ' << ( a[ i ] % 2 ? "(odd) " : "(even)" ) << '\t' << b[ i ] << ' ' << ( b[ i ] % 2 ? "(odd) " : "(even)" ) << '\t'
      << '=' << ' ' << a[ i ] + b[ i ] << std::endl << std::endl;
    }
}

void printNotReverseable() {
    std::cout << "Simplified values without" << std::endl << "insignificant counting in high" << std::endl;
    utl::printBin( simplified[ 0 ], simplified[ 1 ], simplified[ 2 ], simplified[ 3 ], simplified[ 4 ], simplified[ 5 ], simplified[ 6 ], simplified[ 7 ],
                 simplified[ 8 ], simplified[ 9 ], simplified[ 10 ], simplified[ 11 ], simplified[ 12 ], simplified[ 13 ], simplified[ 14 ], simplified[ 15 ] );
    std::cout << std::endl;
    std::cout << "Powers 2^3 and 2^1" << std::endl << "of the simplified values" << std::endl;
    for( int i = 0; i < 16; ++i )
        std::cout << "0x" << utl::base16 << ( int )simplified[ i ] << ':' << ' ' << utl::toBin( invalid[ i ] )[ 3 ] << utl::toBin( invalid[ i ] )[ 1 ] << std::endl;
    std::cout << std::endl;
}

void printAvoidDiffusion() {
    std::cout << "Odd number of XORs based on the values from the matrix" << std::endl;
    std::cout << utl::pasteArr( utl::toBin( ( u8 )( 0x02 ) ) ) << ' ' << "OK number" << std::endl;
    std::cout << utl::pasteArr( utl::toBin( ( u8 )( 0x08 ) ) ) << ' ' << "(XOR)" << ' ' << "OK number" << std::endl;
    std::cout << utl::pasteArr( utl::toBin( ( u8 )( 0x05 ) ) ) << ' ' << "(XOR)" << ' ' << "<-- Problem" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << utl::pasteArr( utl::toBin( ( u8 )( 0x02 ^ 0x08 ^ 0x05 ) ) ) << ' ' << '=' << ' ' << "0x0f" << ' ' << '=' << ' ' << "0x05 ^ 0x08 ^ 0x02" << std::endl;
    std::cout << "0x05 has 00 but needs to have either bit set as well to guarantee 01 or 10" << std::endl << std::endl;
}

void printSafeValues10() {
    std::vector< u8 > safe;
    for( int i = 0; i < 256; ++i ) {
      if( !utl::toBin( ( u8 )i )[ 1 ] && utl::toBin( ( u8 )i )[ 3 ] ) {
        safe.push_back( ( u8 )i );
      }
    }
    int i = 0;
    std::cout << "Safe values with 2^3 set and 2^1 not set" << std::endl;
    for( const auto& value: safe ) {
        if( !( i % 8 ) && i > 0 ) std::cout << std::endl;
        std::cout << "0x" << utl::base16 << ( int )value << ',' << ' ';
        ++i;
    }
    std::cout << std::endl << utl::base10 << "Count: " << i;
    std::cout << std::endl << std::endl;
}

void printSafeValues01() {
    std::vector< u8 > safe;
    for( int i = 0; i < 256; ++i ) {
      if( utl::toBin( ( u8 )i )[ 1 ] && !utl::toBin( ( u8 )i )[ 3 ] ) {
        safe.push_back( ( u8 )i );
      }
    }
    int i = 0;
    std::cout << "Safe values with 2^1 set and 2^3 not set" << std::endl;
    for( const auto& value: safe ) {
        if( !( i % 8 ) && i > 0 ) std::cout << std::endl;
        std::cout << "0x" << utl::base16 << (int)value << ',' << ' ';
        ++i;
    }
    std::cout << std::endl << utl::base10 << "Count: " << i;
    std::cout << std::endl << std::endl;
}

void printSafeReverseLookup01() {
    u8 lookup;
    bool success = false;
    int k = 0;
    for( int i = 0; i < 64; i++ ) {
        lookup = partlySafe01[ i ];
      for( int j = 0; j < 256; ++j ) {
          std::vector< int > tmp = confusion_reverse1[ ( int )lookup ];
          if( tmp.empty() ) break;
          lookup = ( u8 )tmp[ 0 ];
          if( j == 255 ) success = true;
      }
      if( success ) {
          if( !( k % 8 ) ) std::cout << std::endl;
          std::cout << "0x" << utl::base16 << ( int )partlySafe01[ i ] << ',' << ' ';
          success = false;
          ++k;
      }
    }
    std::cout << std::endl;
    std::cout << "Count: " << utl::base10 << k << std::endl << std::endl;
}

void printSafeReverseLookup10() {
    u8 lookup;
    bool success = false;
    int k = 0;
    for( int i = 0; i < 64; i++ ) {
        lookup = partlySafe10[ i ];
        for( int j = 0; j < 256; ++j ) {
            std::vector< int > tmp = confusion_reverse1[ ( int )lookup ];
            if( tmp.empty() ) break;
            lookup = ( u8 )tmp[ 0 ];
            if( j == 255 ) success = true;
        }
        if( success ) {
            if( !( k % 8 ) ) std::cout << std::endl;
            std::cout << "0x" << utl::base16 << (int)partlySafe10[i] << ',' << ' ';
            success = false;
            ++k;
        }
    }
    std::cout << std::endl;
    std::cout << "Count: " << utl::base10 << k << std::endl << std::endl;
}

void printRestoreable( u8 input[ 16 ] ) {
    int matched = 0;
    for( int h = 0; h < 16; ++h ) {
        for( int i = 0; i < 32; ++i ) {
            for( int j = 0; j < 32; ++j ) {
                if( ( confusion[ safe01[ i ] ] ^ confusion[ ( int )( safe10[ j ] ) + 256 ] ) == input[ h ] ) {
                    if( !( matched % 4 ) && matched > 0 ) std::cout << std::endl;
                    std::cout << "0x" << utl::base16 << ( int )safe01[ i ] << ',' << ' ' << "0x" << utl::base16 << ( int )safe10[ j ] << ',' << ' ';
                    ++matched;
                    i = 128;
                    break;
                    // Next k
                }
            }
        }
    }
    std::cout << std::endl << "Characters restored: " << utl::base10 << matched << std::endl;
}

int main() {
    // 32 Equations from the matrix
    printEquationSystem();

    // Values to avoid in the entire process
    printNotReverseable();

    // Accomplish guaranteed lookup-able values after matrix
    printAvoidDiffusion();

    // Safe values when combined in odd XORs
    // 128 Values
    printSafeValues01();
    printSafeValues10();

    // Which of these can be looked-up 256 times
    // without landing on a hole in the reverse
    // 64 Values
    printSafeReverseLookup01();
    printSafeReverseLookup10();

    // Test whether we can restore valid XORs values to be picked
    u8 output[16] = {'A','l','e','x',' ','T','o','e','p','f','e','r','!','!','!','\0'};
    printRestoreable( output );

    return 0;
}

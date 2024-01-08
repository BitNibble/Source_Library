/*************************************************************************
	ARMFUNCTION
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com> 
License: GNU General Public License
Hardware: all
Date: 18062023
Update: 07012024
Comment:
	Tested ->  Atemga128, Atmega328, Atmega32U4, Atmega324, Atmega8535, Atmega88, STM32F446RE
	Very Stable
*************************************************************************/
/*** File Library ***/
#include "armfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/*** File Constant & Macro ***/
#define MAXafterpoint 6
#define DEFAULTafterpoint 2

/*** File Variable ***/
static FUNC setup_func;
static char FUNCstr[FUNCSTRSIZE + 1];
static uint32_t mem[4];
static uint32_t nen[4];

/*** File Header ***/
int function_StringLength (const char string[]);
void function_Reverse(char s[]);
uint8_t function_intinvstr(uint32_t num, char* res, uint8_t n_digit);
void function_swap(long *px, long *py);
/*** 1 ***/
uint16_t function_SwapByte(uint16_t num);
/*** 2 ***/
void function_copy(char to[], char from[]);
void function_squeeze(char s[], int c);
void function_shellsort(int v[], int n);
char* function_resizestr(char *string, int size);
int function_trim(char s[]);
/*** 3 ***/
uint8_t function_bcd2dec(uint8_t num);
uint8_t function_dec2bcd(uint8_t num);
char* function_dectohex(int32_t num);
uint8_t function_bcd2bin(uint8_t val);
uint8_t function_bin2bcd(uint8_t val);
int function_twocomptoint8bit(int twoscomp);
int function_twocomptoint10bit(int twoscomp);
int function_twocomptointnbit(int twoscomp, uint8_t nbits);
/*** 4 ***/
char* function_print_v1( char* str, uint8_t size_str, const char* format, ... );
char* function_print_v2(const char *format, ... );
char* function_print_binary(unsigned int n_bits, unsigned int number);
/*** 5 ***/
char* function_i16toa(int16_t n);
char* function_ui16toa(uint16_t n);
char* function_i32toa(int32_t n);
char* function_ftoa(double num, char* res, uint8_t afterpoint);
/*** 6 ***/
long function_trimmer(long x, long in_min, long in_max, long out_min, long out_max);
int function_pmax(int a1, int a2);
int function_gcd_v1 (int u, int v);
long function_gcd_v2(long a, long b);
/*** 7 ***/
int function_StrToInt (const char string[]);
/*** 8 ***/
uint32_t function_readreg(uint32_t reg, uint32_t size_block, uint32_t bit);
void function_writereg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
void function_setreg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
void function_setbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
uint32_t function_getsetbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit);
void function_RegSetBits( unsigned int* reg, int n_bits, ... );
void function_RegResetBits( unsigned int* reg, int n_bits, ... );
void function_VecSetup( volatile uint32_t vec[], const unsigned int size_block, unsigned int data, unsigned int block_n );
/*** 9 ***/
uint32_t function_triggerA(uint32_t hllh_io, uint8_t pin, uint32_t counter);
uint32_t function_triggerB(uint32_t hl_io, uint32_t lh_io, uint8_t pin, uint32_t counter);
uint32_t read_value(void);
/*** COMMON ***/
void FUNC_var(void);

/*** FUNC Procedure & Function Definition ***/
FUNC FUNCenable( void )
{
	FUNC_var();
	/*** TOP ***/
	setup_func.stringlength = function_StringLength;
	setup_func.reverse = function_Reverse;
	setup_func.swap = function_swap;
	/***********/
	// 1
	setup_func.SwapByte = function_SwapByte;
	// 2
	setup_func.copy = function_copy;
	setup_func.squeeze = function_squeeze;
	setup_func.shellsort = function_shellsort;
	setup_func.resizestr = function_resizestr;
	setup_func.trim = function_trim;
	// 3
	setup_func.bcd2dec = function_bcd2dec;
	setup_func.dec2bcd = function_dec2bcd;
	setup_func.dectohex = function_dectohex;
	setup_func.bcd2bin = function_bcd2bin;
	setup_func.twocomptoint8bit = function_twocomptoint8bit;
	setup_func.twocomptoint10bit = function_twocomptoint10bit;
	setup_func.twocomptointnbit = function_twocomptointnbit;
	// 4
	setup_func.print_v1 = function_print_v1;
	setup_func.print_v2 = function_print_v2;
	setup_func.print_binary = function_print_binary;
	// 5
	setup_func.i16toa = function_i16toa;
	setup_func.ui16toa = function_ui16toa;
	setup_func.i32toa = function_i32toa;
	setup_func.ftoa = function_ftoa;

	// 6
	setup_func.trimmer = function_trimmer;
	setup_func.pmax = function_pmax;
	setup_func.gcd_v1 = function_gcd_v1;
	setup_func.gcd_v2 = function_gcd_v2;
	// 8
	setup_func.strToInt = function_StrToInt;
	// 9
	setup_func.readreg = function_readreg;
	setup_func.writereg = function_writereg;
	setup_func.setreg = function_setreg;
	setup_func.setbit = function_setbit;
	setup_func.getsetbit = function_getsetbit;
	setup_func.regsetbits = function_RegSetBits;
	setup_func.regresetbits = function_RegResetBits;
	setup_func.vecsetup = function_VecSetup;
	// 9
	setup_func.triggerA = function_triggerA;
	setup_func.triggerB = function_triggerB;
	setup_func.value = read_value;

	return setup_func;
}

FUNC* func(void){ return &setup_func; }

void FUNC_var(void)
{
	FUNCstr[FUNCSTRSIZE + 1] = '\0';
	mem[0] = 0; nen[0] = 0;
}
/*** FUNC Procedure & Function Definition***/
/******/
int function_StringLength (const char string[])
{
	int count;
	for (count = 0; string[count] != '\0'; count++ ) ;
	return count;
}
void function_Reverse(char s[])
{
	char c; int i, j;
	for ( i = 0, j = function_StringLength(s) - 1; i < j ; i++, j-- ){
		c = s[i]; s[i] = s[j]; s[j] = c;
	}
}
// intinvstr
uint8_t function_intinvstr(uint32_t num, char* res, uint8_t n_digit)
{
	uint8_t k = 0;
	for(res[k++] = (char)((num % 10) + '0'); (num /= 10) > 0 ; res[k++] = (char)((num % 10) + '0'));
	for( ; k < n_digit ; res[k++] = '0');
	res[k] = '\0';
	return k;
}
void function_swap(long *px, long *py)
{
	long temp;
	temp = *px;
	*px = *py;
	*py = temp;
}
uint16_t function_SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (uint16_t)(num << 8);
	return (num >> 8) | tp;
}
void function_copy(char to[], char from[])
{
	int i; i = 0;
	while ((to[i] = from[i]) != '\0') ++i;
}
void function_squeeze(char s[], int c)
{
	int i, j;
	for (i = 0, j = 0; (s[i] != '\0'); i++){
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}
void function_shellsort(int v[], int n)
{
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}
char* function_resizestr(char *string, int size)
{
	int i; FUNCstr[size] = '\0';
	for(i = 0; i < size; i++){
		if(*(string + i) == '\0'){
			for(; i < size; i++){ FUNCstr[i] = ' '; }
			break;
		}
		FUNCstr[i] = *(string + i);
	}
	return FUNCstr;
}
int function_trim(char s[])
{
	int n;
	for (n = function_StringLength(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') break;
	s[n + 1] = '\0';
	return n;
}
/******/
uint8_t function_bcd2dec(uint8_t num)
{
	return ((num / 16 * 10) + (num % 16));
}
uint8_t function_dec2bcd(uint8_t num)
{
	return ((num / 10 * 16) + (num % 10));
}
uint8_t function_bcd2bin(uint8_t val)
{
	return (val & 0x0f) + (val >> 4) * 10;
}
char* function_dectohex(int32_t num)
{
	int32_t remainder;
	uint8_t j;
	for(j = 0, FUNCstr[j] = '\0'; num; FUNCstr[j] = '\0', num = num / 16){
		remainder = num % 16;
		if (remainder < 10)
			FUNCstr[j++] = (char) (48 + remainder);
		else
			FUNCstr[j++] = (char) (55 + remainder);
	}
	function_Reverse(FUNCstr);
	return FUNCstr;
}
int function_twocomptoint8bit(int twoscomp){

  int value;
	// Let's see if the byte is negative
  if (twoscomp & 0x80){
    // Invert
    twoscomp = ~twoscomp + 1;
		twoscomp = (twoscomp & 0xFF);
    // Cast as int and multiply by negative one
    value = (int)(twoscomp) * (-1);
    return value;
  }else{
    // Byte is non-negative, therefore convert to decimal and display
    // Make sure we are never over 1279
    twoscomp = (twoscomp & 0x7F);
    // Cast as int and return
    value = (int)(twoscomp);
    return value;
  }
}
// Two's Complement function, shifts 10 bit binary to signed integers (-512 to 512)
int function_twocomptoint10bit(int twoscomp){
	int value;
  // Let's see if the byte is negative
  if (twoscomp & 0x200){
    // Invert
    twoscomp = ~twoscomp + 1;
    twoscomp = (twoscomp & 0x3FF);
    // Cast as int and multiply by negative one
    value = (int)(twoscomp) * (-1);
    return value;
  }else{
    // Serial.println("We entered the positive loop");
    // Byte is non-negative, therefore convert to decimal and display
    twoscomp = (twoscomp & 0x1FF);
    // Cast as int and return
    // Serial.println(twoscomp);
    value = (int)(twoscomp);
    return value;
  }
}
// Two's Complement function, nbits
int function_twocomptointnbit(int twoscomp, uint8_t nbits){
  unsigned int signmask;
  unsigned int mask;
  signmask = (1 << (nbits - 1));
  mask = signmask - 1;
  // Let's see if the number is negative
  if ((unsigned int) twoscomp & signmask){
	twoscomp &= mask;
    twoscomp -= signmask;
  }else{
	  twoscomp &= mask;
  }
  return twoscomp;
}
/******/
char* function_print_v1( char* str, uint8_t size_str, const char* format, ... )
{
	va_list aptr;
	int ret;

	va_start(aptr, format);
	ret = vsnprintf( str, size_str, (const char*) format, aptr );
	//ret = vsnprintf( ptr, size_str, format, aptr );
	va_end(aptr);

	if(ret < 0){
		return NULL;
		//str[0]='/0';str[1]='/0';str[2]='/0';str[3]='/0';
	}else
		return str;
}
char* function_print_v2( const char* format, ... )
{
	va_list aptr;
	int ret;

	va_start(aptr, format);
	ret = vsnprintf( FUNCstr, FUNCSTRSIZE, (const char*) format, aptr );
	// ret = vsnprintf( ptr, FUNCSTRSIZE, format, aptr );
	va_end(aptr);

	if(ret < 0){
		return NULL;
		// FUNCstr[0]='/0';FUNCstr[1]='/0';FUNCstr[2]='/0';FUNCstr[3]='/0';
	}else
		return FUNCstr;
}
/******/
char* function_i16toa(int16_t n)
{
	uint8_t i;
	int16_t sign;
	if ((sign = n) < 0) // record sign
		n = -n; // make n positive
	i = 0;
	do { // generate digits in reverse order
		FUNCstr[i++] = (char) (n % 10 + '0'); // get next digit
	}while ((n /= 10) > 0); // delete it
	if (sign < 0)
		FUNCstr[i++] = '-';
	FUNCstr[i] = '\0';
	function_Reverse(FUNCstr);
	return FUNCstr;
}
char* function_ui16toa(uint16_t n)
{
	uint8_t i;
	for(i = 0, FUNCstr[i++] = n % 10 + '0'; (n /= 10) > 0; FUNCstr[i++] = n % 10 + '0');
	FUNCstr[i] = '\0';
	function_Reverse(FUNCstr);
	return FUNCstr;
}
char* function_i32toa(int32_t n)
{
	uint8_t i;
	int32_t sign;
	if ((sign = n) < 0) // record sign
	n = -n; // make n positive
	i = 0;
	do { // generate digits in reverse order
		FUNCstr[i++] = (char) (n % 10 + '0'); // get next digit
	}while ((n /= 10) > 0); // delete it
	if (sign < 0)
		FUNCstr[i++] = '-';
	FUNCstr[i] = '\0';
	function_Reverse(FUNCstr);
	return FUNCstr;
}
char* function_print_binary(unsigned int n_bits, unsigned int number)
{
	unsigned int i, c;
	for(i = (1 << (n_bits - 1)), c = 0; i; i >>= 1, c++)
		(number & i) ? (FUNCstr[c] = '1') : (FUNCstr[c] = '0');
	FUNCstr[c] = '\0';
	return FUNCstr;
}
char* function_ftoa(double num, char* res, uint8_t afterpoint)
{
	uint32_t ipart;
	double n, fpart;
	uint8_t k = 0;
	int8_t sign;
	if (num < 0){
		n = -num; sign = -1;
	}else{
		n = num; sign = 1;
	}
	ipart = (uint32_t) n; fpart = n - (double)ipart;
	k = function_intinvstr((int)ipart, res, 1);
	if (sign < 0) res[k++] = '-'; else res[k++] = ' ';
	res[k] = '\0';
	function_Reverse(res);
	if (afterpoint > 0 && afterpoint < (8 + 1)){
		res[k++] = '.';
		function_intinvstr( (int32_t)(fpart * pow(10, afterpoint)), (res + k), afterpoint );
		function_Reverse(res + k);
	}else{
		res[k++] = '.';
		function_intinvstr( (int32_t)(fpart * pow(10, 2)), (res + k), 2 );
		function_Reverse(res + k);
	}
	return res;
}
/******/
long function_trimmer(long x, long in_min, long in_max, long out_min, long out_max)
// same as arduino map function
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int function_pmax(int a1, int a2)
{
	int biggest;
	if(a1 > a2){ biggest = a1;
	}else{ biggest = a2; }
	return biggest;
}
int function_gcd_v1 (int u, int v)
{
	int temp;
	while ( v != 0 ) {
		temp = u % v; u = v; v = temp;
	}
	return u;
}
long function_gcd_v2(long a, long b)
{
	long r;
	if (a < b) function_swap(&a, &b);
	if (!b){
		while ((r = a % b) != 0) {
			a = b; b = r;
		}
	}
	return b;
}
/******/
int function_StrToInt (const char string[])
{
	int i, intValue, result = 0;
	for ( i = 0; string[i] >= '0' && string[i] <= '9'; ++i ){
		intValue = string[i] - '0';
		result = result * 10 + intValue;
	}
	return result;
}
/******/
uint32_t function_readreg(uint32_t reg, uint32_t size_block, uint32_t bit)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = reg;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}

void function_writereg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	value = (value << bit);
	*reg = value;
}

void function_setreg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*reg &= ~(mask << bit);
	*reg |= (value << bit);
}

void function_setbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	uint32_t n = 0;
	if(bit > 31){ n = bit/32; bit = bit - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*(reg + n ) &= ~(mask << bit);
	*(reg + n ) |= (value << bit);
}

uint32_t function_getsetbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit)
{
	uint32_t n = 0;
	if(bit > 31){ n = bit/32; bit = bit - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = *(reg + n );
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}

void function_RegSetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg |= (unsigned int)(1 << va_arg(list, int));
		}
		va_end(list);
	}
}

void function_RegResetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg &= (unsigned int)~((1 << va_arg(list, int)) << 16);
		}
		va_end(list);
	}
}

void function_VecSetup( volatile uint32_t vec[], const unsigned int size_block, unsigned int data, unsigned int block_n )
{
	const unsigned int n_bits = sizeof(data) * 8;
	const unsigned int mask = (unsigned int) (pow(2, size_block) - 1);
	unsigned int index = (block_n * size_block) / n_bits;
	data &= mask;
	vec[index] &= ~( mask << ((block_n * size_block) - (index * n_bits)) );
	vec[index] |= ( data << ((block_n * size_block) - (index * n_bits)) );
}

/******/
// triggerA
uint32_t function_triggerA(uint32_t ll_io, uint8_t pin, uint32_t counter)
{
	mem[3] = 0;
	if(mem[0] == 0){
		if( ll_io & (1 << pin) ){ mem[1] = counter; mem[2] = 0; mem[0] = 1; }
	}
	if(mem[0] == 1){
		if( ll_io & (1 << pin) ){ if( counter != mem[1] ){ mem[2]++; mem[1] = counter; } }
		else{ mem[3] = mem[2]; mem[0] = 0; }
	}
	return mem[3];
}
// triggerB
uint32_t function_triggerB(uint32_t hl_io, uint32_t lh_io, uint8_t pin, uint32_t counter)
{
	nen[3] = 0;

	switch( nen[0] ){ // Start value
		case 0:
			if( hl_io & (1 << pin) ){ nen[1] = counter; nen[2] = 0; nen[0] = 1; }
		break;
		case 1:
			if( counter != nen[1] ){ nen[2]++; nen[1] = counter; }
			if( lh_io & (1 << pin) ){ nen[3] = nen[2]; nen[0] = 0; }
		break;
		default:
		break;
	}
	return nen[3];
}

uint32_t read_value(void){ return mem[2];}

/*** Not Used ***/
unsigned int function_mayia(unsigned int xi, unsigned int xf, uint8_t nbits)
{// magic formula
	unsigned int mask;
	unsigned int diff;
	unsigned int trans;
	mask = (unsigned int)(pow(2, nbits) - 1);
	xi &= mask;
	xf &= mask;
	diff = xf ^ xi;
	trans = diff & xf;
	return (trans << nbits) | diff;
}

uint8_t leap_year_check(uint16_t year){
	uint8_t i;
	if (!(year % 400))
    	i = 1;
  	else if (!(year % 100))
    	i = 0;
  	else if (!(year % 4) )
    	i = 1;
  	else
    	i = 0;
	return i;
}

/***EOF***/

/******
1º Sequence
2º Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3º Pointer and Variable
4º Casting
******/


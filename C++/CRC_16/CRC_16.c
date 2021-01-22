#include <stdio.h>

#define					P_16		0xA001
#define					P_32		0xEDB88320L
#define					P_CCITT		0x1021
#define					P_DNP		0xA6BC
#define					P_SICK		0x8005 
unsigned int calcByte(unsigned int crc, unsigned char b) //这个函数是用来进行位运算的，主要为下面的计算CRC来服务
{
	unsigned int i;
	crc = crc ^ (unsigned int)b << 8;

	for ( i = 0; i < 8; i++)
	{
		if ((crc & 0x8000) == 0x8000)
			crc = crc << 1 ^ P_SICK;
		else
			crc = crc << 1;
	}

	return
		crc & 0xffff;
}


//count crc-16, length in byte
//这个函数是计算16位CRC码的函数，只要给出要校验的数组，以及数组长度，就可以返回16位CRC校验码
unsigned int MakeCRC16(unsigned char *pBuffer, unsigned int length)
{
	unsigned int wCRC16=0;
	unsigned int i;
	if (( pBuffer==0 )||( length==0 ))
	{
		return 0;
	}
	for ( i = 0; i < length; i++)
	{
		wCRC16 = calcByte(wCRC16, pBuffer[i]);
	}
	return wCRC16;
}

unsigned char buff0[] ={0xF0,0xA5,0x14,0x01,0x10,0x01,0x96,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; 
//unsigned char buff1[] ={0xF0,0xA5,0x14,0x01,0x10,0x01,0x96,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,0xBF};	//P_CCITT
unsigned char buff1[] ={0xF0,0xA5,0x14,0x01,0x10,0x01,0x96,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf1,0x35};	//P_SICK
unsigned int crc_temp0 = 0;
unsigned int crc_temp1 = 0;

void main()
{
	crc_temp0 = MakeCRC16(buff0, 18);
	crc_temp1 = MakeCRC16(buff1, 20);

	printf("crc_temp0 = %#x\n", crc_temp0);
	printf("crc_temp1 = %d\n", crc_temp1);
}
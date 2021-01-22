

unsigned char crc8_byte(unsigned char crc, unsigned char value)
{
    crc = crc ^ value;
    for (i=8; i>0; --i)
    {
        if (crc & 0x80)
            crc = (crc << 1) ^ CRC8_P;
        else
            crc = (crc << 1);
    }
    return crc;
}
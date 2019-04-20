// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t SansSerif_plain_28Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x1F,0xF0, // '!'
	0xC7,0x8F,0x1E,0x3C,0x78,0xF1,0xE3, // '"'
	0x00,0xC3,0x00,0x38,0x60,0x06,0x1C,0x00,0xC3,0x00,0x18,0x60,0x03,0x0C,0x0F,0xFF,0xF9,0xFF,0xFF,0x03,0x0C,0x00,0x61,0x80,0x1C,0x70,0x03,0x0C,0x00,0x61,0x81,0xFF,0xFF,0x3F,0xFF,0xE0,0x61,0x80,0x0C,0x30,0x01,0x86,0x00,0x70,0xC0,0x0C,0x38,0x01,0x86,0x00, // '#'
	0x02,0x00,0x10,0x00,0x80,0x3F,0x83,0xFF,0x39,0x1B,0x88,0x1C,0x40,0xE2,0x07,0x90,0x1F,0x80,0xFF,0x81,0xFF,0x01,0xF8,0x09,0xE0,0x47,0x02,0x38,0x11,0xF0,0x9D,0xFF,0xC3,0xFC,0x01,0x00,0x08,0x00,0x40,0x02,0x00, // '$'
	0x3E,0x00,0x70,0x7F,0x00,0x60,0x63,0x00,0xC0,0xC1,0x81,0xC0,0xC1,0x83,0x80,0xC1,0x83,0x00,0xC1,0x87,0x00,0xC1,0x8E,0x00,0x63,0x0C,0x00,0x7F,0x1C,0x7C,0x3E,0x38,0xFE,0x00,0x30,0xC6,0x00,0x71,0x83,0x00,0xE1,0x83,0x00,0xC1,0x83,0x01,0xC1,0x83,0x03,0x81,0x83,0x03,0x00,0xC6,0x07,0x00,0xFE,0x0E,0x00,0x7C, // '%'
	0x07,0xE0,0x03,0xFE,0x00,0xF0,0x40,0x1C,0x00,0x03,0x80,0x00,0x70,0x00,0x0F,0x00,0x00,0xF0,0x00,0x3F,0x00,0x06,0xF0,0x39,0x8F,0x07,0x70,0xF0,0xCE,0x0F,0x39,0xC0,0xE6,0x38,0x1F,0xC7,0x01,0xF0,0x70,0x1E,0x0F,0x07,0xE0,0xFF,0xDE,0x07,0xE1,0xE0, // '&'
	0xFF,0xFF, // '''
	0x0C,0x61,0x8E,0x31,0xC7,0x18,0xE3,0x8E,0x38,0xE3,0x8E,0x38,0xE1,0x87,0x1C,0x30,0xE1,0x86,0x0C, // '('
	0xC1,0x86,0x1C,0x30,0xE3,0x86,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0xE3,0x8E,0x31,0xC6,0x18,0xC0, // ')'
	0x06,0x00,0x60,0x86,0x3E,0x67,0x3F,0xC0,0xF0,0x0F,0x03,0xFC,0xE6,0x7C,0x62,0x06,0x00,0x60, // '*'
	0x00,0xC0,0x00,0x30,0x00,0x0C,0x00,0x03,0x00,0x00,0xC0,0x00,0x30,0x00,0x0C,0x00,0x03,0x00,0xFF,0xFF,0xFF,0xFF,0xF0,0x0C,0x00,0x03,0x00,0x00,0xC0,0x00,0x30,0x00,0x0C,0x00,0x03,0x00,0x00,0xC0,0x00,0x30,0x00, // '+'
	0x77,0x77,0x6E,0xC0, // ','
	0xFF,0xFC, // '-'
	0xFF,0x80, // '.'
	0x01,0x81,0xC0,0xC0,0x60,0x30,0x30,0x18,0x0C,0x0C,0x06,0x03,0x03,0x81,0x80,0xC0,0x60,0x60,0x30,0x18,0x18,0x0C,0x06,0x07,0x03,0x00, // '/'
	0x0F,0xC0,0x7F,0x83,0x87,0x1C,0x0E,0x70,0x3B,0x80,0x6E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x76,0x01,0xDC,0x0E,0x70,0x38,0xE1,0xC1,0xFE,0x03,0xF0, // '0'
	0x1F,0x07,0xF8,0x39,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x38,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x38,0x3F,0xFF,0xFF,0xF0, // '1'
	0x3F,0x87,0xFF,0x38,0x3D,0x00,0xF0,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x70,0x07,0x80,0x78,0x07,0x80,0x78,0x07,0x80,0x7C,0x07,0xC0,0x7C,0x07,0xC0,0x3F,0xFF,0xFF,0xF0, // '2'
	0x1F,0x83,0xFF,0x18,0x38,0x00,0xE0,0x07,0x00,0x38,0x01,0xC0,0x1C,0x0F,0xC0,0x7E,0x00,0x3C,0x00,0xE0,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x74,0x07,0xBF,0xF8,0x7F,0x00, // '3'
	0x00,0xF0,0x03,0xE0,0x07,0xC0,0x1F,0x80,0x77,0x00,0xCE,0x03,0x1C,0x0E,0x38,0x18,0x70,0x60,0xE1,0xC1,0xC3,0x03,0x8C,0x07,0x1F,0xFF,0xFF,0xFF,0x80,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80, // '4'
	0x7F,0xE3,0xFF,0x1C,0x00,0xE0,0x07,0x00,0x38,0x01,0xFE,0x0F,0xFC,0x41,0xF0,0x03,0x80,0x1E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x0F,0x00,0x74,0x0F,0xBF,0xF8,0x7F,0x00, // '5'
	0x03,0xF0,0x3F,0xE1,0xC0,0x8E,0x00,0x70,0x01,0xC0,0x0E,0x00,0x39,0xF0,0xEF,0xF3,0xE1,0xEF,0x03,0xB8,0x07,0xE0,0x1F,0x80,0x76,0x01,0xD8,0x07,0x70,0x38,0xE1,0xE1,0xFF,0x01,0xF0, // '6'
	0xFF,0xFF,0xFF,0xC0,0x1E,0x00,0xE0,0x07,0x00,0x70,0x03,0x80,0x1C,0x01,0xC0,0x0E,0x00,0xF0,0x07,0x00,0x38,0x03,0xC0,0x1C,0x00,0xE0,0x0E,0x00,0x70,0x03,0x80,0x38,0x00, // '7'
	0x0F,0xC0,0xFF,0xC7,0x87,0xB8,0x07,0xE0,0x1F,0x80,0x7E,0x01,0xDC,0x1E,0x1F,0xE0,0x7F,0x87,0x87,0x9C,0x0E,0xE0,0x1F,0x80,0x7E,0x01,0xF8,0x07,0xF0,0x3D,0xE1,0xE3,0xFF,0x03,0xF0, // '8'
	0x0F,0x80,0xFF,0x87,0x87,0x1C,0x0E,0xE0,0x1B,0x80,0x6E,0x01,0xF8,0x07,0xE0,0x1D,0xC0,0xF7,0x87,0xCF,0xF7,0x0F,0x9C,0x00,0x70,0x03,0x80,0x0E,0x00,0x71,0x03,0x87,0xFC,0x0F,0xC0, // '9'
	0xFF,0x80,0x00,0x00,0x7F,0xC0, // ':'
	0x77,0x70,0x00,0x00,0x00,0x07,0x77,0x76,0xEC, // ';'
	0x00,0x00,0x40,0x00,0xF0,0x01,0xF8,0x03,0xF0,0x07,0xE0,0x0F,0xC0,0x0F,0xC0,0x03,0x80,0x00,0xFC,0x00,0x0F,0xC0,0x00,0x7E,0x00,0x03,0xF0,0x00,0x1F,0x80,0x00,0xF0,0x00,0x04, // '<'
	0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFC, // '='
	0x80,0x00,0x3C,0x00,0x07,0xE0,0x00,0x3F,0x00,0x01,0xF8,0x00,0x0F,0xC0,0x00,0xFC,0x00,0x07,0x00,0x0F,0xC0,0x0F,0xC0,0x1F,0x80,0x3F,0x00,0x7E,0x00,0x3C,0x00,0x08,0x00,0x00, // '>'
	0x1F,0x0F,0xFB,0x87,0x40,0x70,0x0E,0x01,0xC0,0x78,0x1E,0x07,0x81,0xE0,0x38,0x0E,0x01,0xC0,0x38,0x07,0x00,0x00,0x00,0x03,0x80,0x70,0x0E,0x00, // '?'
	0x00,0x7F,0x00,0x00,0xFF,0xF0,0x01,0xF0,0x3E,0x01,0xC0,0x03,0x81,0xC0,0x00,0xE1,0xC0,0x00,0x30,0xC1,0xF9,0x8C,0xC1,0xFE,0xC6,0x61,0xC1,0xE1,0xE0,0xC0,0x70,0xF0,0xC0,0x18,0x78,0x60,0x0C,0x3C,0x30,0x06,0x1E,0x18,0x03,0x0F,0x0C,0x01,0x8D,0x83,0x01,0xC6,0x61,0xC1,0xEE,0x30,0x7F,0xBE,0x1C,0x1F,0x9C,0x07,0x00,0x00,0x01,0xC0,0x00,0x00,0x70,0x00,0x80,0x1E,0x01,0xE0,0x03,0xFF,0xE0,0x00,0x7F,0x80,0x00, // '@'
	0x00,0xE0,0x00,0x3E,0x00,0x07,0xC0,0x00,0xF8,0x00,0x3B,0x80,0x07,0x70,0x01,0xEF,0x00,0x38,0xE0,0x07,0x1C,0x01,0xC1,0xC0,0x38,0x38,0x0F,0x07,0x81,0xFF,0xF0,0x3F,0xFE,0x0E,0x00,0xE1,0xC0,0x1C,0x78,0x03,0xCE,0x00,0x39,0xC0,0x07,0x70,0x00,0x70, // 'A'
	0xFF,0xC3,0xFF,0xCE,0x07,0x38,0x0E,0xE0,0x3B,0x80,0xEE,0x03,0xB8,0x1C,0xFF,0xE3,0xFF,0x8E,0x07,0xB8,0x0E,0xE0,0x1F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x3F,0x81,0xEF,0xFF,0x3F,0xF0, // 'B'
	0x03,0xF8,0x0F,0xFE,0x1E,0x07,0x38,0x03,0x70,0x00,0x70,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0x70,0x00,0x70,0x00,0x38,0x03,0x1E,0x07,0x0F,0xFE,0x03,0xF8, // 'C'
	0xFF,0xC0,0x7F,0xFC,0x38,0x0F,0x1C,0x01,0xCE,0x00,0x77,0x00,0x3B,0x80,0x0F,0xC0,0x07,0xE0,0x03,0xF0,0x01,0xF8,0x00,0xFC,0x00,0x7E,0x00,0x3F,0x00,0x1F,0x80,0x1D,0xC0,0x0E,0xE0,0x0E,0x70,0x1E,0x3F,0xFE,0x1F,0xF8,0x00, // 'D'
	0xFF,0xFF,0xFF,0xF8,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xFF,0xF7,0xFF,0xB8,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x3F,0xFF,0xFF,0xF0, // 'E'
	0xFF,0xFF,0xFF,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xFF,0xEF,0xFE,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00, // 'F'
	0x03,0xFC,0x03,0xFF,0xC1,0xE0,0x78,0xE0,0x06,0x70,0x00,0x9C,0x00,0x0E,0x00,0x03,0x80,0x00,0xE0,0x00,0x38,0x0F,0xFE,0x03,0xFF,0x80,0x07,0xE0,0x01,0xF8,0x00,0x77,0x00,0x1D,0xC0,0x07,0x38,0x01,0xC7,0x80,0xF0,0xFF,0xF8,0x07,0xF0, // 'G'
	0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xFF,0xFF,0xFF,0xFF,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07, // 'H'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0, // 'I'
	0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x8E,0xF9,0xE0, // 'J'
	0xE0,0x3C,0xE0,0x78,0xE0,0xF0,0xE1,0xE0,0xE3,0xC0,0xE7,0x80,0xEF,0x00,0xFE,0x00,0xFC,0x00,0xFC,0x00,0xFE,0x00,0xFF,0x00,0xEF,0x80,0xE7,0xC0,0xE3,0xE0,0xE1,0xF0,0xE0,0xF8,0xE0,0x7C,0xE0,0x3E,0xE0,0x1F, // 'K'
	0xE0,0x07,0x00,0x38,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x38,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x3F,0xFF,0xFF,0xF0, // 'L'
	0xF8,0x03,0xFF,0x80,0xFF,0xF0,0x1F,0xFF,0x07,0xFE,0xE0,0xEF,0xDC,0x1D,0xF9,0xC7,0x3F,0x38,0xE7,0xE7,0xBC,0xFC,0x77,0x1F,0x8E,0xE3,0xF1,0xFC,0x7E,0x1F,0x0F,0xC3,0xE1,0xF8,0x38,0x3F,0x07,0x07,0xE0,0x00,0xFC,0x00,0x1F,0x80,0x03,0xF0,0x00,0x70, // 'M'
	0xF0,0x0F,0xF0,0x1F,0xE0,0x3F,0xE0,0x7F,0xC0,0xFF,0xC1,0xFB,0x83,0xF3,0x87,0xE7,0x0F,0xC7,0x1F,0x8F,0x3F,0x0E,0x7E,0x1E,0xFC,0x1D,0xF8,0x3F,0xF0,0x3F,0xE0,0x7F,0xC0,0x7F,0x80,0xFF,0x00,0xF0, // 'N'
	0x03,0xF8,0x01,0xFF,0xC0,0x78,0x3C,0x1C,0x01,0xC7,0x80,0x3C,0xE0,0x03,0xBC,0x00,0x7F,0x00,0x07,0xE0,0x00,0xFC,0x00,0x1F,0x80,0x03,0xF0,0x00,0x7E,0x00,0x0F,0xC0,0x03,0xDC,0x00,0x73,0x80,0x0E,0x38,0x03,0x83,0xC1,0xE0,0x3F,0xF8,0x01,0xFC,0x00, // 'O'
	0xFF,0x87,0xFF,0x38,0x3D,0xC0,0xFE,0x03,0xF0,0x1F,0x80,0xFC,0x07,0xE0,0x7F,0x07,0xBF,0xF9,0xFF,0x0E,0x00,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x38,0x01,0xC0,0x00, // 'P'
	0x03,0xF8,0x01,0xFF,0xC0,0x78,0x3C,0x1C,0x01,0xC7,0x80,0x3C,0xE0,0x03,0xBC,0x00,0x7F,0x00,0x07,0xE0,0x00,0xFC,0x00,0x1F,0x80,0x03,0xF0,0x00,0x7E,0x00,0x0F,0xC0,0x03,0xDC,0x00,0x73,0x80,0x0E,0x38,0x03,0x83,0xC1,0xE0,0x3F,0xF8,0x01,0xFE,0x00,0x03,0xC0,0x00,0x3C,0x00,0x03,0xC0,0x00,0x3C, // 'Q'
	0xFF,0x80,0xFF,0xE0,0xE0,0xF0,0xE0,0x78,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x78,0xE0,0xF0,0xFF,0xE0,0xFF,0xC0,0xE0,0xE0,0xE0,0x70,0xE0,0x78,0xE0,0x38,0xE0,0x3C,0xE0,0x1E,0xE0,0x0E,0xE0,0x0F, // 'R'
	0x0F,0xE0,0xFF,0xE7,0x83,0xBC,0x02,0xE0,0x03,0x80,0x0E,0x00,0x3E,0x00,0x7F,0x80,0xFF,0x80,0xFF,0x80,0x3E,0x00,0x3C,0x00,0x70,0x01,0xC0,0x07,0x80,0x3F,0x81,0xEF,0xFF,0x0F,0xF0, // 'S'
	0xFF,0xFF,0xFF,0xFF,0xC0,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00, // 'T'
	0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xE0,0x07,0xF0,0x0F,0x70,0x0E,0x78,0x1E,0x3F,0xF8,0x0F,0xF0, // 'U'
	0xE0,0x00,0xEE,0x00,0x39,0xC0,0x07,0x3C,0x01,0xE3,0x80,0x38,0x70,0x07,0x07,0x01,0xC0,0xE0,0x38,0x1E,0x0F,0x01,0xC1,0xC0,0x38,0x38,0x03,0x8E,0x00,0x71,0xC0,0x0F,0x78,0x00,0xEE,0x00,0x1D,0xC0,0x01,0xF0,0x00,0x3E,0x00,0x07,0xC0,0x00,0x70,0x00, // 'V'
	0xE0,0x1E,0x01,0xF8,0x07,0x80,0xF7,0x01,0xE0,0x39,0xC0,0x78,0x0E,0x70,0x3F,0x03,0x9E,0x0C,0xC1,0xE3,0x83,0x30,0x70,0xE0,0xCC,0x1C,0x38,0x73,0x87,0x0F,0x18,0x63,0xC1,0xC6,0x18,0xE0,0x71,0x86,0x38,0x1C,0xE1,0xCE,0x07,0xB0,0x37,0x80,0xEC,0x0D,0xC0,0x3B,0x03,0x70,0x0F,0xC0,0xFC,0x01,0xE0,0x1F,0x00,0x78,0x07,0x80,0x1E,0x01,0xE0, // 'W'
	0x78,0x07,0x9E,0x07,0x87,0x03,0x83,0xC3,0xC0,0xE3,0xC0,0x79,0xC0,0x1F,0xE0,0x07,0xE0,0x03,0xE0,0x00,0xF0,0x00,0xF8,0x00,0x7E,0x00,0x7F,0x00,0x7B,0xC0,0x38,0xF0,0x3C,0x38,0x3C,0x1E,0x1C,0x07,0x1E,0x01,0xDE,0x00,0xF0, // 'X'
	0xF0,0x07,0xBC,0x07,0x8E,0x03,0x87,0x83,0xC1,0xE3,0xC0,0x71,0xC0,0x3D,0xE0,0x0F,0xE0,0x03,0xE0,0x01,0xF0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00, // 'Y'
	0xFF,0xFF,0xFF,0xFF,0xC0,0x01,0xE0,0x01,0xE0,0x01,0xE0,0x01,0xE0,0x01,0xE0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x3F,0xFF,0xFF,0xFF,0xF0, // 'Z'
	0xFF,0xFE,0x38,0xE3,0x8E,0x38,0xE3,0x8E,0x38,0xE3,0x8E,0x38,0xE3,0x8E,0x38,0xE3,0x8E,0x3F,0xFC, // '['
	0xC0,0x70,0x18,0x0C,0x06,0x01,0x80,0xC0,0x60,0x18,0x0C,0x06,0x03,0x80,0xC0,0x60,0x30,0x0C,0x06,0x03,0x00,0xC0,0x60,0x30,0x1C,0x06, // '\'
	0xFF,0xF1,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xFF,0xFC, // ']'
	0x01,0xE0,0x00,0xFC,0x00,0x7F,0x80,0x3C,0xF0,0x1E,0x1E,0x0F,0x03,0xC7,0x00,0x3B,0x80,0x07, // '^'
	0xFF,0xFF,0xFF,0xF0, // '_'
	0xE0,0xE0,0xE0,0xE0,0xE0, // '`'
	0x1F,0xC3,0xFF,0x10,0x3C,0x00,0x70,0x03,0x8F,0xFD,0xFF,0xEE,0x07,0xE0,0x3F,0x01,0xF8,0x1F,0xC0,0xFF,0x0F,0xBF,0xDC,0x78,0xE0, // 'a'
	0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80,0x0E,0x7C,0x3B,0xFC,0xF8,0x7B,0xC0,0xEF,0x03,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x3F,0xC0,0xEF,0x87,0xBB,0xFC,0xE7,0xC0, // 'b'
	0x0F,0xE1,0xFF,0x3C,0x17,0x00,0xF0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xF0,0x07,0x00,0x3C,0x11,0xFF,0x0F,0xE0, // 'c'
	0x00,0x1C,0x00,0x70,0x01,0xC0,0x07,0x00,0x1C,0x00,0x70,0xF9,0xCF,0xF7,0x78,0x7D,0xC0,0xFF,0x03,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x3D,0xC0,0xF7,0x87,0xCF,0xF7,0x0F,0x9C, // 'd'
	0x0F,0xC0,0x7F,0xC3,0x87,0x9C,0x0E,0xF0,0x1F,0x80,0x7F,0xFF,0xFF,0xFF,0xE0,0x03,0x80,0x0E,0x00,0x1C,0x00,0x38,0x08,0x7F,0xE0,0xFE,0x00, // 'e'
	0x0F,0xC7,0xF3,0xC0,0xE0,0x38,0x0E,0x0F,0xFB,0xFE,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0x80,0xE0,0x38,0x00, // 'f'
	0x0F,0x9C,0xFF,0x77,0x87,0xDC,0x0F,0xE0,0x3F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x03,0xDC,0x0F,0x78,0x7C,0xFF,0x70,0xF9,0xC0,0x07,0x00,0x1C,0x00,0xE2,0x07,0x8F,0xFC,0x1F,0xC0, // 'g'
	0xE0,0x07,0x00,0x38,0x01,0xC0,0x0E,0x00,0x70,0x03,0x8F,0x1D,0xFE,0xF8,0x77,0x83,0xF8,0x0F,0xC0,0x7E,0x03,0xF0,0x1F,0x80,0xFC,0x07,0xE0,0x3F,0x01,0xF8,0x0F,0xC0,0x7E,0x03,0x80, // 'h'
	0xFF,0x80,0x3F,0xFF,0xFF,0xFF,0xFF,0xFE, // 'i'
	0x1C,0x71,0xC0,0x00,0x01,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x3F,0xEF,0x00, // 'j'
	0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80,0x0E,0x07,0xB8,0x3C,0xE3,0xE3,0x9F,0x0E,0xF8,0x3F,0x80,0xFC,0x03,0xF0,0x0F,0xE0,0x3B,0xC0,0xE7,0x83,0x8F,0x0E,0x1E,0x38,0x3C,0xE0,0x78, // 'k'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE, // 'l'
	0xE7,0x83,0xC7,0x7E,0x3F,0xBE,0x3B,0x1D,0xE0,0xF0,0x7E,0x07,0x03,0xF0,0x38,0x1F,0x81,0xC0,0xFC,0x0E,0x07,0xE0,0x70,0x3F,0x03,0x81,0xF8,0x1C,0x0F,0xC0,0xE0,0x7E,0x07,0x03,0xF0,0x38,0x1F,0x81,0xC0,0xE0, // 'm'
	0xE3,0xC7,0x7F,0xBE,0x1D,0xE0,0xFE,0x03,0xF0,0x1F,0x80,0xFC,0x07,0xE0,0x3F,0x01,0xF8,0x0F,0xC0,0x7E,0x03,0xF0,0x1F,0x80,0xE0, // 'n'
	0x0F,0xC0,0xFF,0xC7,0x87,0x9C,0x0E,0xF0,0x3F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x03,0xDC,0x0E,0x78,0x78,0xFF,0xC0,0xFC,0x00, // 'o'
	0xE7,0xC3,0xBF,0xCF,0x87,0xBC,0x0E,0xF0,0x3F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x03,0xFC,0x0E,0xF8,0x7B,0xBF,0xCE,0x7C,0x38,0x00,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x00, // 'p'
	0x0F,0x9C,0xFF,0x77,0x87,0xDC,0x0F,0xF0,0x3F,0x80,0x7E,0x01,0xF8,0x07,0xE0,0x1F,0x80,0x7E,0x03,0xDC,0x0F,0x78,0x7C,0xFF,0x70,0xF9,0xC0,0x07,0x00,0x1C,0x00,0x70,0x01,0xC0,0x07,0x00,0x1C, // 'q'
	0xE7,0xF7,0xFE,0x3E,0x0E,0x07,0x03,0x81,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x07,0x03,0x80, // 'r'
	0x1F,0xC7,0xFE,0xF0,0x2E,0x00,0xE0,0x0F,0x00,0x7E,0x03,0xFC,0x07,0xE0,0x0F,0x00,0x70,0x07,0xC0,0xFF,0xFE,0x3F,0x80, // 's'
	0x38,0x0E,0x03,0x80,0xE0,0xFF,0xFF,0xF3,0x80,0xE0,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0x80,0xE0,0x3C,0x07,0xF0,0xFC, // 't'
	0xE0,0x3F,0x01,0xF8,0x0F,0xC0,0x7E,0x03,0xF0,0x1F,0x80,0xFC,0x07,0xE0,0x3F,0x01,0xF8,0x0F,0xE0,0xF7,0x0F,0xBF,0xDC,0x78,0xE0, // 'u'
	0xE0,0x0E,0xE0,0x39,0xC0,0x73,0xC1,0xE3,0x83,0x87,0x07,0x07,0x1E,0x0E,0x38,0x1C,0xF0,0x1D,0xC0,0x3B,0x80,0x7F,0x00,0x7C,0x00,0xF8,0x00,0xE0,0x00, // 'v'
	0xE0,0x70,0x3F,0x83,0x83,0xDC,0x3E,0x1C,0xE1,0xB0,0xE7,0x0D,0x87,0x3C,0x6C,0x78,0xE6,0x33,0x87,0x31,0x9C,0x39,0x8C,0xE0,0xEC,0x6E,0x07,0xC1,0xF0,0x3E,0x0F,0x81,0xF0,0x7C,0x07,0x83,0xC0,0x38,0x0E,0x00, // 'w'
	0x78,0x1E,0x78,0x78,0x79,0xE0,0x73,0x80,0xFF,0x00,0xFC,0x00,0xF0,0x01,0xE0,0x07,0xC0,0x1F,0xC0,0x3F,0xC0,0xF3,0x83,0xC3,0x8F,0x07,0xBC,0x07,0x80, // 'x'
	0xE0,0x0E,0xE0,0x39,0xC0,0x73,0xC1,0xE3,0x83,0x87,0x0F,0x07,0x1C,0x0E,0x38,0x1E,0xE0,0x1D,0xC0,0x3F,0x80,0x3E,0x00,0x7C,0x00,0xF0,0x00,0xE0,0x03,0xC0,0x07,0x00,0x1E,0x00,0x38,0x03,0xF0,0x07,0x80,0x00, // 'y'
	0xFF,0xFF,0xFF,0x00,0xF0,0x1E,0x03,0xC0,0x3C,0x07,0x80,0xF0,0x1E,0x01,0xC0,0x3C,0x07,0x80,0xF0,0x0F,0xFF,0xFF,0xF0, // 'z'
	0x03,0xE0,0xFC,0x3C,0x07,0x00,0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x0E,0x0F,0x81,0xF0,0x07,0x00,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x03,0x80,0x78,0x07,0xE0,0x7C, // '{'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // '|'
	0xF8,0x1F,0x80,0x78,0x07,0x00,0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x03,0x80,0x3E,0x07,0xC1,0xC0,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x03,0x80,0xF0,0xFC,0x1F,0x00 // '}'
};
const GFXglyph SansSerif_plain_28Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,  10,    0,    0 }, // ' '
	  {     1,   3,  20,  12,    4,  -20 }, // '!'
	  {     9,   7,   8,  14,    3,  -20 }, // '"'
	  {    16,  19,  21,  24,    2,  -21 }, // '#'
	  {    66,  13,  25,  19,    2,  -21 }, // '$'
	  {   107,  24,  20,  28,    2,  -20 }, // '%'
	  {   167,  19,  20,  23,    2,  -20 }, // '&'
	  {   215,   2,   8,   9,    3,  -20 }, // '''
	  {   217,   6,  25,  12,    2,  -21 }, // '('
	  {   236,   6,  25,  12,    2,  -21 }, // ')'
	  {   255,  12,  12,  15,    1,  -20 }, // '*'
	  {   273,  18,  18,  24,    3,  -18 }, // '+'
	  {   314,   4,   7,  10,    2,   -3 }, // ','
	  {   318,   7,   2,  11,    1,   -9 }, // '-'
	  {   320,   3,   3,  10,    3,   -3 }, // '.'
	  {   322,   9,  23,  10,    0,  -20 }, // '/'
	  {   348,  14,  20,  19,    2,  -20 }, // '0'
	  {   383,  13,  20,  19,    3,  -20 }, // '1'
	  {   416,  13,  20,  19,    2,  -20 }, // '2'
	  {   449,  13,  20,  19,    2,  -20 }, // '3'
	  {   482,  15,  20,  19,    1,  -20 }, // '4'
	  {   520,  13,  20,  19,    2,  -20 }, // '5'
	  {   553,  14,  20,  19,    2,  -20 }, // '6'
	  {   588,  13,  20,  19,    2,  -20 }, // '7'
	  {   621,  14,  20,  19,    2,  -20 }, // '8'
	  {   656,  14,  20,  19,    2,  -20 }, // '9'
	  {   691,   3,  14,  10,    3,  -14 }, // ':'
	  {   697,   4,  18,  10,    2,  -14 }, // ';'
	  {   706,  18,  15,  24,    3,  -16 }, // '<'
	  {   740,  18,   7,  24,    3,  -12 }, // '='
	  {   756,  18,  15,  24,    3,  -16 }, // '>'
	  {   790,  11,  20,  16,    2,  -20 }, // '?'
	  {   818,  25,  25,  29,    2,  -20 }, // '@'
	  {   897,  19,  20,  20,    0,  -20 }, // 'A'
	  {   945,  14,  20,  20,    3,  -20 }, // 'B'
	  {   980,  16,  20,  21,    2,  -20 }, // 'C'
	  {  1020,  17,  20,  23,    3,  -20 }, // 'D'
	  {  1063,  13,  20,  19,    3,  -20 }, // 'E'
	  {  1096,  12,  20,  17,    3,  -20 }, // 'F'
	  {  1126,  18,  20,  23,    2,  -20 }, // 'G'
	  {  1171,  16,  20,  22,    3,  -20 }, // 'H'
	  {  1211,   3,  20,   9,    3,  -20 }, // 'I'
	  {  1219,   7,  26,   9,   -1,  -20 }, // 'J'
	  {  1242,  16,  20,  19,    3,  -20 }, // 'K'
	  {  1282,  13,  20,  17,    3,  -20 }, // 'L'
	  {  1315,  19,  20,  25,    3,  -20 }, // 'M'
	  {  1363,  15,  20,  22,    3,  -20 }, // 'N'
	  {  1401,  19,  20,  23,    2,  -20 }, // 'O'
	  {  1449,  13,  20,  18,    3,  -20 }, // 'P'
	  {  1482,  19,  24,  23,    2,  -20 }, // 'Q'
	  {  1539,  16,  20,  20,    3,  -20 }, // 'R'
	  {  1579,  14,  20,  19,    2,  -20 }, // 'S'
	  {  1614,  17,  20,  18,    0,  -20 }, // 'T'
	  {  1657,  16,  20,  22,    3,  -20 }, // 'U'
	  {  1697,  19,  20,  20,    0,  -20 }, // 'V'
	  {  1745,  26,  20,  29,    1,  -20 }, // 'W'
	  {  1810,  17,  20,  20,    1,  -20 }, // 'X'
	  {  1853,  17,  20,  18,    0,  -20 }, // 'Y'
	  {  1896,  17,  20,  20,    1,  -20 }, // 'Z'
	  {  1939,   6,  25,  12,    2,  -21 }, // '['
	  {  1958,   9,  23,  10,    0,  -20 }, // '\'
	  {  1984,   6,  25,  12,    3,  -21 }, // ']'
	  {  2003,  18,   8,  24,    3,  -20 }, // '^'
	  {  2021,  14,   2,  15,    0,    5 }, // '_'
	  {  2025,   7,   5,  15,    2,  -22 }, // '`'
	  {  2030,  13,  15,  18,    2,  -15 }, // 'a'
	  {  2055,  14,  21,  19,    3,  -21 }, // 'b'
	  {  2092,  12,  15,  16,    2,  -15 }, // 'c'
	  {  2115,  14,  21,  19,    2,  -21 }, // 'd'
	  {  2152,  14,  15,  18,    2,  -15 }, // 'e'
	  {  2179,  10,  21,  11,    1,  -21 }, // 'f'
	  {  2206,  14,  21,  19,    2,  -15 }, // 'g'
	  {  2243,  13,  21,  19,    3,  -21 }, // 'h'
	  {  2278,   3,  21,   9,    3,  -21 }, // 'i'
	  {  2286,   6,  27,   9,    0,  -21 }, // 'j'
	  {  2307,  14,  21,  17,    3,  -21 }, // 'k'
	  {  2344,   3,  21,   9,    3,  -21 }, // 'l'
	  {  2352,  21,  15,  28,    3,  -15 }, // 'm'
	  {  2392,  13,  15,  19,    3,  -15 }, // 'n'
	  {  2417,  14,  15,  18,    2,  -15 }, // 'o'
	  {  2444,  14,  21,  19,    3,  -15 }, // 'p'
	  {  2481,  14,  21,  19,    2,  -15 }, // 'q'
	  {  2518,   9,  15,  13,    3,  -15 }, // 'r'
	  {  2535,  12,  15,  16,    2,  -15 }, // 's'
	  {  2558,  10,  19,  12,    1,  -19 }, // 't'
	  {  2582,  13,  15,  19,    3,  -15 }, // 'u'
	  {  2607,  15,  15,  18,    1,  -15 }, // 'v'
	  {  2636,  21,  15,  24,    1,  -15 }, // 'w'
	  {  2676,  15,  15,  18,    1,  -15 }, // 'x'
	  {  2705,  15,  21,  18,    1,  -15 }, // 'y'
	  {  2745,  12,  15,  16,    1,  -15 }, // 'z'
	  {  2768,  11,  26,  19,    4,  -21 }, // '{'
	  {  2804,   2,  28,  10,    4,  -21 }, // '|'
	  {  2811,  11,  26,  19,    4,  -21 } // '}'
};
const GFXfont SansSerif_plain_28 PROGMEM = {
(uint8_t  *)SansSerif_plain_28Bitmaps,(GFXglyph *)SansSerif_plain_28Glyphs,0x20, 0x7E, 33};
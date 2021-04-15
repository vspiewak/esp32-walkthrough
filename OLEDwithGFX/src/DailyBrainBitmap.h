#include <Arduino.h>

//https://diyusthad.com/image2cpp
const unsigned char dailybrainBitmap [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0xfc, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1f, 0xff, 0x80, 0x00, 0x00, 0x1c, 0xe0, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x1c, 0xe0, 0x07, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0x0f, 0xe0, 0x00, 0x00, 0x38, 0xe0, 0x0f, 0xf8, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xf0, 0x01, 0xf0, 0x00, 0x00, 0x38, 0xc0, 0x1f, 0x80, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xc0, 0x00, 0xf8, 0x00, 0x1e, 0x38, 0xc0, 0x1c, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x1e, 0x00, 0x00, 
	0x07, 0x00, 0x78, 0x00, 0x1e, 0x79, 0xc0, 0x00, 0x70, 0x03, 0xe0, 0x00, 0x00, 0x3e, 0x00, 0x00, 
	0x0f, 0x00, 0x78, 0x00, 0x3e, 0x71, 0xc0, 0x00, 0xf0, 0x03, 0xc0, 0x00, 0x00, 0x3e, 0x00, 0x00, 
	0x0f, 0x00, 0x78, 0x00, 0x1e, 0x71, 0x80, 0x00, 0xf0, 0x03, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00, 
	0x0f, 0x00, 0x7c, 0x00, 0x00, 0x73, 0x80, 0x00, 0xf0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0f, 0x00, 0x7c, 0x00, 0x00, 0x73, 0x80, 0x00, 0xe0, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1e, 0x00, 0x7c, 0x70, 0x18, 0xf7, 0x18, 0x71, 0xe3, 0xfe, 0x61, 0xc0, 0xf0, 0x18, 0x30, 0xe0, 
	0x1e, 0x00, 0x79, 0xfc, 0x3c, 0xf7, 0x3c, 0x71, 0xe3, 0xf8, 0xe3, 0xe1, 0xfc, 0x38, 0x73, 0xe0, 
	0x1e, 0x00, 0x7f, 0xfe, 0x38, 0xfe, 0x38, 0xf1, 0xe3, 0xfc, 0xe7, 0xe3, 0xfe, 0x38, 0x77, 0xe0, 
	0x1e, 0x00, 0x7f, 0x9e, 0x38, 0xfe, 0x38, 0xf1, 0xe0, 0x3e, 0xef, 0xc7, 0x9c, 0x38, 0xf7, 0xe0, 
	0x1e, 0x00, 0xff, 0x1c, 0x78, 0xfc, 0x78, 0xe1, 0xc0, 0x1f, 0xff, 0xcf, 0x1c, 0x78, 0xff, 0xe0, 
	0x3c, 0x00, 0xff, 0x1c, 0x78, 0xf8, 0x79, 0xe3, 0xc0, 0x1f, 0xf9, 0xcf, 0x1c, 0x78, 0xfd, 0xe0, 
	0x3c, 0x01, 0xfe, 0x1c, 0x78, 0xf8, 0x79, 0xe3, 0xc0, 0x1f, 0xf9, 0xfe, 0x3c, 0x70, 0xf9, 0xe0, 
	0x3c, 0x01, 0xfe, 0x3c, 0x70, 0xf0, 0x73, 0xe3, 0xc0, 0x1f, 0xf1, 0xfe, 0x3c, 0x70, 0xf9, 0xc2, 
	0x3c, 0x07, 0xee, 0x3c, 0x71, 0xf0, 0x7b, 0xe7, 0xc0, 0x3f, 0xf0, 0xfe, 0x3c, 0xf1, 0xf9, 0xc6, 
	0x3c, 0x1f, 0xce, 0x3c, 0xfb, 0xf1, 0xff, 0xff, 0xc0, 0xfd, 0xe0, 0x1e, 0x7d, 0xfb, 0xf1, 0xce, 
	0x3f, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xe0, 0x0f, 0xff, 0xff, 0xf1, 0xfe, 
	0x3f, 0xfe, 0x0f, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xf1, 0xe0, 0x0f, 0xff, 0xff, 0xf1, 0xfc, 
	0x3f, 0xf0, 0x07, 0x8f, 0x3e, 0x1f, 0x3d, 0xe3, 0xff, 0x80, 0xc0, 0x07, 0x8f, 0x3e, 0x60, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#pragma once
#include <stdint.h>
#include <stddef.h>

struct Framebuffer {
	void *Address;
	uint32_t Width;
	uint32_t Height;
	uint16_t BPP;
	uint8_t RedShift;
	uint8_t GreenShift;
	uint8_t BlueShift;
}__attribute__((packed));

extern uint8_t font[128][8];

void InitFB(Framebuffer *data);
void FB_PrintScreen(const char *string);
void FB_PutChar(const char ch);
void FB_PrintScreen(int row, int col, const char *string);


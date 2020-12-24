#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argv[1]==NULL)return 1;
	if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--h") || !strcmp(argv[1], "/?"))
	{
		printf("HexToRGB Version-1.0\n"
               "Copyright (C) 2018-2020 MathInDOS\n"
			   "Build Date: 23 December 2020\n\n"
               "Usage: Hex2RGB [hex value]\n"
               "Ex: Hex2RGB 0x00ff00\n\n"
               "Note: Don't forget to give [0x] to get RGB value.\n");
        return 0;
	}
	
	if(argv[1][0] != '0')return 1;
	int hex = (int)strtol(argv[1], NULL, 0);
	int r = (hex >> 16) & 0xff;
	int g = (hex >> 8) & 0xff;
	int b = (hex) & 0xff;
	strupr(argv[1]);
	printf("Hex Code: %s", argv[1]);
	printf("  --  RGB Code: Red: %d Green: %d Blue: %d", r, g, b);
	return 0;
}

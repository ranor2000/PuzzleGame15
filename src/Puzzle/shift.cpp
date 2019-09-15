#include "shift.h"

int recmo(int a, int n, byte** rec) {
	int i, j;
	byte t;
	switch (a) {
	case 87:
	yt:for (i = 1; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (rec[i][j] == EMPTY) {
				t = rec[i][j];
				rec[i][j] = rec[i - 1][j];
				rec[i - 1][j] = t;
				n++;
				break;
			}break;
	case 83:
	yd:for (i = 2; i >= 0; i--)
		for (j = 0; j < 4; j++)
			if (rec[i][j] == EMPTY) {
				t = rec[i][j];
				rec[i][j] = rec[i + 1][j];
				rec[i + 1][j] = t;
				n++;
				break;
			}break;
	case 68:
	xr:for (i = 0; i < 4; i++)
		for (j = 2; j >= 0; j--)
			if (rec[i][j] == EMPTY) {
				t = rec[i][j];
				rec[i][j] = rec[i][j + 1];
				rec[i][j + 1] = t;
				n++;
				break;
			}break;
	case 65:
	xl:for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			if (rec[i][j] == EMPTY) {
				t = rec[i][j];
				rec[i][j] = rec[i][j - 1];
				rec[i][j - 1] = t;
				n++;
				break;
			}break;
	case 119:
		goto yt;
	case 115:
		goto yd;
	case 100:
		goto xr;
	case 97:
		goto xl;
	case 150:
		goto yt;
	case 155:
		goto yd;
	case 130:
		goto xr;
	case 148:
		goto xl;
	case 230:
		goto yt;
	case 235:
		goto yd;
	case 162:
		goto xr;
	case 228:
		goto xl;
	default: break;
	}
	return n;
}
#define F_CPU  16000000UL

#include <util/delay.h>
#include "keypad.h"


#define ROW_NO  4
#define COL_NO	4

u8 keypad_keyLayout[ROW_NO][COL_NO] =
{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};


static u8 keypad_getColumn(void)
{
	u8 loc_col = 255 ;
	if (dio_readPin(KPAD_COL0_PORT, KPAD_COL0_PIN) == LOW)
	{
		loc_col =0;
	}
	else if (dio_readPin(KPAD_COL1_PORT, KPAD_COL1_PIN) == LOW)
	{
		loc_col =1;
	}
	else if (dio_readPin(KPAD_COL2_PORT, KPAD_COL2_PIN) == LOW)
	{
		loc_col =2;
	}
	else if (dio_readPin(KPAD_COL3_PORT, KPAD_COL3_PIN) == LOW)
	{
		loc_col =3;
	}
	else
	{
		/* do nothing*/
	}
	return loc_col;
}

static u8 keypad_getRow(u8 loc_col)
{
	u8 loc_row =255;
	dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, LOW);
	dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
	dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
	dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
	if (keypad_getColumn() == loc_col)
	{
		loc_row =0;
	}
	else
	{
		dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
		dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, LOW);
		dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
		dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
		if (keypad_getColumn() == loc_col)
		{
			loc_row =1;
		}
		else
		{
			dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
			dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
			dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, LOW);
			dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
			if (keypad_getColumn() == loc_col)
			{
				loc_row =2;
			}
			else
			{
				dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
				dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
				dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
				dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, LOW);
				if (keypad_getColumn() == loc_col)
				{
					loc_row =3;
				}
				else
				{
					loc_row =255;
				}
			}
		}
	}
	return loc_row;
}

static void Keypad_reset(void)
{
	dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
	dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
	dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
	dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
}


void keypad_init(void)
{
	dio_setPinDirection(KPAD_ROW0_PORT, KPAD_ROW0_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW1_PORT, KPAD_ROW1_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW2_PORT, KPAD_ROW2_PIN, OUTPUT);
	dio_setPinDirection(KPAD_ROW3_PORT, KPAD_ROW3_PIN, OUTPUT);

	dio_setPinDirection(KPAD_COL0_PORT, KPAD_COL0_PIN, INPUT);
	dio_setPinDirection(KPAD_COL1_PORT, KPAD_COL1_PIN, INPUT);
	dio_setPinDirection(KPAD_COL2_PORT, KPAD_COL2_PIN, INPUT);
	dio_setPinDirection(KPAD_COL3_PORT, KPAD_COL3_PIN, INPUT);

	dio_writePin(KPAD_COL0_PORT, KPAD_COL0_PIN, HIGH);
	dio_writePin(KPAD_COL1_PORT, KPAD_COL1_PIN, HIGH);
	dio_writePin(KPAD_COL2_PORT, KPAD_COL2_PIN, HIGH);
	dio_writePin(KPAD_COL3_PORT, KPAD_COL3_PIN, HIGH);

	dio_writePin(KPAD_ROW0_PORT, KPAD_ROW0_PIN, HIGH);
	dio_writePin(KPAD_ROW1_PORT, KPAD_ROW1_PIN, HIGH);
	dio_writePin(KPAD_ROW2_PORT, KPAD_ROW2_PIN, HIGH);
	dio_writePin(KPAD_ROW3_PORT, KPAD_ROW3_PIN, HIGH);
}


boolean keypad_keyIsPressed(void)
{
	if (
	dio_readPin(KPAD_COL0_PORT, KPAD_COL0_PIN) == LOW ||
	dio_readPin(KPAD_COL1_PORT, KPAD_COL1_PIN) == LOW ||
	dio_readPin(KPAD_COL2_PORT, KPAD_COL2_PIN) == LOW ||
	dio_readPin(KPAD_COL3_PORT, KPAD_COL3_PIN) == LOW
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

u8 keypad_getKeyPressed(void)
{
	u8 rows[] = {KPAD_ROW0_PIN, KPAD_ROW1_PIN, KPAD_ROW2_PIN, KPAD_ROW3_PIN};
	u8 cols[] = {KPAD_COL0_PIN, KPAD_COL1_PIN, KPAD_COL2_PIN, KPAD_COL3_PIN};
	u8 row_ports[] = {KPAD_ROW0_PORT, KPAD_ROW1_PORT, KPAD_ROW2_PORT, KPAD_ROW3_PORT};
	u8 col_ports[] = {KPAD_COL0_PORT, KPAD_COL1_PORT, KPAD_COL2_PORT, KPAD_COL3_PORT};

	for (int r = 0; r < ROW_NO; r++)
	{
		dio_writePin(row_ports[r], rows[r], LOW);

		for (int c = 0; c < COL_NO; c++)
		{
			if (dio_readPin(col_ports[c], cols[c]) == LOW)
			{
				_delay_ms(50);
				dio_writePin(row_ports[r], rows[r], HIGH);
				return keypad_keyLayout[r][c];
			}
		}
		dio_writePin(row_ports[r], rows[r], HIGH);
	}

	return 255;
}


u8 keypad_waitForKey(void) {
	u8 key = 0xFF;

	while ((key = keypad_getKeyPressed()) == 0xFF);

	while (keypad_getKeyPressed() != 0xFF);

	return key;
}
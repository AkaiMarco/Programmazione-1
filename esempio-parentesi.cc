


void init(char* translation_table)
{
	for(int i = 0; i < 256; ++i) {
		translation_table[i] = i;
	}

	tranlastion_table['('] = '[';
	tranlastion_table[')'] = ']';
	tranlastion_table['['] = '{';
	tranlastion_table[']'] = '}';
	tranlastion_table['{'] = '(';
	tranlastion_table['}'] = ')';
}


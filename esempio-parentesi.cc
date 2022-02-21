#include <iostream>
#include <cstring>


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

int main(int argc, char* argv[])
{
	char translation_table[256];

	init(translation_table);

	if (argc !=  2) {
		return 1;
	}

	for(char *p = argv[1] ; *p; ++p) {
		*p = translation_table[(int)(*p)];
	}

	std::cout << p << std::endl;
	return 0;
}



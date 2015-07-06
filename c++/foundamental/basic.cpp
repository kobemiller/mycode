// c++ÖĞµÄ²¼¶ûÀàĞÍ
// 	c++ÖĞbool¿ÉÈ¡µÄÖµÖ»ÓĞtrueºÍfalse¡£
// 	ÀíÂÛÉÏboolÖ»Õ¼ÓÃÒ»¸ö×Ö½Ú£¬Èç¹û¶à¸öbool±äÁ¿¶¨ÒåÔÚÒ»Æğ£¬¿ÉÄÜ»á¸÷Õ¼Ò»¸öbit£¬È¡¾öÓÚ±àÒëÆ÷µÄÊµÏÖ¡£
// 	*true´ú±íÕæÖµ£¬±àÒëÆ÷ÄÚ²¿ÓÃ1±íÊ¾£»
// 	*false´ú±í·ÇÕæÖµ£¬±àÒëÆ÷ÄÚ²¿ÓÃ0±íÊ¾£»
// 	C++¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿true¿0¿¿¿¿false

#include <iostream>

void bool_test()
{
    int a;
	bool b = true;

	//´òÓ¡boolÀàĞÍËùÕ¼µÄ×Ö½Ú
	std::cout << "b = " << b << ", sizeof(b) = " << sizeof(b) << std::endl;

	b = 3;
	a = b;
	std::cout << "a = " << a << "b = " << b << std::endl;

	b = 0;
	std::cout << "b = " << b << std::endl;

    b = false;
    b++; 
	std::cout << "b = " << b << std::endl;

    b += 1;
	std::cout << "b = " << b << std::endl;
}

void triple()
{
    int a = 1;
    int b = 2;

    /*
     * c¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
     * c++¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
     * ¿¿¿a=3,b = 2
     * ¿¿¿c¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
     *      c++¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
     *      ¿¿¿¿¿¿¿
     * ¿¿¿c++¿¿¿
     */
    (a < b ? a : b) = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
}

/*
 * ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 * Tip¿ ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 *      ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 * ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 *
 */
void quote()
{
    int a = 4;
    int &b = a;

    b = 5;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "&a = " << &a << std::endl;
    std::cout << "&b = " << &b << std::endl;
}

int main()
{
    //bool_test();
    //triple();
    quote();

	return 0;
}



class poser
{
public:
	virtual void beat() const
	{
		std::cout << "一般选手的力量为260磅" << std::endl;
	}
protected:
	int age;
};
class ali : public poser
{
public:
	void beat() const
	{
		std::cout << "ali一拳的力量为420磅" << std::endl;
	}
};
class lewis : public poser
{
public:
	void beat() const
	{
		std::cout << "lewis一拳的力量为480磅" << std::endl;
	}
};
class tyson : public poser
{
public:
	void beat() const
	{
		std::cout << "tyson一拳的力量为500磅" << std::endl;
	}
};
class holy : public poser
{
public:
	void beat() const
	{
		std::cout << "holy一拳的力量为350磅" << std::endl;
	}
};

int main()
{
	poser *p[5];
	poser *p1;
	int choice, i;
	for ( i = 0; i < 5; i++ )
	{
		std::cout << "1)ali 2)lewis 3)tyson 4)holy: ";
		std::cin >> choice;
		switch ( choice )
		{
		case 1:
			p = new ali;
			break;
        case 2:
            p = new lewis;
            break;
        case 3:
            p = new tyson;
            break;
        case 4:
            p = new holy;
            break;
        default:
            p = new poser;
            break;
		}
        a[i] = p;
        a[i]->beat();
	}
	
	return 0;
}

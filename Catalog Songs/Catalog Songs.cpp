#include<iostream>
#include<vector>
#include<string>


class Catalog
{
public:
	std::string name_song;
	std::string autor_song;
	std::string text;
	int year_create;

	Catalog()
	{ 
		name_song = " no name ";
		autor_song = " no autor ";
		text = " no text ";
		year_create = 0;
	}
	void redact()
	{
		std::cout << "Enter name song \n";
		std::cin.ignore();
		getline(std::cin, name_song);
		std::cout << "Enter autor song \n";
		std::cin.ignore();
		getline(std::cin, autor_song);
		std::cout << "Enter Year create song \n";
		std::cin >> year_create;
		std::cout << "Enter text song \n";
		std::cin.ignore();
		getline(std::cin, text);
	}


private:
	void print()
	{
		std::cout << "Song name: " << name_song << " \n";
		std::cout << "Autor song: " << autor_song << " \n";
		std::cout << "Year create: " << year_create << " \n";
		std::cout << "Text song: " << text << " \n";
	}
	~Catalog()
	{

	}
};

int main()
{
	int choose = 10;
	std::cout << "����� ���������� � ������� �����.\n" <<
		"�������� ����� ����\n";
	while (choose!=0)
	{
		std::cout << "1. �������� ����� �����\n";
		std::cout << "2. ������� ������ �����\n";
		std::cout << "3. ��������� ������ �����\n";
		std::cout << "4. ����������� ������ ����� �� �����\n";
		std::cout << "5. ���������� ������ ����� � ����\n";
		std::cout << "6. ����� � ����������� ���� ����� ������ ������\n";
		std::cout << "7. ����� � ����������� ���� ����� ���������� ����� ��������� �������������\n";
		std::cout << "0. �����\n";
		std::cin >> choose;
		switch (choose)
		{
		case 1://�������� ����� �����
			std::cout << "�������� ����� ����\n";
			int add_choose=10;
			while (add_choose!=0)
			{
				std::cout << "1. �������� ����� ����� ��������������\n";
				std::cout << "2. ��������� ����� ����� �� �����\n";
				std::cout << "0. \n";
				std::cin >> add_choose;
			}
			switch (add_choose)
			{
			case 1:

				break;
			case 2:

				break;
			case 0:

				break;

			default:
				std::cout << " �� ���������� ����, ��������� �����\n";
				break;
			}

			break;
		case 2://������� ������ �����

			break;
		case 3://��������� ������ �����

			break;
		case 4://����������� ������ ����� �� �����

			break;
		case 5://���������� ������ ����� � ����

			break;
		case 6://����� � ����������� ���� ����� ������ ������

			break;
		case 7://����� � ����������� ���� ����� ���������� ����� ��������� �������������

			break;
		case 8://�����

			break;
		default:
			std::cout << " �� ���������� ����, ��������� �����\n";
			break;
		}
	}
}
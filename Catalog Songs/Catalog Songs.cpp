#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<conio.h>


struct Catalog
{

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
		std::getline(std::cin, name_song);
		std::cout << "Enter autor song \n";
		std::cin.ignore();
		std::getline(std::cin, autor_song);
		std::cout << "Enter Year create song \n";
		std::cin >> year_create;
		std::cout << "Enter text song , after enter escape\n";
		std::cin.ignore(32676, _getch());
		while (_getch()!=27)
		{
			std::getline(std::cin, text);
		}
		
	}

	
       void print()
	{
		std::cout << "Song name: " << name_song << " \n";
		std::cout << "Autor song: " << autor_song << " \n";
		std::cout << "Year create: " << year_create << " \n";
		std::cout << "Text song: " << text << " \n";
	}
	/*~Catalog()
	{

	}*/

	   void save(std::string save_str)
	   {
		   std::ofstream save_file;
		   save_file.open("catalog.txt", std::ios::app);
		   if (save_file.is_open())
		   {
			   save_file << "Song name: " << name_song << '\n';
			   save_file << "Author: " << autor_song << '\n';
			   save_file << "Release date: " << year_create << '\n';
			   save_file << "Text: " << text << '\n';
			   std::cout << std::endl;
		   }
		   else
		   {
			   std::cout << "File for save not open. \n";
		   }
		   save_file.close();
	   }

};

int main()
{
	setlocale(0, "ru");
	int choose = 10;
	int add_choose = 10;
	Catalog cat_free;
	std::vector<Catalog> vect_cat;
	int num = 0;
	std::ifstream dlya_chteniya;
	std::ofstream dlya_zapisi;
	std::string odna_stroka,all_str;
	std::string save_str = " ��� ���������� ";
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
			while (add_choose!=0)
			{
				std::cout << "1. �������� ����� ����� ��������������\n";
				std::cout << "2. ��������� ����� ����� �� �����\n";
				std::cout << "0. ������� � ��������� ����\n";
				std::cin >> add_choose;
				switch (add_choose)
				{
				case 1:
					int kol_song;
					std::cout << "������� ����� ������ ��������: \n";
					std::cin >> kol_song;
					dlya_zapisi.open("Catalog Song for record.txt");
					for (int i = 0; i < kol_song; i++)
					{
						cat_free.redact();
						vect_cat.push_back(cat_free);
					}
					for (int i = 0; i < vect_cat.size(); i++)
					{
						vect_cat.at(i).print();
					}
					dlya_zapisi.close();
					break;
				case 2:
					std::cout << " ��������� ����� �� �����: \n";
					dlya_chteniya.open("Catalog Song for record.txt");
					for (int i = 0; i < dlya_chteniya.eof(); i++)
					{
						vect_cat.push_back(cat_free);
						dlya_chteniya.ignore();
					}
					for (int i = 0; i < vect_cat.size(); i++)
					{
						vect_cat.at(i).print();
					}
					dlya_chteniya.close();
					break;
				case 0:
					//std::cout << "������� � ���������� ����.\n";
					break;

				default:
					std::cout << " �� ���������� ����, ��������� �����\n";
					break;
				}
			}
			
			break;
		case 2://������� ������ �����
			std::cout << "����� ����� ����� �������? \n ";
			
			std::cin >> num;
			dlya_zapisi.open("Catalog Song for record.txt",std::ios::trunc);
			vect_cat.erase(vect_cat.begin() + (num - 1));
			for (int i = 0; i < vect_cat.size(); i++)
			{
				vect_cat.at(i).print();
			}
			dlya_zapisi.close();
			
			break;
			
		case 3://��������� ������ �����
			std::cout << "����� ����� ����� ��������? \n ";
			break;
		case 4://����������� ������ ����� �� �����
			std::cout << "����� ����� ����� �������� �� ������? \n ";
			dlya_chteniya.open("Catalog pesen.txt");  //dlya_zapisi.open("Catalog Song for record.txt"); ��� ����
			if (dlya_chteniya.is_open())
			{
				std::cout << "File is iopen\n";
				while (!dlya_chteniya.eof())
				{
					save_str = "";
					std::getline(dlya_chteniya, save_str);
					std::cout << save_str << "\n";
				}
				dlya_chteniya.close();
				std::cout << "Fail is closeed\n";
			}
			else
				std::cout << "����� ������ ���\n";
			break;
		case 5://���������� ������ ����� � ����
			std::cout << "������� ����� ����� ������� ������ ��������� � ����: \n ";
			
			//����� ��� ��� ������ ����� ����, ��� �������� ����������

			break;
		case 6://����� � ����������� ���� ����� ������ ������
			std::cout << "������� ��� ������, �������� ������ �����: \n ";
			break;
		case 7://����� � ����������� ���� ����� ���������� ����� ��������� �������������
			std::cout << "������� ����� ������� ������ ����� � �����: \n ";
			dlya_chteniya.open("Catalog pesen.txt");//���� ��� ������
			std::cin >> odna_stroka;//���������� � ��� ������ �����
			dlya_chteniya.open(odna_stroka);
			if (dlya_chteniya.is_open())
			{
				std::cout << "� ����� ���� ��� �����\n";
			}
			else //                           
			{
				std::cout << "� ����� ��� ������ � ���� ������\n";
			}
			break;
		case 0://�����
			std::cout << "����� �� �������� �����\n ";
			break;
		default:
			std::cout << " �� ���������� ����, ��������� �����\n";
			break;
		}
	}
}


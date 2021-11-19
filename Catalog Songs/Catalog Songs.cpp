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
	std::string save_str = " для сохранения ";
	std::cout << "Добро пожаловать в каталог песен.\n" <<
		"Выберите пункт меню\n";
	while (choose!=0)
	{
		std::cout << "1. Добавить текст песни\n";
		std::cout << "2. Удалить текста песни\n";
		std::cout << "3. Изменение текста песни\n";
		std::cout << "4. Отображение текста песни на экран\n";
		std::cout << "5. Сохранение текста песни в файл\n";
		std::cout << "6. Поиск и отображение всех песен одного автора\n";
		std::cout << "7. Поиск и отображение всех песен содержащих слово указанное пользователем\n";
		std::cout << "0. Выход\n";
		std::cin >> choose;
		switch (choose)
		{
		case 1://Добавить текст песни
			std::cout << "Выберите пункт меню\n";
			while (add_choose!=0)
			{
				std::cout << "1. Написать текст песни самостоятельно\n";
				std::cout << "2. Загрузить текст песни из файла\n";
				std::cout << "0. Возврат в предыдщее меню\n";
				std::cin >> add_choose;
				switch (add_choose)
				{
				case 1:
					int kol_song;
					std::cout << "Сколько песен хотите добавить: \n";
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
					std::cout << " Загрузите песни из файла: \n";
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
					//std::cout << "Возврат в предыдущее меню.\n";
					break;

				default:
					std::cout << " Не правильный ввод, попробйте снова\n";
					break;
				}
			}
			
			break;
		case 2://Удалить текста песни
			std::cout << "Текст какой песни удалить? \n ";
			
			std::cin >> num;
			dlya_zapisi.open("Catalog Song for record.txt",std::ios::trunc);
			vect_cat.erase(vect_cat.begin() + (num - 1));
			for (int i = 0; i < vect_cat.size(); i++)
			{
				vect_cat.at(i).print();
			}
			dlya_zapisi.close();
			
			break;
			
		case 3://Изменение текста песни
			std::cout << "Текст какой песни изменить? \n ";
			break;
		case 4://Отображение текста песни на экран
			std::cout << "Текст какой песни показать на экране? \n ";
			dlya_chteniya.open("Catalog pesen.txt");  //dlya_zapisi.open("Catalog Song for record.txt"); или этот
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
				std::cout << "этого текста нет\n";
			break;
		case 5://Сохранение текста песни в файл
			std::cout << "Введите текст песни который хотите сохранить в файл: \n ";
			
			//думаю что это первый пункт меню, все делается аналогично

			break;
		case 6://Поиск и отображение всех песен одного автора
			std::cout << "Введите имя автора, которого хотите найти: \n ";
			break;
		case 7://Поиск и отображение всех песен содержащих слово указанное пользователем
			std::cout << "Введите слово которое хотите найти в песне: \n ";
			dlya_chteniya.open("Catalog pesen.txt");//файл для чтения
			std::cin >> odna_stroka;//записываем в эту строку текст
			dlya_chteniya.open(odna_stroka);
			if (dlya_chteniya.is_open())
			{
				std::cout << "в файле есть это слово\n";
			}
			else //                           
			{
				std::cout << "В файле нет текста с этим словом\n";
			}
			break;
		case 0://Выход
			std::cout << "Выход из каталога песен\n ";
			break;
		default:
			std::cout << " Не правильный ввод, попробйте снова\n";
			break;
		}
	}
}


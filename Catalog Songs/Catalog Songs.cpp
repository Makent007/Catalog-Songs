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
			int add_choose=10;
			while (add_choose!=0)
			{
				std::cout << "1. Написать текст песни самостоятельно\n";
				std::cout << "2. Загрузить текст песни из файла\n";
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
				std::cout << " Не правильный ввод, попробйте снова\n";
				break;
			}

			break;
		case 2://Удалить текста песни

			break;
		case 3://Изменение текста песни

			break;
		case 4://Отображение текста песни на экран

			break;
		case 5://Сохранение текста песни в файл

			break;
		case 6://Поиск и отображение всех песен одного автора

			break;
		case 7://Поиск и отображение всех песен содержащих слово указанное пользователем

			break;
		case 8://Выход

			break;
		default:
			std::cout << " Не правильный ввод, попробйте снова\n";
			break;
		}
	}
}
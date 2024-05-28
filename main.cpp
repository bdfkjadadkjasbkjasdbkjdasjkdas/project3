
// vector<Enemy> enemies = {{100, 0, " /\\_/\\ \n( о.о ) \n > * <"}, {120, 0, " /\\_/\\ \n( о.0 ) \n > _ <"}, {80, 0, " /\\_/\\ \n( 0.0 ) \n > @ <"}};

// cout << "\x1B[2J\x1B[H";
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

// Структура для питомца
struct Pet {
  string name;
  int level;
  int health;
  int xp;
  int happiness;
  int money = 0;
  int eat;
};

struct Enemy {
  int bossHealth;
  int boss2;
  string image;
};

struct item {
  string name;
  int quantity;
  int rarity;
};

void show(Enemy& bot) {
  cout << bot.image;
}


void animation() {
    string start;
    cout << "\033[34m";
    cout << "Введите слово СТАРТ для начала игры: " << endl;
    cin >> start;
  if (start == "СТАРТ") {
    cout << "\033[31m";
    cout << '-' << flush;
    for (;;) {
      sleep(1);
      cout << "\b\\" << flush;
      sleep(1);
      cout << "\b|" << flush;
      sleep(1);
      cout << "\b/" << flush;
      sleep(1);
      cout << "\b-" << flush << endl;
      break;
    }
  }
  else if (start != "СТАРТ") {
    cout << "Неверное слово!" << endl;
    animation();
  }
}


void searchEnemy() {
  string searchMessage = "Поиск врага...";
      string spinner = "|/-\\";
      cout << searchMessage << flush;
      for (int i = 0; i < 4; i++) {
        usleep(300000);
        cout << "\b\\" << flush;
        usleep(300000);;
        cout << "\b|" << flush;
        usleep(300000);
        cout << "\b/" << flush;
        usleep(300000);
        cout << "\b-" << flush << endl;
        break;
      }
  cout << endl;
}

void winEnemy() {
  string victoryMessage = "Победа!";
  string explosion = "* BOOM * * BOOM * * BOOM *";
  cout << victoryMessage << flush;
  for (int i = 0; i < 3; i++) {
      usleep(500000); 
      cout << "\b\b\b\b\b\b\b\b\b\b\b" << explosion << flush;
  }
  cout << endl;
}


void animationUpLevel() {
  string celebration = "* * *";
  for (int i = 0; i < 3; i++) {
      usleep(500000); 
      cout << "\b\b\b";
      for (char c : celebration) {
          cout << c << flush;
          usleep(200000); 
          cout << "\b \b" << flush;
      }
  }
  cout << "* Поздравления! *" << endl;
}
// Функция для отображения ASCII-арта питомца
void drawPet() {
  cout << " /\\_/\\ " << endl;
  cout << "( o.o )" << endl;
  cout << " > ^ < " << endl;
}

// Функция для отображения питомца
void displayPet(const Pet &pet) {
  cout << "\033[0;36m";
  cout << "\nИмя питомца: " << pet.name << endl;
  cout << "Уровень: " << pet.level << endl;
  cout << "Здоровье: " << pet.health << endl;
  cout << "Счастье: " << pet.happiness << endl;
  cout << "Еда: " << pet.eat << endl;
  drawPet(); // Отрисовка питомца
}

// Функция для отображения меню
void displayMenu() {
  cout << "\033[0;32m";
  cout << "1. Играть с питомцем" << endl;
  cout << "2. Отправиться в путешествие" << endl;
  cout << "3. Купить перки" << endl;
  cout << "4. Бой с боссом(средний уровень)" << endl;
  cout << "5. Бой с боссом(сложный уровень)" << endl;
  cout << "6. Бой с боссом(легкий уровень)" << endl;
  cout << "7. Зайти в пекарню" << endl;
  cout << "8. Зайти в инвентарь" << endl;
  cout << "9. Использовать что то" << endl;
  cout << "10. Зайти в магазин" << endl;
  cout << "11. Скрафтить предмет" << endl;
  cout << "12. Выйти из программы" << endl;
  cout << "Редкости предметов: " << endl;
  cout << "1. Зелье здоровья - ";
  cout << "\033[0;33m" << "легендарный предмет";
  cout << "\033[0;32m" << "(дает 20 здоровья и стоит дешево)" << endl;
  cout << "2. Зелье счастья - ";
  cout << "\033[0;34m" << "сверхредкий предмет";
  cout << "\033[0;32m" << "(дает 20 счастья)" << endl;
  cout << "3. Печенье - их дается 4 в начале игры, поэтому они ";
  cout << "\033[0;35m" << "эпические" << endl;
  cout << "\033[0;32m";
}

void logo() {
  cout << "\033[35m";
  cout << "\033[40m";
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠒⠈⠉⠁⠂⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡗⣅⡢⠀⣂⠠⡄⣏⣀⣀⡀⠀⠀⠀⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠔⠊⡧⢼⣀⠭⠯⢄⠀⡿⠀⠀⠈⠉⠒⢤⡀⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⡿⣒⣒⣊⡩⡆⡿⠀⠀⠀⠀⠀⠀⠀⢱⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢃⢀⠀⠀⢻⠡⠖⠂⢚⠁⡇⠀⠀⠀⠀⢀⠔⠀⢸⡀⠀" << endl;
  cout << "⠀⢀⣀⠀⠀⠀⠀⠀⣰⡉⠀⢢⡀⠀⠁⠐⠊⠁⠀⠀⠀⠀⠀⡔⠁⠀⠀⠀⠱⡀" << endl;
  cout << "⠹⡀⠀⠉⠒⠤⣀⣸⡯⢎⢕⢄⡝⢲⡂⠤⠬⡄⠀⠀⠤⠤⡞⠘⡤⢤⠄⢐⢆⢣" << endl;
  cout << "⠀⠈⠒⠤⣀⠀⢀⢽⠉⢰⠩⡊⠀⢸⠀⢋⠉⠀⠡⢲⢒⠈⡀⠀⢻⠵⠧⠄⠛⢃" << endl;
  cout << "⠀⠀⠀⠀⠀⠉⠮⡃⢁⢞⢿⠀⠀⣮⠑⠠⠯⡄⡰⠁⠤⠔⡇⢰⠁⠀⠀⠀⠀⡸" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠉⠂⠤⣀⡈⢀⣀⠴⢊⠇⠀⠓⠃⡇⢀⠗⠁" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠆⢒⢂⠊⠀⣘⠃⢀⠜⢠⢄⠀⠀⠑⠁⠀⠀" << endl;
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⣉⣐⣄⡼⠀⠀⠙⠓⠰⠶⠂⠚⠀⠀" << endl;
  cout << "\033[47m";
}

void addItem(vector<item> &inventory, string itemname, int quantity, int rarity) {
  for (auto& item : inventory) {
    if (item.name == itemname) {
      item.quantity += quantity;
      return;
    }
  }
  inventory.push_back({itemname, quantity, rarity});
}


void shop(vector<item>& inventory, int itemnumber, Pet& myPet) {
  int vibor55;
  cout << "Ваши деньги: " << myPet.money << endl;
  cout << "Предметы для покупки в инвентарь:" << endl;
  cout << "1. " << "\033[0;33m" << "Зелье здоровья (цена: 10 монет)" << "\033[0;32m" << endl;
  cout << "2. " << "\033[0;34m" << "Зелье счастья (цена: 15 монет)" << "\033[0;32m" << endl;
  cout << "3. " << "\033[0;35m" << "Печенье (цена: 5 монет)" << "\033[0;32m" << endl;
  cin >> vibor55;
  if (vibor55 == 1 && myPet.money >= 10) {
    cout << "Вы купили " << "\033[0;33m" << "зелье здоровья" << "\033[0;32m" << endl;
    myPet.money -= 10;
    addItem(inventory, "Зелье здоровья", 1, 3);
  }
  else if (vibor55 == 2 && myPet.money >= 15) {
    cout << "Вы купили " << "\033[0;34m" <<  "зелье счастья"  << "\033[0;32m"  << endl;
    myPet.money -= 15;
    addItem(inventory, "Зелье счастья", 1, 2);
  }
  else if (vibor55 == 3 && myPet.money >= 5) {
    cout << "Вы купили " << "\033[0;35m" << "печенье" << "\033[0;32m" << endl;
    myPet.money -= 5;
    addItem(inventory, "Печенье", 1, 2);
  }
  else {
    cout << "Неверный ввод или недостаточно монет" << endl;
  }
}

// теперь выводится номер
void printInventory(vector<item>& inventory) {
    cout << "\nИнвентарь:" << endl;
    for (int i = 0; i < inventory.size(); ++i) {
        cout << "#" << i + 1 << " " << inventory[i].name << " — " << inventory[i].quantity << " - редкость - " << inventory[i].rarity << endl;
    }
    cout << endl;
}


// теперь предмет удаляется из вектора если его количество равно нулю
bool useItemByNumber(vector<item>& inventory, int itemnumber, Pet& myPet) {
    if (itemnumber >= 0 && itemnumber < inventory.size()) {
        item& item = inventory[itemnumber];
        if (item.quantity > 0) {
            item.quantity--;
            if (item.name == "Зелье здоровья") {
                myPet.health += 20 * item.rarity;
            }
          else if (item.name == "Зелье счастья") {
                myPet.happiness += 20 * item.rarity;
          }
          else if (item.name == "Печенье") {
                myPet.health += 10 * item.rarity;
          }
          else if (item.name == "Кекс") {
                myPet.happiness += 10 * item.rarity;
                myPet.health += 10 * item.rarity;
          }
          else if (item.name == "Суперзелье") {
                myPet.health += 20 * item.rarity;
          }
          else if (item.name == "Крекер") {
                myPet.eat += 20 * item.rarity;  
                myPet.health += 10 * item.rarity;
          }
          else if (item.name == "Мегазелье") {
                myPet.eat += 10 * item.rarity;  
                myPet.health += 10 * item.rarity;
                myPet.level += 0.5 * item.rarity;
                myPet.happiness += 10 * item.rarity;
          }
          else if (item.name == "Мегакекс") {
                myPet.eat += 10 * item.rarity;
                myPet.health += 10 * item.rarity;
                myPet.level += 1 * item.rarity;
                myPet.happiness += 10 * item.rarity; 
          }

            if (item.quantity == 0) {
                inventory.erase(inventory.begin() + itemnumber);
            }
            return true;
        }
    }
    return false;
}

int xpToNextlevel(int currentLevel) {
  return 10 * (currentLevel + 1) * (currentLevel + 1);
}

int play(Pet &myPet) {
  int xpGain = 20;
  myPet.xp += xpGain;
  return myPet.xp;
}

Pet journey(Pet &myPet) {
  int xpGain = 5;
  int xpGain2 = 10;
  string country;
  string arr[] = {"Турция",   "Германия", "Франция", "Италия",  "Норвегия",
                  "Швеция",   "Чехия",    "Бельгия", "Эстония", "Финляндия",
                  "Болгария", "Россия",   "Япония",  "Испания"};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  srand(static_cast<unsigned int>(time(0)));
  int randomNumberIndex = rand() % arraySize;
  string randomIndex = arr[randomNumberIndex];
  cout << "Питомец очень любит путешествия, поэтому он отправился в "
          "путешествие, особенно он любит страну: "
       << randomIndex << endl;
  cout << "Выберите страну, в которую путешествовать: ";
  cin >> country;
  if (country == randomIndex) {
    cout << "Вы выбрали любимую страну тамагочи, он очень рад, что вы ее "
            "посетили!"
         << endl;
    myPet.health += 10;
    myPet.happiness += 10;
    myPet.xp += xpGain2;
  } else {
    cout << "Тамагочи рад, что отправился в путешествие, но он не очень рад, "
            "что вы ему не послушали("
         << endl;
    myPet.health += 5;
    myPet.happiness += 5;
    myPet.xp += xpGain;
  }
  return myPet;
}

void boss(Pet &myPet, vector<item>& inventory, Enemy &bot) {
  searchEnemy();
  bot.image = " /\\_/\\ \n( о.о ) \n > * <";
  int hit;
  bot.bossHealth = 100;
  cout << "бой с босом (средний уровень)" << endl;
  while (bot.bossHealth > 0) {
    srand(static_cast<unsigned int>(time(0)));
    int myhealth = rand() % 11;
    int randMin = 1;
    int randMax = 10;
    bot.boss2 = rand() % (randMax - randMin + 1) + randMin;
    cout << "1. Удар рукой" << endl << "2. Удар ногой" << endl << "3. Войти в инвентарь";
    cin >> hit;
    if (hit == 1) {
      cout << "Вы ударили босса рукой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - bot.boss2;
      myPet.health = myPet.health - myhealth;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
    } else if (hit == 2) {
      cout << "Вы ударили босса ногой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - bot.boss2;
      myPet.health = myPet.health - myhealth;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
    }  else if (hit == 3) {
      cout << "Вы вошли в инвентарь" << endl;
      printInventory(inventory);
      int itemnumber4;
      cout << "Введите номер предмета для использования: ";
      cin >> itemnumber4;
      if (useItemByNumber(inventory, itemnumber4 - 1, myPet)) {
        cout << "Предмет был использован." << endl;
      }
      else {
        cout << "Неверный номер предмета или предмет не найден." << endl;
      }
    }
    else if (hit >= 4) {
      cout << "Неверный ввод" << endl;
    }
    cout << "Ваше здоровье: " << myPet.health << endl;
    if (myPet.health <= 0) {
      cout << "Вы проиграли, питомец умер" << endl;
      break;
    }
    if (bot.bossHealth <= 0) {
      cout << endl << "Вы победили босса!" << endl;
      myPet.money += 20;
      myPet.xp += 20;
      winEnemy();
    }
  }
}

void boss2(Pet &myPet, vector<item>& inventory, Enemy &bot) {
  searchEnemy();
  int hit2;
  bot.image = " /\\_/\\ \n( о.0 ) \n > _ <";
  bot.bossHealth = 120;
  cout << "бой с босом (сложный уровень)" << endl;
  while (bot.bossHealth > 0) {
    srand(static_cast<unsigned int>(time(0)));
    int myhealth2 = rand() % 9;
    int randMin2 = 1;
    int randMax2 = 12;
    bot.boss2 = rand() % (randMax2 - randMin2 + 1) + randMin2;
    cout << "1. Удар рукой" << endl << "2. Удар ногой" << endl << "3. Войти в инвентарь" << endl;;
    cin >> hit2;
    if (hit2 == 1) {
      cout << "Вы ударили босса рукой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - bot.boss2;
      myPet.health = myPet.health - myhealth2;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
    } else if (hit2 == 2) {
      cout << "Вы ударили босса ногой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - myhealth2;
      myPet.health = myPet.health - bot.boss2;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
    }  else if (hit2 == 3) {
      cout << "Вы вошли в инвентарь" << endl;
      printInventory(inventory); 
      int itemnumber3;
      cout << "Введите номер предмета для использования: ";
      cin >> itemnumber3;
      if (useItemByNumber(inventory, itemnumber3 - 1, myPet)) {
        cout << "Предмет был использован." << endl;
      }
      else {
        cout << "Неверный номер предмета или предмет не найден." << endl;
      }
    }
    else if (hit2 >= 4) {
      cout << "Неверный ввод" << endl;
    }
    cout << "Ваше здоровье: " << myPet.health << endl;
    if (myPet.health <= 0) {
      cout << "Вы проиграли, питомец умер" << endl;
      break;
    }
    if (bot.bossHealth <= 0) {
      cout << endl << "Вы победили босса!" << endl;
      myPet.money += 50;
      myPet.xp += 50;
      winEnemy();
    }
  }
}

void boss3(Pet &myPet,  vector<item>& inventory, Enemy &bot) {
  searchEnemy();
  int hit3;
  bot.image = " /\\_/\\ \n( 0.0 ) \n > @ <";
  bot.bossHealth = 80;
  cout << "бой с босом (легкий уровень)" << endl;
  while (bot.bossHealth > 0) {
    srand(static_cast<unsigned int>(time(0)));
    int myhealth3 = rand() % 13;
    int randMin3 = 1;
    int randMax3 = 8;
    bot.boss2 = rand() % (randMax3 - randMin3 + 1) + randMin3;
    cout << "1. Удар рукой" << endl << "2. Удар ногой" << endl << "3. Войти в инвентарь" << endl;
    cin >> hit3;
    if (hit3 == 1) {
      cout << "Вы ударили босса рукой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - bot.boss2;
      myPet.health = myPet.health - myhealth3;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
    } else if (hit3 == 2) {
      cout << "Вы ударили босса ногой" << endl;
      cout << bot.image << endl;
      bot.bossHealth = bot.bossHealth - myhealth3;
      myPet.health = myPet.health - bot.boss2;
      cout << "У босса осталось " << bot.bossHealth << " здоровья" << endl;
      } else if (hit3 == 3) {
      cout << "Вы вошли в инвентарь" << endl;
      printInventory(inventory); 
      int itemnumber3;
      cout << "Введите номер предмета для использования: ";
      cin >> itemnumber3;
      if (useItemByNumber(inventory, itemnumber3 - 1, myPet)) {
        cout << "Предмет был использован." << endl;
      }
      else {
        cout << "Неверный номер предмета или предмет не найден." << endl;
      }
    }
    else if (hit3 >= 4) {
      cout << "Неверный ввод" << endl;
    }
    cout << "Ваше здоровье: " << myPet.health << endl;
    if (myPet.health <= 0) {
      cout << "Вы проиграли, питомец умер" << endl;
      break;
    }
    if (bot.bossHealth <= 0) {
      cout << endl << "Вы победили босса!" << endl;
      myPet.money += 10;
      myPet.xp += 10;
      winEnemy();
    }
  }
}

void perk(Pet &myPet) {
  int number;
  cout << "Ваши монеты: " << myPet.money << endl;
  cout << "Перки: " << endl
       << "1. Увеличение здоровья (+50) (стоимость 20)" << endl
       << "2. Увеличение счастья (+20) (стоимость 20)" << endl
       << "3. Увеличение уровня (+1) (стоимость 10)" << endl;
  cin >> number;
  if (number == 1 && myPet.money >= 20) {
    myPet.money -= 20;
    cout << "было " << myPet.health << " здоровья" << endl;
    myPet.health += 50;
    cout << "стало " << myPet.health << " здоровья" << endl;
  } else if (number == 2 && myPet.money >= 20) {
    myPet.money -= 20;
    cout << "было " << myPet.happiness << " счастья" << endl;
    myPet.happiness += 20;
    cout << "стало " << myPet.happiness << " счастья" << endl;
  } else if (number == 3 && myPet.money >= 10) {
    myPet.money -= 10;
    cout << "был " << myPet.level << " уровень" << endl;
    myPet.level += 1;
    cout << "стал " << myPet.level << " уровень" << endl;
  } else {
    cout << "Неверный ввод или недостаточно монет" << endl;
  }
}

void pekarnia(Pet& myPet) {
  int vibor;
  cout << "У вас " << myPet.money << " монет" << endl;
  cout << "Что вы хотите сделать? 1. Купить шоколадку (цена 5 за 10 еды), 2. "
          "Купить сладости (цена 8 за 20 еды)."<< endl;
  cin >> vibor;
  if (vibor == 1 && myPet.money >= 5) {
    cout << "Еды было: " << myPet.eat;
    cout << "Вы купили шоколад" << endl;
    cout << "Еды стало: " << myPet.eat + 10;
    myPet.money -= 5;
  } else if (vibor == 2 && myPet.money >= 8) {
    cout << "Вы купили сладости" << endl;
    myPet.money -= 8;
    cout << "Еды было: " << myPet.eat << endl;
    cout << "Вы использовали сладости." << endl;
    cout << "Еды стало: " << myPet.eat + 20 << endl;
  } else {
    cout << "недостаточно денег или неверный ввод" << endl;
  }
}


bool itemExists(vector<item>& inventory, string itemName) {
  for (int i = 0; i < inventory.size(); i++) {
    if (inventory[i].name == itemName) {
      return true;
    }
  }
  return false;
}

bool multipleExists(vector<item>& inventory) {
    for (auto& item : inventory) {
        if (item.name == "Печенье" && item.quantity >= 2) {
            return true;
        }
    }
    return false;
}

void deleteItem(vector<item>& inventory, string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].name == itemName) {
          inventory[i].quantity--;
        }
      if (inventory[i].quantity == 0) {
        cout << "Предмет " << itemName << " был удален из инвентаря." << endl;
        inventory.erase(inventory.begin() + i);
      }
    }
}

void craftItems(vector<item>& inventory) {
  int vibor2222;
  int vibor123123;
  int vibor555555;
  int zelye;
  int choice12;
  if (itemExists(inventory, "Печенье") && itemExists(inventory, "Зелье счастья")) {
    cout << "Вы можете скрафтить кекс" << endl;
    cout << "Вы хотите скрафтить кекс? (1 печенье и 1 зелье счастья)" << endl;
    cout << "1. Да" << endl << "2. Нет" << endl;
    cin >> vibor2222;
    if (vibor2222 == 1) {
      cout << "Вы скрафтили кекс" << endl;
      deleteItem(inventory, "Печенье");
      deleteItem(inventory, "Зелье счастья");
      addItem(inventory, "Кекс", 1, 5);
    }
  }
  if (itemExists(inventory, "Печенье") && itemExists(inventory, "Зелье здоровья")) {
    cout << "Вы можете скрафтить суперзелье" << endl;
    cout << "Вы хотите скрафтить суперзелье? (1 печенье и 1 зелье здоровья)" << endl;
    cout << "1. Да" << endl << "2. Нет" << endl;
    cin >> vibor123123;
    if (vibor123123 == 1) {
      cout << "Вы скрафтили суперзелье" << endl;
      deleteItem(inventory, "Печенье");
      deleteItem(inventory, "Зелье здоровья");
      addItem(inventory, "Суперзелье", 1, 5);
    }
  }
  if (multipleExists(inventory)) {
      cout << "Вы можете скрафтить крекер" << endl;
      cout << "Вы хотите скрафтить крекер? (2 печенья)" << endl;
      cout << "1. Да" << endl << "2. Нет" << endl;
      cin >> vibor555555;
      if (vibor555555 == 1) {
        cout << "Вы скрафтили крекер" << endl;
        deleteItem(inventory, "Печенье");
        deleteItem(inventory, "Печенье");
        addItem(inventory, "Крекер", 1, 5);
      }
  if (multipleExists(inventory) && itemExists(inventory, "Зелье здоровья") && itemExists(inventory, "Зелье счастья")) {
      cout << "Вы можете скрафтить мегазелье" << endl;
      cout << "Вы хотите скрафтить мегазелье? (2 печенья, 1 зелье здоровья, 1 зелье счастья)" << endl;
      cout << "1. Да" << endl << "2. Нет" << endl;
      cin >> zelye;
      if (zelye == 1) {
        cout << "Вы скрафтили мегазелье" << endl;
        deleteItem(inventory, "Печенье");
        deleteItem(inventory, "Печенье");
        deleteItem(inventory, "Зелье здоровья");
        deleteItem(inventory, "Зелье счастья");
        addItem(inventory, "Мегазелье", 1, 10);
      }
  }
  if (itemExists(inventory, "Кекс") && itemExists(inventory, "Крекер")) {
      cout << "Вы можете скрафтить мегакекс" << endl;
      cout << "Вы хотите скрафтить мегакекс? (1 кекс и 1 крекер)" << endl;
      cout << "1. Да" << endl << "2. Нет" << endl;
      cin >> choice12;
      if (choice12 == 1) {
        cout << "Вы скрафтили мегакекс" << endl;
        deleteItem(inventory, "Кекс");
        deleteItem(inventory, "Крекер");
        addItem(inventory, "Мегакекс", 1, 8);
      }
  }
    else {
      if (!multipleExists(inventory)) {
        cout << "для крафта мегазелья не хватает печенья" << endl;
      }
      if (!itemExists(inventory, "Зелье здоровья")) {
        cout << "для крафта мегазелья не хватает зелья здоровья" << endl;
      }
      if (!itemExists(inventory, "Зелье счастья")) {
        cout << "для крафта мегазелья не хватает зелья счастья" << endl;
      }
    }
  }
    else {
      cout << "Вы не можете ничего скрафтить :(" << endl;
    }
  }

  //for (int i = 0; i < inventory.size(); i++) {
    //  if (inventory[i].name == "Печенье") {
      //  cout << "Это печенье" << endl;
      //}
    //}
 // inventory.push_back({itemname, quantity, rarity});

int main() {
  Pet myPet;
  Enemy bot;
  myPet.level = 1;
  myPet.xp = 0;
  myPet.health = 105;
  myPet.happiness = 105;
  myPet.eat = 102;

  vector<item> inventory;

  addItem(inventory, "Печенье", 4, 2);

  logo();
  animation();
  cout << "\033[0;35m";
  cout << "Введите имя вашего питомца: ";
  getline(cin, myPet.name);

  bool isRunning = true;
  while (isRunning) {
    myPet.happiness -= 5;
    myPet.health -= 5;
    myPet.eat -= 2;
    if (myPet.happiness < 1 || myPet.health < 1) {
      cout << "Питомец умер :(, это конец :(" << endl;
      break;
    }
    if (myPet.eat < 1) {
      myPet.health -= 5;
    }

    displayPet(myPet);
    displayMenu();

    int choice;
    cout << "Выберите действие: ";
    cin >> choice;

    switch (choice) {
    case 1:
      myPet.xp = play(myPet);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }

      break;
    case 2:
      journey(myPet);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 3:
      perk(myPet);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 4:
      boss(myPet, inventory, bot);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 5:
      boss2(myPet, inventory, bot);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 6:
      boss3(myPet, inventory, bot);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 7:
      pekarnia(myPet);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 8:
      printInventory(inventory);
      cout << "текущий уровень xp: " << myPet.xp;
      cout << " До следующего уровня: " << xpToNextlevel(myPet.level)
           << " xp\n";

      if (myPet.xp >= xpToNextlevel(myPet.level)) {
        myPet.level++;
        myPet.health += 10;
        myPet.happiness += 10;
        myPet.eat += 5;
        animationUpLevel();
        cout << "Уровень повышен до " << myPet.level;
      }
      break;
    case 9:
    int itemnumber;
      printInventory(inventory);
      cout << "Введите номер предмета для использования: ";
      cin >> itemnumber;
      if (useItemByNumber(inventory, itemnumber - 1, myPet)) {
        cout << "Предмет был использован." << endl;
      }
      else {
        cout << "Неверный номер предмета или предмет не найден." << endl;
      }
      break;
    case 10:
    shop(inventory, itemnumber, myPet);
      break;
    case 11:
    craftItems(inventory);
      break;
    case 12:
      isRunning = false;
      break;
    default:
      cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
    }
  }

  return 0;
}

















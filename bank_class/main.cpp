#include <iostream>


class BankSystem
{
  public:
    int balance = 0;

  void deposit_money(int money_to_deposit)
  {
    if (money_to_deposit >= 50000 || money_to_deposit <= 0)
    {
      std::cout << "ban value for deposit!!!\n";
    }
    else
    {
      balance += money_to_deposit;
    }
  }

  void withdrow_money(int money_to_withdrow)
  {
    if (balance >= money_to_withdrow)
    {
      balance -= money_to_withdrow;
    }
    else
    {
      std::cout << "no withdrow for you!!!\n";
    }
  }

  void show_info()
  {
    std::cout << "your balance is " << balance << '\n';
  }
};


int main()
{
  BankSystem system;
  int x = 0;
  bool tmp = true;
  std::string menu[3] = {"1. deposit money for your test account",
                         "2. withdrow money from your test account",
                         "3. quit your test bank account"};
  while (tmp)
  {
    for (int i = 0; i < 3; i++)
    {
      std::cout << menu[i] << std::endl;
    }
    std::cin >> x;
    std::system("clear");
    switch(x)
    {
      case 1:
        std::cout << "type how much you want to deposit\n";
        std::cin >> x;
        system.deposit_money(x);
        system.show_info();
        break;
      case 2:
        std::cout << "type how much you want to withdrow\n";
        std::cin >> x;
        system.withdrow_money(x);
        system.show_info();
        break;
      case 3:
        std::cout << "Good bye!";
        tmp = false;
        break;
      default:
        std::cout << " bad value... try again!";
        std::cin.clear();
        break;
    }
  }
  return 0;
}

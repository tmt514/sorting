#pragma execution_character_set("utf-8")

#include <bits/stdc++.h>
using namespace std;

enum Item {
  珍珠奶茶,
  鐵觀音紅茶,
};

enum Suger {
  全糖,
  半糖,
  微糖,
  無糖,
};

enum Ice {
  正常冰,
  少冰,
  微冰,
  去冰,
};

enum Topping {
  珍珠,
  布丁,
  椰果,
};

class BubbleTea {
 public:
  Item 品項;
  Suger 糖量;
  Ice 冰量;
  void ShowInfo() { cout << "這是一杯不健康的飲料。" << endl; }
};

class Tea : public BubbleTea {};

class Coffee : public BubbleTea {};

class BubbleTeaFactory {
 public:
  BubbleTea* GetBubbleTea(Item item, Suger suger, Ice ice) {
    auto tea = new BubbleTea();
  }
};

int main() {
  BubbleTeaFactory factory;
  BubbleTea* bubble_tea = factory.GetBubbleTea(珍珠奶茶, 半糖, 少冰);
  bubble_tea->ShowInfo();
  return 0;
}

// Copyright 2023 AMSL

#include <iostream>
#include <string>

// std::shared_ptrを利用するのに必要
#include <memory>

// 説明用のクラス。生成/破棄時にメッセージを出力する
class Hoge
{
public:
  Hoge(const std::string &name)
      : name_(name)
  {
    std::cout << "Create " << name_ << std::endl;
  }
  ~Hoge()
  {
    std::cout << "Destroy " << name_ << std::endl;
  }

private:
  std::string name_;
};

int main(int argc, char **argv)
{
  {
    {
      // 1. 普通のポインタ(メモリリーク)
      Hoge *hoge = new Hoge("Object 1");
    }
    std::cout << "hogeの寿命が尽きたがObject 1が破棄されていない->メモリリーク" << std::endl;

    {
      // 2. 普通のポインタ(detete)
      Hoge *hoge = new Hoge("Object 2");
      delete hoge;
    }
    std::cout << "Object 2はdeleteにより破棄された" << std::endl;

    {
      // 3. std::shared_ptr
      std::shared_ptr<Hoge> hoge = std::make_shared<Hoge>("Object 3");
    }
    std::cout << "hogeの寿命が尽きるとObject 3は自動的に破棄される" << std::endl;

    {
      // 4. std::shared_ptr(複数)
      std::shared_ptr<Hoge> hoge1 = std::make_shared<Hoge>("Object 4");
      {
        // hoge2はhoge1と同じオブジェクトを指す
        std::shared_ptr<Hoge> hoge2 = hoge1;
      }
      std::cout << "hoge2の寿命が尽きてもObject 4は破棄されない" << std::endl;
    }
    std::cout << "hoge1の寿命が尽きるとObject 4は自動的に破棄される" << std::endl;

    {
      // 5. std::shared_ptr(複数その2)
      // hoge1は初めオブジェクトを指さない
      std::shared_ptr<Hoge> hoge1 = nullptr;
      {
        // hoge2が指すオブジェクトを生成
        std::shared_ptr<Hoge> hoge2 = std::make_shared<Hoge>("Object 5");
        // hoge1はhoge2と同じオブジェクトを指す
        hoge1 = hoge2;
      }
      std::cout << "hoge2の寿命が尽きてもObject 5は破棄されない" << std::endl;
    }
    std::cout << "hoge1の寿命が尽きるとObject 5は自動的に破棄される" << std::endl;

    {
      // 6. std::shared_ptr(use_count()について)
      std::shared_ptr<Hoge> hoge1 = std::make_shared<Hoge>("Object 6");
      // 同じオブジェクトを指すポインタの数はuse_count()で取得できる
      // hoge1のみなので1
      std::cout << "use_count: " << hoge1.use_count() << std::endl;
      {
        std::shared_ptr<Hoge> hoge2 = hoge1;
        // hoge1とhoge2なので2
        std::cout << "use_count: " << hoge2.use_count() << std::endl;
      }
      // hoge2が寿命を迎えてhoge1のみなので1
      std::cout << "use_count: " << hoge1.use_count() << std::endl;
    }
    std::cout << "カウントが0になるとObject 6は自動的に破棄される" << std::endl;

  }
  return 0;
}

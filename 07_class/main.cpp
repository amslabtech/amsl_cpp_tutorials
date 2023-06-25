// Copyright 2023 AMSL

#include <iostream>
#include <memory>
#include <string>

class Base
{
public:
  // コンストラクタ
  explicit Base(const std::string &name)
      : name_(name) // メンバ初期化子リスト
  {
    std::cout << "Create " << name_ << std::endl;
  }

  // デストラクタ
  ~Base()
  {
    std::cout << "Destroy " << name_ << std::endl;
  }

  // メンバ関数
  void saySomething()
  {
    std::cout << "Hello. I'm " << name_ << " !" << std::endl;
  }

  // 仮想関数
  virtual void sayNumber()
  {
    std::cout << 1 << std::endl;
  }

private:
  // メンバ変数
  std::string name_;
};

// Baseをpublic継承したDerivedクラス
class Derived : public Base
{
public:
  Derived(const std::string &name)
      : Base(name)
  {
    std::cout << "Create Derived class " << name << std::endl;
  }

  ~Derived()
  {
    std::cout << "Destroy Derived class" << std::endl;
  }

  // メンバ関数
  // 関数のオーバーライド
  void saySomething()
  {
    // 基底クラスのprivateなメンバにはアクセスできない
    // std::cout << "Hello. I'm " << name_ << " !" << std::endl;
    std::cout << "Hello from Derived class!" << std::endl;
  }

  // 明示的なオーバーライド
  void sayNumber() override
  {
    std::cout << 2 << std::endl;
  }
};

int main(int argc, char **argv)
{
  {
    // Baseクラスのインスタンスを生成
    // インスタンス化
    Base obj("obj0");
    obj.saySomething();
    // privateなメンバ変数には外部からアクセスできない
    // std::cout << obj.name_ << std::endl;
  }
  {
    // Derivedクラスのインスタンスを生成
    Derived obj("obj1");
    obj.saySomething();
  }
  {
    // Baseクラスのポインタ
    std::unique_ptr<Base> obj = std::make_unique<Base>("obj2");
    obj->saySomething();
    obj->sayNumber();
  }
  {
    // Derivedクラスのポインタ
    std::unique_ptr<Derived> obj = std::make_unique<Derived>("obj3");
    obj->saySomething();
    obj->sayNumber();
  }
  {
    // BaseクラスのポインタでDerivedクラスのインスタンスを指す
    std::unique_ptr<Base> obj = std::make_unique<Derived>("obj4");
    // BaseクラスのsaySomething()が呼ばれる
    obj->saySomething();
    // 仮想関数についてはDerivedクラスのものが呼ばれる
    obj->sayNumber();
  }
  return 0;
}

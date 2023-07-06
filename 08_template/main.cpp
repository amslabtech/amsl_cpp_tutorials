// Copyright 2023 AMSL

#include <iostream>

class Point
{
public:
  Point(double x, double y, double z)
      : x_(x), y_(y), z_(z)
  {
  }

  double getX() const
  {
    return x_;
  }

  double getY() const
  {
    return y_;
  }

  double getZ() const
  {
    return z_;
  }

private:
  double x_;
  double y_;
  double z_;
};

// Pointと継承関係は無いが、同じインターフェースを持つ
class Position
{
public:
  Position(double x, double y, double z)
      : x_(x), y_(y), z_(z)
  {
  }

  double getX() const
  {
    return x_;
  }

  double getY() const
  {
    return y_;
  }

  double getZ() const
  {
    return z_;
  }

private:
  double x_;
  double y_;
  double z_;
};

// 説明用クラス
// getZを持たない
class Point2D
{
public:
  Point2D(double x, double y)
      : x_(x), y_(y)
  {
  }

  double getX() const
  {
    return x_;
  }

  double getY() const
  {
    return y_;
  }

private:
  double x_;
  double y_;
};

// 関数テンプレート
// getX, getY, getZを持つT型のオブジェクトを受け付ける
template <typename T>
void printXYZ(const T &data)
{
  std::cout << data.getX() << ", " << data.getY() << ", " << data.getZ() << std::endl;
}

// クラステンプレート
template <typename T>
class XYZPrinter
{
public:
  XYZPrinter(const T &data)
      : data_(data)
  {
  }

  void printXYZ() const
  {
    std::cout << data_.getX() << ", " << data_.getY() << ", " << data_.getZ() << std::endl;
  }

private:
  T data_;
};

int main(int argc, char **argv)
{
  printXYZ<Point>(Point(1, 2, 3));
  printXYZ<Position>(Position(4, 5, 6));
  // Point2DはgetZを持たないのでコンパイルエラー
  // printXYZ<Point2D>(Point2D(7, 8));

  XYZPrinter<Point>(Point(1, 2, 3)).printXYZ();
  XYZPrinter<Position>(Position(4, 5, 6)).printXYZ();
  // Point2DはgetZを持たないのでコンパイルエラー
  // XYZPrinter<Point2D>(Point2D(7, 8)).printXYZ();
  return 0;
}

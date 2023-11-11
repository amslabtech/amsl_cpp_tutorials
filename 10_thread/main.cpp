// Copyright 2023 AMSL

#include <iostream>
#include <thread>
#include <mutex>

int main(int argc, char **argv)
{
  {
    // Lambdaとして渡した関数を実行するスレッド
    // 定義した時点で勝手に実行されるので、Thread1とMain thread1のどちらが先に表示されるかは不定
    std::thread th([]() {
      std::cout << "Thread1" << std::endl;
      std::chrono::milliseconds sleep_duration(1000);
      // 1000ms待つ
      std::this_thread::sleep_for(sleep_duration);
      std::cout << "Thread2" << std::endl;
    });
    std::cout << "Main thread1" << std::endl;
    // 500ms待つ
    std::chrono::milliseconds sleep_duration(500);
    std::this_thread::sleep_for(sleep_duration);
    std::cout << "Main thread2" << std::endl;
    // thの終了待ち
    th.join();
    std::cout << "Main thread3" << std::endl;
  }
  {
    std::mutex mtx;
    std::thread th([&]() {
      std::cout << "Thread1" << std::endl;
      std::chrono::milliseconds sleep_duration(1000);
      {
        // ロックを取得する
        // 変数lockの寿命の間、他のスレッドはロックを取得できない
        std::lock_guard<std::mutex> lock(mtx);
        std::this_thread::sleep_for(sleep_duration);
        std::cout << "Thread2" << std::endl;
      }
    });
    std::cout << "Main thread1" << std::endl;
    std::chrono::milliseconds sleep_duration(500);
    std::this_thread::sleep_for(sleep_duration);
    {
      // 上の例と異なり、Main thread2はThread2の後に表示される
      std::lock_guard<std::mutex> lock(mtx);
      std::cout << "Main thread2" << std::endl;
    }
    th.join();
    std::cout << "Main thread3" << std::endl;
  }
  return 0;
}

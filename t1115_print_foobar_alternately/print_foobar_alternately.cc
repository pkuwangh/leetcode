/**
 * Suppose you are given the following code:
 * class FooBar {
 *   public void foo() {
 *     for (int i = 0; i < n; i++) {
 *       print("foo");
 *     }
 *   }
 * 
 *   public void bar() {
 *     for (int i = 0; i < n; i++) {
 *       print("bar");
 *     }
 *   }
 * }
 * The same instance of FooBar will be passed to two different threads.
 * Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.
 * Example 1:
 * Input: n = 1
 * Output: "foobar"
 * Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
 * Example 2:
 * Input: n = 2
 * Output: "foobarfoobar"
 * Explanation: "foobar" is being output 2 times.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
  private:
    int n;
    bool started;
    std::mutex mu;
    std::condition_variable cond;

  public:
    FooBar(int n) {
        this->n = n;
        started = false;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> locker(mu, std::defer_lock);
        for (int i = 0; i < n; i++) {
            locker.lock();
            cond.wait(locker, [this]()->bool { return !started; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            started = true;
            locker.unlock();
            cond.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> locker(mu, std::defer_lock);
        for (int i = 0; i < n; i++) {
            locker.lock();
            cond.wait(locker, [this]()->bool { return started; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            started = false;
            locker.unlock();
            cond.notify_one();
        }
    }
};

void t_foo(FooBar& obj) {
    obj.foo([]() { cout << "foo"; });
}

void t_bar(FooBar& obj) {
    obj.bar([]() { cout << "bar"; });
}

int main() {
    FooBar obj(4);
    std::thread t1(t_foo, std::ref(obj));
    std::thread t2(t_bar, std::ref(obj));
    t1.join();
    t2.join();
    return 0;
}

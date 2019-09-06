/**
 * Suppose you are given the following code:
 * class ZeroEvenOdd {
 *   public ZeroEvenOdd(int n) { ... }      // constructor
 *   public void zero(printNumber) { ... }  // only output 0's
 *   public void even(printNumber) { ... }  // only output even numbers
 *   public void odd(printNumber) { ... }   // only output odd numbers
 * }
 * The same instance of ZeroEvenOdd will be passed to three different threads:
 * Thread A will call zero() which should only output 0's.
 * Thread B will call even() which should only ouput even numbers.
 * Thread C will call odd() which should only output odd numbers.
 * Each of the threads is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.
 * Example 1:
 * Input: n = 2
 * Output: "0102"
 * Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
 * Example 2:
 * Input: n = 5
 * Output: "0102030405"
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

class ZeroEvenOdd {
  private:
    int n;
    std::mutex mu_zero_;
    std::mutex mu_odd_;
    std::mutex mu_even_;

  public:
    ZeroEvenOdd(int n) {
        this->n = n;
        mu_odd_.lock();
        mu_even_.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            mu_zero_.lock();
            printNumber(0);
            if (i % 2 == 0) {
                mu_odd_.unlock();
            } else {
                mu_even_.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            mu_even_.lock();
            printNumber(i);
            mu_zero_.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            mu_odd_.lock();
            printNumber(i);
            mu_zero_.unlock();
        }
    }
};

auto printNumber = [](int x)->void {
    cout << x;
};

void f1(ZeroEvenOdd& obj) {
    obj.zero(printNumber);
}

void f2(ZeroEvenOdd& obj) {
    obj.even(printNumber);
}

void f3(ZeroEvenOdd& obj) {
    obj.odd(printNumber);
}

int main() {
    ZeroEvenOdd obj(5);
    std::thread t1(f1, std::ref(obj));
    std::thread t2(f2, std::ref(obj));
    std::thread t3(f3, std::ref(obj));
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

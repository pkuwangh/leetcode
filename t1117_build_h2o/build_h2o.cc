/**
 * There are two kinds of threads, oxygen and hydrogen.
 * Your goal is to group these threads to form water molecules.
 * There is a barrier where each thread has to wait until a complete molecule can be formed.
 * Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively,
 * which will allow them to pass the barrier.
 * These threads should pass the barrier in groups of three,
 * and they must be able to immediately bond with each other to form a water molecule.
 * You must guarantee that all the threads from one molecule bond before any other threads
 * from the next molecule do.
 * In other words:
 * If an oxygen thread arrives at the barrier when no hydrogen threads are present,
 * it has to wait for two hydrogen threads.
 * If a hydrogen thread arrives at the barrier when no other threads are present,
 * it has to wait for an oxygen thread and another hydrogen thread.
 * We don’t have to worry about matching the threads up explicitly;
 * that is, the threads do not necessarily know which other threads they are paired up with.
 * The key is just that threads pass the barrier in complete sets;
 * thus, if we examine the sequence of threads that bond and divide them into groups of three,
 * each group should contain one oxygen and two hydrogen threads.
 * Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.
 * Example 1:
 * Input: "HOH"
 * Output: "HHO"
 * Explanation: "HOH" and "OHH" are also valid answers.
 * Example 2:
 * Input: "OOHHHH"
 * Output: "HHOHHO"
 * Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH"
 * and "OHHOHH" are also valid answers.
 * Constraints:
 * Total length of input string will be 3n, where 1 ≤ n ≤ 20.
 * Total number of H will be 2n in the input string.
 * Total number of O will be n in the input string.
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
#include <string>
using namespace std;

class H2O {
  private:
    int32_t h_count_;
    int32_t o_count_;
    std::mutex h_mu_;
    std::mutex o_mu_;
    std::condition_variable h_cond_;
    std::condition_variable o_cond_;

  public:
    H2O() {
        h_count_ = 0;
        o_count_ = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> locker(h_mu_);
        h_cond_.wait(locker, [this]()->bool { return h_count_ < 2; });
        h_count_ += 1;
        locker.unlock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        o_mu_.lock();
        o_count_ -= 1;
        o_mu_.unlock();
        o_cond_.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> locker(o_mu_);
        o_cond_.wait(locker, [this]()->bool { return o_count_ <= 0; });
        o_count_ += 2;
        locker.unlock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        h_mu_.lock();
        h_count_ -= 2;
        h_mu_.unlock();
        h_cond_.notify_one();
    }
};

void process_h(H2O& obj) {
    obj.hydrogen([]()->void { cout << "H"; });
}

void process_o(H2O& obj) {
    obj.oxygen([]()->void { cout << "O"; });
}

int main() {
    auto run = [&](string input) ->void {
        H2O obj;
        std::vector<std::thread> threads;
        for (const auto& c : input) {
            if (c == 'H') {
                threads.emplace_back(process_h, ref(obj));
            } else {
                threads.emplace_back(process_o, ref(obj));
            }
        }
        for (uint32_t i = 0; i < threads.size(); ++i) {
            threads[i].join();
        }
        cout << endl;
    };
    run("OOHHHH");
    return 0;
}

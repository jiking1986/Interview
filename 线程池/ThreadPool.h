#pragma once

#include <queue>
#include <vector>

#include <thread>
#include <atomic>
#include <mutex>

class CThreadPool
{
public:
    CThreadPool() {
    
    }
    ~CThreadPool() {

    }

public:
    int AddTask() {

    }

    int run() {

    }
    int stop() {

    }

private:
    std::queue<int> m_taskList;
    std::vector<std::thread> m_threadList;
};

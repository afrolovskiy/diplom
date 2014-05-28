void foo1() {
    if (threadsafe) Mu.lock();
    ...
    if (threadsafe) Mu.unlock();
} 

void foo2() {
    for (int i = 0; i < 10; ++i) MutexArray[i].lock();
    ... 
    for (int i = 0; i < 10; ++i) MutexArray[i].unlock();
}
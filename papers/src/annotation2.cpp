Mutex CacheMutex;
Cache GlobalCache GUARDED_BY(CacheMutex);

class ScopedLookup {
public: 
  ScopedLookup(Key* K) EXCLUSIVE_LOCKS_REQUIRED(CacheMutex)
    : Ky(K), Val(GlobalCache.lookup(K))
  { }
  ~ScopedLookup() EXCLUSIVE_LOCKS_REQUIRED(CacheMutex) {
    GlobalCache.release(Ky); 
  }
  ...
};
int x ; mutex m1 = MUTEX_INIT;
int y, z; mutex m2 = MUTEX_INIT;

void munge(int *v, mutex *m) {
    lock (m); (*v)++; unlock (m);
}

thread t1 () {
    munge (&x, &m1);
    munge (&y, &m2);
    munge (&z, &m2);
}

thread t2 () {
    munge (&x, &m1);
    munge (&y, &m1);
    munge (&z, &m2);
}
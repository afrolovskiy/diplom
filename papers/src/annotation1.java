class Account {
	final Object lock = new Object();
	
	/*# guarded_by lock */
	int balance = 0;
	
	/*# requires lock */
	void update(int n) {
		balance = n;
	}
	
	void deposit(int x) {
		synchronized(lock) {
			update(balance + x);
		}
	}
}
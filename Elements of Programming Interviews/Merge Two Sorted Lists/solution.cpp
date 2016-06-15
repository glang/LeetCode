shared_ptr<ListNode<T>> merge(shared_ptr<ListNode<T>> A, shared_ptr<ListNode<T>> B) {
	auto A_iter = A, B_iter = B;

	while (A_iter && B_iter) {
		if (A_iter->data <= B_iter) {
			auto attach = A_iter;
			A_iter = A_iter->next;
			attach->next = B_iter;
		} else {
			auto attach = B_iter;
			B_iter = B_iter->next;
			attach->next = A_iter;		
		}
	}

	return A->data <= B->data ? A : B;
} 